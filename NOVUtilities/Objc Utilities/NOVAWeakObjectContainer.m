//
//  NOVAWeakObjectContainer.m
//  NOVAUtilities
//
//  Created by shupeng on 2019/7/26.
//

#import "NOVAWeakObjectContainer.h"

@implementation NOVAWeakObjectContainer

- (instancetype)initWithObject:(id)object {
    if (self = [super init]) {
        _object = object;
    }
    return self;
}
@end
