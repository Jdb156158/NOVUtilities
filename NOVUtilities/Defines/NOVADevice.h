//
//  NOVADevice.h
//  AFNetworking
//
//  Created by John Shu on 2020/2/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, NOVADeviceSimulator) {
    NOVADeviceiOSSimulator32_bit,
    NOVADeviceiOSSimulator64_bit
};

typedef NS_ENUM(NSUInteger, NOVADeviceiPhone) {
    NOVADevice_iPhone_1st_Gen,
    NOVADevice_iPhone_3G_2nd_Gen,
    NOVADevice_iPhone_3GS_3rd_Gen,
    NOVADevice_iPhone_4,
    NOVADevice_iPhone_4_GSM_Rev_A,
    NOVADevice_iPhone_4_CDMA,
    NOVADevice_iPhone_4s,
    NOVADevice_iPhone_5_GSM,
    NOVADevice_iPhone_5_CDMA_LTE,
    NOVADevice_iPhone_5c_GSM,
    NOVADevice_iPhone_5c_Global,
    NOVADevice_iPhone_5s_GSM,
    NOVADevice_iPhone_5s_Global,
    NOVADevice_iPhone_6_Plus,
    NOVADevice_iPhone_6,
    NOVADevice_iPhone_6s,
    NOVADevice_iPhone_6s_Plus,
    NOVADevice_iPhone_SE,
    NOVADevice_iPhone_7,
    NOVADevice_iPhone_7_Plus,
    NOVADevice_iPhone_7_no_CDMA,
    NOVADevice_iPhone_7_Plus_no_CDMA,
    NOVADevice_iPhone_8,
    NOVADevice_iPhone_8_Plus,
    NOVADevice_iPhone_X,
    NOVADevice_iPhone_8_no_CDMA,
    NOVADevice_iPhone_8_Plus_no_CDMA,
    NOVADevice_iPhone_X_no_CDMA,
    NOVADevice_iPhone_XS,
    NOVADevice_iPhone_XS_Max_China,
    NOVADevice_iPhone_XS_Max,
    NOVADevice_iPhone_XR,
    NOVADevice_iPhone_11,
    NOVADevice_iPhone_11_Pro,
    NOVADevice_iPhone_11_Pro_Max,

};

typedef NS_ENUM(NSUInteger, NOVADeviceiPod) {
    NOVADevice_iPod_1st_Gen,
    NOVADevice_iPod_2nd_Gen,
    NOVADevice_iPod_3rd_Gen,
    NOVADevice_iPod_4th_Gen,
    NOVADevice_iPod_5th_Gen,
    NOVADevice_iPod_6th_Gen,
    NOVADevice_iPod_7th_Gen,
};
                 
