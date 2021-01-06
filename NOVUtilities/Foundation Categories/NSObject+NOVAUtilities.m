//
//  NSObject+NOVAUtilities.m
//  NOVAUtilities
//
//  Created by shupeng on 2019/5/22.
//  Copyright © 2019 shupeng. All rights reserved.
//

#import "NSObject+NOVAUtilities.h"
#import "objc/runtime.h"

@implementation NSObject (NOVAUtilities)
- (void)setAssociateValue:(id)value withKey:(void *)key {
    objc_setAssociatedObject(self, key, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)setAssociateWeakValue:(id)value withKey:(void *)key {
    objc_setAssociatedObject(self, key, value, OBJC_ASSOCIATION_ASSIGN);
}

- (void)removeAssociatedValues {
    objc_removeAssociatedObjects(self);
}

- (id)getAssociatedValueForKey:(void *)key {
    return objc_getAssociatedObject(self, key);
}

+ (NSString *)className {
    return NSStringFromClass(self);
}

- (NSString *)className {
    return [NSString stringWithUTF8String:class_getName([self class])];
}

- (id)deepCopy {
    id obj = nil;
    @try {
        obj = [NSKeyedUnarchiver unarchiveObjectWithData:[NSKeyedArchiver archivedDataWithRootObject:self]];
    }
    @catch (NSException *exception) {
        NSLog(@"%@", exception);
    }
    return obj;
}

- (id)deepCopyWithArchiver:(Class)archiver unarchiver:(Class)unarchiver {
    id obj = nil;
    @try {
        obj = [unarchiver unarchiveObjectWithData:[archiver archivedDataWithRootObject:self]];
    }
    @catch (NSException *exception) {
        NSLog(@"%@", exception);
    }
    return obj;
}

#pragma mark - runtime
+ (NSArray *)propertyList
{
    NSMutableArray *list = [[NSMutableArray alloc] init];
    unsigned int propertyCount, i;
    objc_property_t *propertList = class_copyPropertyList(self, &propertyCount);
    for(i = 0; i < propertyCount; i++) {
        objc_property_t property = propertList[i];
        const char *propName = property_getName(property);
        if(propName) {
            NSString *propertyName = [NSString stringWithCString:propName encoding:NSUTF8StringEncoding];
            [list addObject:propertyName];
        }
    }
    free(propertList);
    
    return list ;
}

+ (NSArray *)subclasses
{
    int numClasses = objc_getClassList(NULL, 0);
    Class *classes = NULL;
    
    classes = (Class *)malloc(sizeof(Class) * numClasses);
    numClasses = objc_getClassList(classes, numClasses);
    
    NSMutableArray *result = [NSMutableArray array];
    for (NSInteger i = 0; i < numClasses; i++)
    {
        Class superClass = classes[i];
        do
        {
            superClass = class_getSuperclass(superClass);
        } while(superClass && superClass != self);
        
        if (superClass == nil)
        {
            continue;
        }
        
        [result addObject:classes[i]];
    }
    
    free(classes);
    
    return [NSArray arrayWithArray:result];
}

+ (NSBundle *)selfBundle {
    return [NSBundle bundleForClass:self];
}

- (NSBundle *)selfBundle {
    return [NSBundle bundleForClass:[self class]];
}
@end
