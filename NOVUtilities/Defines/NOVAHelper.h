//
//  NOVAHelper.h
//  NOVAUtilities
//
//  Created by shupeng on 2019/7/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NOVAHelper : NSObject

@end


@interface NOVAHelper (Locale)
/**
 获取用户手机的本地化列表
 
 @return 示例: "en-US" "zh-Hans-CN"
 */
+ (NSString *)preferredSystemLocale;

/**
 获取当前应用的本地化列表
 
 @return 示例: "en-US" "zh-Hans-CN"
 */
+ (NSString *)preferredBundleLocale;

/**
 获取系统的本地化字典
 
 iSO 标准:
 ISO 639-1 codes
 https://en.wikipedia.org/wiki/List_of_ISO_639-1_codes
 
 完整的代号
 http://www.iana.org/assignments/language-subtag-registry/language-subtag-registry
 
 keys
 kCFLocaleCountryCodeKey = CN;
 kCFLocaleLanguageCodeKey = zh;
 kCFLocaleScriptCodeKey = Hans;
 
 @param localeString 本地化字符串
 @return  经过转换后的字典
 */
+ (NSDictionary *)preferredLocaleDicFromLocaleString:(NSString *)localeString;

@end

@interface NOVAHelper (SystemVersion)
+ (NSInteger)numbericOSVersion;
+ (NSComparisonResult)compareSystemVersion:(nonnull NSString *)currentVersion toVersion:(nonnull NSString *)targetVersion;
+ (BOOL)isCurrentSystemAtLeastVersion:(nonnull NSString *)targetVersion;
+ (BOOL)isCurrentSystemLowerThanVersion:(nonnull NSString *)targetVersion;
@end


@interface NOVAHelper (DynamicType)

/// 返回当前 contentSize 的 level，这个值可以在设置里面的“字体大小”查看，辅助功能里面有个“更大字体”可以设置更大的字体，不过这里我们这个接口将更大字体都做了统一，都返回“字体大小”里面最大值。
/// Returns the level of contentSize
/// The value can be set in Settings - Display & Brightness - Text Size as well as in General - Accessibility - Larger Text
/// This method returns the value set by user or the maximum value in Text Size, whichever is smaller
+ (nonnull NSNumber *)preferredContentSizeLevel;

/// 设置当前 cell 的高度，heights 是有七个数值的数组，对于不支持的iOS版本，则选择中间的值返回。
/// Sets height of the cell; Heights consist of 7 numberic values; Returns the middle value on legacy iOS versions.
+ (CGFloat)heightForDynamicTypeCell:(nonnull NSArray *)heights;
@end


@interface NOVAHelper (Device)

+ (nonnull NSString *)deviceModel;

+ (BOOL)isIPad;
+ (BOOL)isIPod;
+ (BOOL)isIPhone;
+ (BOOL)isSimulator;

/// 带物理凹槽的刘海屏或者使用 Home Indicator 类型的设备
+ (BOOL)isNotchedScreen;

/// 将屏幕分为普通和紧凑两种，这个方法用于判断普通屏幕
+ (BOOL)isRegularScreen;

/// iPhone XS Max
+ (BOOL)is65InchScreen;

/// iPhone XR
+ (BOOL)is61InchScreen;

/// iPhone X/XS
+ (BOOL)is58InchScreen;

/// iPhone 8 Plus
+ (BOOL)is55InchScreen;

/// iPhone 8
+ (BOOL)is47InchScreen;

/// iPhone 5
+ (BOOL)is40InchScreen;

/// iPhone 4
+ (BOOL)is35InchScreen;

+ (CGSize)screenSizeFor65Inch;
+ (CGSize)screenSizeFor61Inch;
+ (CGSize)screenSizeFor58Inch;
+ (CGSize)screenSizeFor55Inch;
+ (CGSize)screenSizeFor47Inch;
+ (CGSize)screenSizeFor40Inch;
+ (CGSize)screenSizeFor35Inch;

+ (CGFloat)preferredLayoutAsSimilarScreenWidthForIPad;

// 用于获取 isNotchedScreen 设备的 insets，注意对于 iPad Pro 11-inch 这种无刘海凹槽但却有使用 Home Indicator 的设备，它的 top 返回0，bottom 返回 safeAreaInsets.bottom 的值
+ (UIEdgeInsets)safeAreaInsetsForDeviceWithNotch;

/// 判断当前设备是否高性能设备，只会判断一次，以后都直接读取结果，所以没有性能问题
+ (BOOL)isHighPerformanceDevice;

/// 系统设置里是否开启了“放大显示-试图-放大”，支持放大模式的 iPhone 设备可在官方文档中查询 https://support.apple.com/zh-cn/guide/iphone/iphd6804774e/ios
+ (BOOL)isZoomedMode;

/**
 在 iPad 分屏模式下可获得实际运行区域的窗口大小，如需适配 iPad 分屏，建议用这个方法来代替 [UIScreen mainScreen].bounds.size
 @return 应用运行的窗口大小
 */
+ (CGSize)applicationSize;

@end

@interface NOVAHelper (UIApplication)

/**
 *  更改状态栏内容颜色为深色
 *
 *  @warning 需在项目的 Info.plist 文件内设置字段 “View controller-based status bar appearance” 的值为 NO 才能生效，如果不设置，或者值为 YES，则请通过系统的 - UIViewController preferredStatusBarStyle 方法来修改
 */
+ (void)renderStatusBarStyleDark DEPRECATED_ATTRIBUTE;

/**
 *  更改状态栏内容颜色为浅色
 *
 *  @warning 需在项目的 Info.plist 文件内设置字段 “View controller-based status bar appearance” 的值为 NO 才能生效，如果不设置，或者值为 YES，则请通过系统的 - UIViewController preferredStatusBarStyle 方法来修改
 */
+ (void)renderStatusBarStyleLight DEPRECATED_ATTRIBUTE;

/**
 * 把App的主要window置灰，用于浮层弹出时，请注意要在适当时机调用`resetDimmedApplicationWindow`恢复到正常状态
 */
+ (void)dimmedApplicationWindow;

/**
 * 恢复对App的主要window的置灰操作，与`dimmedApplicationWindow`成对调用
 */
+ (void)resetDimmedApplicationWindow;

@end

@interface NOVAHelper (Animation)

/**
 在 animationBlock 里的操作完成之后会调用 completionBlock，常用于一些不提供 completionBlock 的系统动画操作，例如 [UINavigationController pushViewController:animated:YES] 的场景，注意 UIScrollView 系列的滚动无法使用这个方法。
 
 @param animationBlock 要进行的带动画的操作
 @param completionBlock 操作完成后的回调
 */
+ (void)executeAnimationBlock:(nonnull __attribute__((noescape)) void (^)(void))animationBlock completionBlock:(nullable __attribute__((noescape)) void (^)(void))completionBlock;

@end
NS_ASSUME_NONNULL_END
