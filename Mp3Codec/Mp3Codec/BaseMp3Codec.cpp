//
//  BaseMp3Codec.cpp
//  Mp3Codec
//
//  Created by Jingfu Li on 2021/12/20.
//

#include <assert.h>
#include "BaseMp3Codec.hpp"

int BaseMp3Codec::Init(const char *pcmFilePath,
                   const char *mp3FilePath,
                   long sampleRate,
                   long channels,
                   long bitRate)
{
    this->pcmFilePath = (char *)pcmFilePath;
    this->mp3FilePath = (char *)mp3FilePath;

    this->sampleRate = sampleRate;
    this->channels = channels;
    this->bitRate = bitRate;

    pcmFile = fopen(pcmFilePath, "rwb+");
    mp3File = fopen(mp3FilePath, "rwb+");

    // config lame
    lameClient = lame_init();
    lame_set_in_samplerate(lameClient, (int)sampleRate);
    lame_set_out_samplerate(lameClient, (int)sampleRate);
    lame_set_num_channels(lameClient, (int)channels);
    lame_set_brate(lameClient, (int)bitRate);
    lame_set_quality(lameClient, 2); // 转码质量
    lame_init_params(lameClient);

    return !pcmFile || !mp3File ? -1 : 0;
}

BaseMp3Codec::~BaseMp3Codec()
{
    lame_close(lameClient);
}

int BaseMp3Codec::encode()
{
    // 目前只支持双声道
    assert(channels == 2);
    //assert(bitRate == 16 * 1024);

    // 跳过 pcm header，否则有噪音在 mp3 处播放
    fseek(pcmFile, 4 * 1024, SEEK_CUR);

    int bufferSize = 256 * 1024;
    // 左右声道
    short *buffer = new short[bufferSize/2];
    short *leftBuffer = new short[bufferSize/4];
    short *rightBuffer = new short[bufferSize/4];
    unsigned char *mp3Buffer = new unsigned char[bufferSize];

    size_t readBufferSize = 0;
    // 双声道获取比特率的数据
    while ((readBufferSize = fread(buffer, 2, bufferSize / 2, pcmFile)) > 0) {
        for (int i = 0; i < readBufferSize; i++) {
            if (i % 2 == 0) {
                leftBuffer[i/2] = buffer[i];
            } else {
                rightBuffer[i/2] = buffer[i];
            }

            // TODO: nsamples 参数应该为 readBufferSize？
            size_t writeBufferSize = lame_encode_buffer(lameClient,
                                                        (short int *)leftBuffer,
                                                        (short int *)rightBuffer,
                                                        (int)(readBufferSize / 2),
                                                        mp3Buffer,
                                                        bufferSize);

            fwrite(mp3Buffer, 1, writeBufferSize, mp3File);
        }
    };

    // Mp3 VBR Tag，不是必须。不写可能会导致某些播放器播放时获取时长出现问题。
    lame_mp3_tags_fid(lameClient, mp3File);

    delete [] buffer;
    delete [] leftBuffer;
    delete [] rightBuffer;
    delete [] mp3Buffer;

    int ret = 0;
    return ret;
}

int BaseMp3Codec::decode()
{
    int ret = 0;
    return ret;
}
