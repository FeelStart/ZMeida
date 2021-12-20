//
//  Mp3CodecProtocol.h
//  Mp3Codec
//
//  Created by Jingfu Li on 2021/12/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol Mp3CodecProtocol <NSObject>

/**
 * 将 pcm 数据转换成为 mp3 数据
 * @param pcmFilePath pcm文件
 * @param mp3FilePath mp3文件
 * @param sampleRate 采样率
 * @param channels 通道数
 * @param bitRate 码率
 * @return 成功返回 YES
 */
- (BOOL)encodeWithPcmFilePath:(NSString *)pcmFilePath
                  mp3FilePath:(NSString *)mp3FilePath
                   sampleRate:(NSUInteger)sampleRate
                     channels:(NSUInteger)channels
                      bitRate:(NSUInteger)bitRate;

/**
 * 将 mp3 数据转换成为 pcm 数据
 * @param pcmFilePath pcm文件
 * @param mp3FilePath mp3文件
 * @param sampleRate 采样率
 * @param channels 通道数
 * @param bitRate 码率
 * @return 成功返回 YES
 */
- (BOOL)decodeWithPcmFilePath:(NSString *)pcmFilePath
                  mp3FilePath:(NSString *)mp3FilePath
                   sampleRate:(NSUInteger)sampleRate
                     channels:(NSUInteger)channels
                      bitRate:(NSUInteger)bitRate;

@end

NS_ASSUME_NONNULL_END
