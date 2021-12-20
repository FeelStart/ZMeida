//
//  BaseMp3Codec.hpp
//  Mp3Codec
//
//  Created by Jingfu Li on 2021/12/20.
//

#ifndef BaseMp3Codec_hpp
#define BaseMp3Codec_hpp

#include <stdio.h>
#include <lame/lame.h>

class BaseMp3Codec {
private:
    /// pcm 音频裸数据文件
    char *pcmFilePath;
    /// mp3 数据文件
    char *mp3FilePath;

    FILE *pcmFile;
    FILE *mp3File;

    /// 采样率
    long sampleRate;
    /// 通道数
    long channels;
    /// 码率
    long bitRate;

    lame_t lameClient;

public:

    /**
     * 初始化
     * @param pcmFilePath pcm文件
     * @param mp3FilePath mp3文件
     * @param sampleRate 采样率
     * @param channels 通道数
     * @param bitRate 码率
     * @return 返回 0 表示成功，否则失败
     */
    int Init(const char *pcmFilePath,
             const char *mp3FilePath,
             long sampleRate,
             long channels,
             long bitRate
         );

    ~BaseMp3Codec();

    /// 将 pcm 数据转换成为 mp3
    int encode();

    /// 将 mp3 数据转换成为 pcm
    int decode();
};

#endif /* Mp3Codec_hpp */
