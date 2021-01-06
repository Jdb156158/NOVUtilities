//
//  NSFileManager+NOVAUtilities.h
//  NOVAUtilities
//
//  Created by shupeng on 2019/5/22.
//  Copyright © 2019 shupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 程序目录，不能存任何东西
static inline NSString* AppPath(void);

// 文档目录，需要ITUNES同步备份的数据存这里
static inline NSString* DocPath(void);

// 配置目录，配置文件存这里
static inline NSString* LibPrefPath(void);

// 缓存目录，系统永远不会删除这里的文件，ITUNES会删除
static inline NSString* LibCachePath(void);

// 缓存目录，APP退出后，系统可能会删除这里的内容
static inline NSString* TmpPath(void);

// 创建目录
static inline NSString* TouchPath(NSString *path);


#pragma mark -

static inline NSString* AppPath()
{
    NSArray * paths = NSSearchPathForDirectoriesInDomains(NSApplicationDirectory, NSUserDomainMask, YES);
    return [paths objectAtIndex:0];
}

static inline NSString* DocPath()
{
    NSArray * paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    return [paths objectAtIndex:0];
}

static inline NSString* LibPrefPath()
{
    NSArray * paths = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES);
    return [[paths objectAtIndex:0] stringByAppendingFormat:@"/Preferences"];
}

static inline NSString* LibCachePath()
{
    NSArray * paths = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES);
    return [[paths objectAtIndex:0] stringByAppendingFormat:@"/Caches"];
}

static inline NSString* TmpPath()
{
    NSArray * paths = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES);
    return [[paths objectAtIndex:0] stringByAppendingFormat:@"/tmp"];
}

static inline NSString* TouchPath(NSString *path)
{
    if ( NO == [[NSFileManager defaultManager] fileExistsAtPath:path] )
    {
        [[NSFileManager defaultManager] createDirectoryAtPath:path
                                  withIntermediateDirectories:YES
                                                   attributes:nil
                                                        error:NULL];
    }
    return path;
}

@interface NSFileManager (NOVAUtilities)

@end

NS_ASSUME_NONNULL_END
