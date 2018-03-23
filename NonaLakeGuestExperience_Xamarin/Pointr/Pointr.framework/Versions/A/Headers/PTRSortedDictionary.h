//
//  PTRSortedDictionary.h
//  Pointr
//
//  Created by Erkan Sen on 7.11.2017.
//
//  Sorted dictionary object
//  Keeps objects in adding order and gives them back in the same order
//  Objects can be retrieved both using object for key or object at index
//

#import "Foundation/Foundation.h"

@interface PTRSortedDictionary <__covariant keyType : NSString *, __covariant valueType>: NSObject
NS_ASSUME_NONNULL_BEGIN
/**
 *  Initialises with objects from given dictionary
 *  @warn Sorting will be arbitrary
 */
- (instancetype)initWithDictionary:(NSDictionary<keyType,valueType>*)dictionary;

/**
 *  Returns object for given key (if found)
 */
- (nullable valueType)objectForKey:(keyType)key;

/**
 *  Remove object for given key (if found)
 */
- (void)removeObjectForKey:(keyType)key;

/**
 *  Sets object for given key
 *  Overwrites previous object if key already in use
 */
- (void)setObject:(valueType)object forKey:(keyType)key;

/**
 *  Returns all keys, in insertion order
 */
- (NSArray<keyType> *)allKeys;

/**
 *  Returns all values, in insertion order
 */
- (NSArray<valueType> *)allValues;

/////////////////////////////////////////////////////////////////////////
#pragma mark - NSArray methods
/////////////////////////////////////////////////////////////////////////

/**
 *  Returns object at given index (if any)
 */
- (valueType)objectAtIndex:(NSUInteger)index;

/**
 *  Removes object at given index (if any)
 */
- (void)removeObjectAtIndex:(NSUInteger)index;

/**
 *  Returns count of keys
 */
- (NSUInteger)count;

/**
 *  Sorts keys using given selector
 */
- (void)sortUsingSelector:(SEL)selector;

NS_ASSUME_NONNULL_END
@end
