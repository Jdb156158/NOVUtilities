//
//  NOVAUtilities.h
//  NOVAUtilities
//
//  Created by 舒鹏 on 2019/9/26.
//  Copyright © 2019 舒鹏. All rights reserved.
//

#ifndef NOVAUtilities_h
#define NOVAUtilities_h

// objc 运行时 相关的辅助类
#import "weakify.h"
#import "AssociatedObject.h"
#import "NOVAWeakObjectContainer.h"
#import "NSObject+Swizzle.h"

// 针对系统基础数据类型的扩展
#import "NSObject+NOVAUtilities.h"
#import "NSArray+NOVAUtilities.h"
#import "NSData+NOVAUtilities.h"
#import "NSDictionary+NOVAUtilities.h"
#import "NSDate+NOVAUtilities.h"
#import "NSFileManager+NOVAUtilities.h"
#import "NSString+NOVAUtilities.h"
#import "NSNumber+NOVAUtilities.h"

// 常用定义 以及 很多的工具
// 此分组会依赖上面的基础数据类型扩展
#import "NOVADefines.h"
#import "NOVAHelper.h"
#import "NOVAMISC.h"
#import "NOVADevice.h"

// YYKit相关工具
#import "YYAsyncLayer.h"
#import "YYDispatchQueuePool.h"
#import "YYFileHash.h"
#import "YYGestureRecognizer.h"
#import "YYKeychain.h"
#import "YYReachability.h"
#import "YYSentinel.h"
#import "YYThreadSafeArray.h"
#import "YYThreadSafeDictionary.h"
#import "YYTimer.h"
#import "YYTransaction.h"
#import "YYWeakProxy.h"

#endif /* NOVAUtilities_h */
