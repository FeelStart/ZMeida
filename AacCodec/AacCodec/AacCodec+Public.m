//
//  AacCodec+Public.m
//  AacCodec
//
//  Created by Jingfu Li on 2021/12/21.
//

#import "AacCodec+Public.h"
#import <fdk-aac/aacenc_lib.h>
#import <fdk-aac/FDK_audio.h>

@implementation AacCodec

#pragma mark - Init

- (instancetype)init {
    self = [super init];
    if (self) {
        [self commonInit];
    }

    return self;
}

- (void)commonInit {
}

@end