typedef NS_ENUM(NSUInteger, NOVADeviceiPad) {
    NOVADevice_iPad_1st_Gen_WiFi,
    NOVADevice_iPad_1st_Gen_3G,
    NOVADevice_iPad_2nd_Gen_WiFi,
    NOVADevice_iPad_2nd_Gen_GSM,
    NOVADevice_iPad_2nd_Gen_CDMA,
    NOVADevice_iPad_2nd_Gen_New_Revision,
    NOVADevice_iPad_mini_1st_Gen_WiFi,
    NOVADevice_iPad_mini_1st_Gen_GSM_LTE,
    NOVADevice_iPad_mini_1st_Gen_CDMA_LTE,
    NOVADevice_iPad_3rd_Gen_WiFi,
    NOVADevice_iPad_3rd_Gen_CDMA,
    NOVADevice_iPad_3rd_Gen_GSM,
    NOVADevice_iPad_4th_Gen_WiFi,
    NOVADevice_iPad_4th_Gen_GSM_LTE,
    NOVADevice_iPad_4th_Gen_CDMA_LTE,
    NOVADevice_iPad_Air_1st_Gen_WiFi,
    NOVADevice_iPad_Air_1st_Gen_GSM_CDMA,
    NOVADevice_iPad_Air_1st_Gen_China,
    NOVADevice_iPad_mini_2nd_Gen_WiFi,
    NOVADevice_iPad_mini_2nd_Gen_WiFi_Cellular,
    NOVADevice_iPad_mini_2nd_Gen_China,
    NOVADevice_iPad_mini_3rd_Gen_WiFi,
    NOVADevice_iPad_mini_3rd_Gen_WiFi_Cellular,
    NOVADevice_iPad_mini_3rd_Gen_China,
    NOVADevice_iPad_mini_4th_Gen_WiFi,
    NOVADevice_iPad_mini_4th_Gen_WiFi_Cellular,
    NOVADevice_iPad_Air_2_WiFi,
    NOVADevice_iPad_Air_2_WiFi_Cellular,
    NOVADevice_iPad_Pro_1st_Gen_9_7_inch_WiFi,
    NOVADevice_iPad_Pro_1st_Gen_9_7_inch_WiFi_Cellular,
    NOVADevice_iPad_Pro_1st_Gen_12_9_inch_WiFi,
    NOVADevice_iPad_Pro_1st_Gen_12_9_inch_WiFi_Cellular,
    NOVADevice_iPad_5th_Gen_WiFi,
    NOVADevice_iPad_5th_Gen_WiFi_Cellular,
    NOVADevice_iPad_Pro_2nd_Gen_12_9_inch_WiFi,
    NOVADevice_iPad_Pro_2nd_Gen_12_9_inch_WiFi_Cellular,
    NOVADevice_iPad_Pro_2nd_Gen_10_5_inch_WiFi,
    NOVADevice_iPad_Pro_2nd_Gen_10_5_inch_WiFi_Cellular,
    NOVADevice_iPad_6th_Gen_WiFi,
    NOVADevice_iPad_6th_Gen_WiFi_Cellular,
    NOVADevice_iPad_7th_Gen_10_2_inch_WiFi,
    NOVADevice_iPad_7th_Gen_10_2_inch_WiFi_Cellular,
    NOVADevice_iPad_Pro_3rd_Gen_11_inch_WiFi,
    NOVADevice_iPad_Pro_3rd_Gen_11_inch_WiFi_1TB,
    NOVADevice_iPad_Pro_3rd_Gen_11_inch_WiFi_Cellular,
    NOVADevice_iPad_Pro_3rd_Gen_11_inch_WiFi_Cellular_1TB,
    NOVADevice_iPad_Pro_3rd_Gen_12_9_inch_WiFi,
    NOVADevice_iPad_Pro_3rd_Gen_12_9_inch_WiFi_1TB,
    NOVADevice_iPad_Pro_3rd_Gen_12_9_inch_WiFi_Cellular,
    NOVADevice_iPad_Pro_3rd_Gen_12_9_inch_WiFi_Cellular_1TB,
    NOVADevice_iPad_mini_5th_Gen_WiFi,
    NOVADevice_iPad_mini_5th_Gen_WiFi_Cellular,
    NOVADevice_iPad_Air_3rd_Gen_WiFi,
    NOVADevice_iPad_Air_3rd_Gen_WiFi_Cellular,
};

typedef NS_ENUM(NSUInteger, NOVADeviceWatch) {
    NOVADevice_Apple_Watch_1st_Gen_38mm_case,
    NOVADevice_Apple_Watch_1st_Gen_42mm_case,
    NOVADevice_Apple_Watch_Series_1_38mm_case,
    NOVADevice_Apple_Watch_Series_1_42mm_case,
    NOVADevice_Apple_Watch_Series_2_38mm_case,
    NOVADevice_Apple_Watch_Series_2_42mm_case,
    NOVADevice_Apple_Watch_Series_3_38mm_case_GPS_Cellular,
    NOVADevice_Apple_Watch_Series_3_42mm_case_GPS_Cellular,
    NOVADevice_Apple_Watch_Series_3_38mm_case_GPS,
    NOVADevice_Apple_Watch_Series_3_42mm_case_GPS,
    NOVADevice_Apple_Watch_Series_4_40mm_case_GPS,
    NOVADevice_Apple_Watch_Series_4_44mm_case_GPS,
    NOVADevice_Apple_Watch_Series_4_40mm_case_GPS_Cellular,
    NOVADevice_Apple_Watch_Series_4_44mm_case_GPS_Cellular,
    NOVADevice_Apple_Watch_Series_5_40mm_case_GPS,
    NOVADevice_Apple_Watch_Series_5_44mm_case_GPS,
    NOVADevice_Apple_Watch_Series_5_40mm_case_GPS_Cellular,
    NOVADevice_Apple_Watch_Series_5_44mm_case_GPS_Cellular
};

@interface NOVADevice : NSObject
+ (BOOL)isSimulator;
+ (BOOL)isiPhone;
+ (BOOL)isiPod;
+ (BOOL)isiPad;
+ (BOOL)isAppleWatch;
+ (NSString *)deviceName;
+ (NSUInteger)currentDeviceType;
@end

NS_ASSUME_NONNULL_END
