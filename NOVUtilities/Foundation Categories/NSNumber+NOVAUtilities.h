//
//  NSNumber+NOVAUtilities.h
//  NOVAUtilities
//
//  Created by shupeng on 2019/5/22.
//  Copyright © 2019 shupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSNumber (NOVAUtilities)
/**
 Creates and returns an NSNumber object from a string.
 Valid format: @"12", @"12.345", @" -0xFF", @" .23e99 "...
 
 @param string  The string described an number.
 
 @return an NSNumber when parse succeed, or nil if an error occurs.
 */
+ (NSNumber *)numberWithString:(NSString *)string;
@end

NS_ASSUME_NONNULL_END
