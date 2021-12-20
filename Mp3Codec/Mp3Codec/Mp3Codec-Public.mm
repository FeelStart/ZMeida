//
//  Mp3Codec-Public.m
//  Mp3Codec
//
//  Created by Jingfu Li on 2021/12/20.
//

#import "Mp3Codec-Public.h"
#import <lame/lame.h>

@implementation Mp3Codec_Public

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
    lame_init();
}

@end
