//
//  AssociatedObject.h
//  NOVAUtilities
//
//  Created by shupeng on 2019/5/8.
//  Copyright © 2019 shupeng. All rights reserved.
//

#ifndef AssociatedObject_h
#define AssociatedObject_h

#import <objc/runtime.h>

/**
 动态创建对象类型属性
 通过动态创建类型属性, 并添加getter和setter方法
 
 @param _getter_ <#_getter_ description#>
 @param _setter_ <#_setter_ description#>
 @param _association_ <#_association_ description#>
 @param _type_ <#_type_ description#>
 @return <#return value description#>
 */
#ifndef DYNAMIC_OBJECT_PROPERTY
#define DYNAMIC_OBJECT_PROPERTY(_getter_, _setter_, _association_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
objc_setAssociatedObject(self, _cmd, object, OBJC_ASSOCIATION_ ## _association_); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
return objc_getAssociatedObject(self, @selector(_setter_:)); \
}
#endif


/**
 动态创建值类型属性
 通过动态创建值类型属性, 并添加getter和setter方法
 
 @param _getter_ <#_getter_ description#>
 @param _setter_ <#_setter_ description#>
 @param _type_ <#_type_ description#>
 @return <#return value description#>
 */
#ifndef DYNAMIC_CTYPE_PROPERTY
#define DYNAMIC_CTYPE_PROPERTY(_getter_, _setter_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
NSValue *value = [NSValue value:&object withObjCType:@encode(_type_)]; \
objc_setAssociatedObject(self, _cmd, value, OBJC_ASSOCIATION_RETAIN); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
_type_ cValue = { 0 }; \
NSValue *value = objc_getAssociatedObject(self, @selector(_setter_:)); \
[value getValue:&cValue]; \
return cValue; \
}
#endif

#endif /* AssociatedObject_h */
