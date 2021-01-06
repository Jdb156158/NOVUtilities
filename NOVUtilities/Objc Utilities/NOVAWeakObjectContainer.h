//
//  NOVAWeakObjectContainer.h
//  NOVAUtilities
//
//  Created by shupeng on 2019/7/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 通过oc运行时给对象动态添加的对象。 如果是weak类型。 当该对象释放时， 对象的运行时添加的这个变量不会自动置为nil。 通过一个wrapper来包裹这个weak对象可以解决这个问题
 其解决思想是， 利用weak属性的自动置nil来解决。
 */
@interface NOVAWeakObjectContainer : NSObject

/// 将一个 object 包装到一个 NOVAWeakObjectContainer 里
- (instancetype)initWithObject:(id)object;

/// 获取原始对象 object，如果 object 已被释放则该属性返回 nil
@property (nonatomic, weak) id object;
@end

NS_ASSUME_NONNULL_END
