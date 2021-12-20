//
//  Mp3Codec-Public.m
//  Mp3Codec
//
//  Created by Jingfu Li on 2021/12/20.
//

#import "Mp3Codec-Public.h"
#import "BaseMp3Codec.hpp"

@implementation Mp3Codec
{
    BaseMp3Codec _codec;
}

#pragma mark - Initialization

- (instancetype)init
{
    self = [super init];
    if (self) {
        [self commonInit];
    }

    return self;
}

- (void)commonInit
{
    _codec = BaseMp3Codec();
}

#pragma mark - Mp3CodecProtocol

- (BOOL)encodeWithPcmFilePath:(NSString *)pcmFilePath
                  mp3FilePath:(NSString *)mp3FilePath
                   sampleRate:(NSUInteger)sampleRate
                     channels:(NSUInteger)channels
                      bitRate:(NSUInteger)bitRate
{
    _codec.Init(pcmFilePath.UTF8String,
                mp3FilePath.UTF8String,
                (long)sampleRate,
                (long)channels,
                (long)bitRate);

    return _codec.encode() == 0;
}

- (BOOL)decodeWithPcmFilePath:(NSString *)pcmFilePath
                  mp3FilePath:(NSString *)mp3FilePath
                   sampleRate:(NSUInteger)sampleRate
                     channels:(NSUInteger)channels
                      bitRate:(NSUInteger)bitRate
{
    _codec.Init(pcmFilePath.UTF8String,
                mp3FilePath.UTF8String,
                (long)sampleRate,
                (long)channels,
                (long)bitRate);

    return _codec.decode() == 0;
}

@end
