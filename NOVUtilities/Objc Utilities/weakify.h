//
//  weakify.h
//  NOVAUtilities
//
//  Created by shupeng on 2019/5/8.
//  Copyright © 2019 shupeng. All rights reserved.
//

#ifndef weakify_h
#define weakify_h


/**
 使用方法:
 @weakify(self)
 someblock {
    @strongify(self)
 }
 */
#ifndef weakify
#if DEBUG
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#endif
#endif

#ifndef strongify
#if DEBUG
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#endif
#endif

#endif /* weakify_h */
