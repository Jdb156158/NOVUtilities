//
//  NSDictionary+NOVAUtilities.h
//  NOVAUtilities
//
//  Created by shupeng on 2019/5/22.
//  Copyright © 2019 shupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (NOVAUtilities)
#pragma mark - Dictionary Value Getter

/**
 Creates and returns a dictionary from a specified property list data.
 
 @param plist   A property list data whose root object is a dictionary.
 @return A new dictionary created from the binary plist data, or nil if an error occurs.
 */
+ (nullable NSDictionary *)dictionaryWithPlistData:(NSData *)plist;

/**
 Creates and returns a dictionary from a specified property list xml string.
 
 @param plist   A property list xml string whose root object is a dictionary.
 @return A new dictionary created from the plist string, or nil if an error occurs.
 
 @discussion Apple has implemented this method, but did not make it public.
 */
+ (nullable NSDictionary *)dictionaryWithPlistString:(NSString *)plist;

/**
 Serialize the dictionary to a binary property list data.
 
 @return A binary plist data, or nil if an error occurs.
 
 @discussion Apple has implemented this method, but did not make it public.
 */
- (nullable NSData *)plistData;

/**
 Returns a new array containing the dictionary's keys sorted.
 The keys should be NSString, and they will be sorted ascending.
 
 @return A new array containing the dictionary's keys,
 or an empty array if the dictionary has no entries.
 */
- (NSArray *)allKeysSorted;

/**
 Returns a new array containing the dictionary's values sorted by keys.
 
 The order of the values in the array is defined by keys.
 The keys should be NSString, and they will be sorted ascending.
 
 @return A new array containing the dictionary's values sorted by keys,
 or an empty array if the dictionary has no entries.
 */
- (NSArray *)allValuesSortedByKeys;

/**
 Returns a BOOL value tells if the dictionary has an object for key.
 
 @param key The key.
 */
- (BOOL)containsObjectForKey:(id)key;

/**
 Returns a new dictionary containing the entries for keys.
 If the keys is empty or nil, it just returns an empty dictionary.
 
 @param keys The keys.
 @return The entries for the keys.
 */
- (NSDictionary *)entriesForKeys:(NSArray *)keys;

/**
 Convert dictionary to json string. return nil if an error occurs.
 */
- (nullable NSString *)jsonStringEncoded;

/**
 Convert dictionary to json string formatted. return nil if an error occurs.
 */
- (nullable NSString *)jsonPrettyStringEncoded;

- (BOOL)boolValueForKey:(NSString *)key defaultValue:(BOOL)def;

- (char)charValueForKey:(NSString *)key defaultValue:(char)def;

- (unsigned char)unsignedCharValueForKey:(NSString *)key defaultValue:(unsigned char)def;

- (short)shortValueForKey:(NSString *)key defaultValue:(short)def;

- (unsigned short)unsignedShortValueForKey:(NSString *)key defaultValue:(unsigned short)def;

- (int)intValueForKey:(NSString *)key defaultValue:(int)def;

- (unsigned int)unsignedIntValueForKey:(NSString *)key defaultValue:(unsigned int)def;

- (long)longValueForKey:(NSString *)key defaultValue:(long)def;

- (unsigned long)unsignedLongValueForKey:(NSString *)key defaultValue:(unsigned long)def;

- (long long)longLongValueForKey:(NSString *)key defaultValue:(long long)def;

- (unsigned long long)unsignedLongLongValueForKey:(NSString *)key defaultValue:(unsigned long long)def;

- (float)floatValueForKey:(NSString *)key defaultValue:(float)def;

- (double)doubleValueForKey:(NSString *)key defaultValue:(double)def;

- (NSInteger)integerValueForKey:(NSString *)key defaultValue:(NSInteger)def;

- (NSUInteger)unsignedIntegerValueForKey:(NSString *)key defaultValue:(NSUInteger)def;

- (NSNumber *)numverValueForKey:(NSString *)key defaultValue:(NSNumber *)def;

- (NSString *)stringValueForKey:(NSString *)key defaultValue:(NSString *)def;

- (NSDictionary *)appendDictionary:(NSDictionary *)dic;
@end

/**
 Provide some some common method for `NSMutableDictionary`.
 */
@interface NSMutableDictionary (NOVAUtilities)

/**
 Creates and returns a dictionary from a specified property list data.
 
 @param plist   A property list data whose root object is a dictionary.
 @return A new dictionary created from the binary plist data, or nil if an error occurs.
 
 @discussion Apple has implemented this method, but did not make it public.
 */
+ (nullable NSMutableDictionary *)dictionaryWithPlistData:(NSData *)plist;

/**
 Creates and returns a dictionary from a specified property list xml string.
 
 @param plist   A property list xml string whose root object is a dictionary.
 @return A new dictionary created from the plist string, or nil if an error occurs.
 */
+ (nullable NSMutableDictionary *)dictionaryWithPlistString:(NSString *)plist;


/**
 Removes and returns the value associated with a given key.
 
 @param aKey The key for which to return and remove the corresponding value.
 @return The value associated with aKey, or nil if no value is associated with aKey.
 */
- (nullable id)popObjectForKey:(id)aKey;

/**
 Returns a new dictionary containing the entries for keys, and remove these
 entries from receiver. If the keys is empty or nil, it just returns an
 empty dictionary.
 
 @param keys The keys.
 @return The entries for the keys.
 */
- (NSDictionary *)popEntriesForKeys:(NSArray *)keys;

@end

NS_ASSUME_NONNULL_END
