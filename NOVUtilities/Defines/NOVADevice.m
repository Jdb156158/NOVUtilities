//
//  NOVADevice.m
//  AFNetworking
//
//  Created by John Shu on 2020/2/12.
//

#import "NOVADevice.h"
#import <sys/utsname.h>

static NSDictionary *deviceDic = nil;

@implementation NOVADevice
+ (NSUInteger)currentDeviceType {
    NSNumber *deviceTypeNumber = [self deviceDic][[self deviceName]];
    if (deviceTypeNumber) {
        return [deviceTypeNumber unsignedIntValue];
    } else {
        return NSUIntegerMax;
    }
}

+ (BOOL)isSimulator {
    return [[self deviceName] containsString:@"i386"]
    || [[self deviceName] containsString:@"x86_64"];
}

+ (BOOL)isiPod {
    return [[self deviceName] containsString:@"iPod"];
}

+ (BOOL)isiPhone {
    return [[self deviceName] containsString:@"iPhone"];
}

+ (BOOL)isiPad {
    return [[self deviceName] containsString:@"iPad"];
}

+ (BOOL)isAppleWatch {
    return [[self deviceName] containsString:@"Watch"];
}

+ (NSString *)deviceName {
    struct utsname systemInfo;
    uname(&systemInfo);
    NSString *name = [NSString stringWithCString:systemInfo.machine
                               encoding:NSUTF8StringEncoding];
    
    return name;
}

+ (NSDictionary *)deviceDic {
    if (deviceDic == nil) {
        deviceDic = @{
            @"i386":        @(NOVADeviceiOSSimulator32_bit),
            @"x86_64":       @(NOVADeviceiOSSimulator64_bit),
            
            @"iPhone1,1":        @(NOVADevice_iPhone_1st_Gen),
            @"iPhone1,2":        @(NOVADevice_iPhone_3G_2nd_Gen),
            @"iPhone2,1":        @(NOVADevice_iPhone_3GS_3rd_Gen),
            @"iPhone3,1":        @(NOVADevice_iPhone_4),
            @"iPhone3,2":        @(NOVADevice_iPhone_4_GSM_Rev_A),
            @"iPhone3,3":        @(NOVADevice_iPhone_4_CDMA),
            @"iPhone4,1":        @(NOVADevice_iPhone_4s),
            @"iPhone5,1":        @(NOVADevice_iPhone_5_GSM),
            @"iPhone5,2":        @(NOVADevice_iPhone_5_CDMA_LTE),
            @"iPhone5,3":        @(NOVADevice_iPhone_5c_GSM),
            @"iPhone5,4":        @(NOVADevice_iPhone_5c_Global),
            @"iPhone6,1":        @(NOVADevice_iPhone_5s_GSM),
            @"iPhone6,2":        @(NOVADevice_iPhone_5s_Global),
            @"iPhone7,1":        @(NOVADevice_iPhone_6_Plus),
            @"iPhone7,2":        @(NOVADevice_iPhone_6),
            @"iPhone8,1":        @(NOVADevice_iPhone_6s),
            @"iPhone8,2":        @(NOVADevice_iPhone_6s_Plus),
            @"iPhone8,4":        @(NOVADevice_iPhone_SE),
            @"iPhone9,1":        @(NOVADevice_iPhone_7),
            @"iPhone9,2":        @(NOVADevice_iPhone_7_Plus),
            @"iPhone9,3":        @(NOVADevice_iPhone_7_no_CDMA),
            @"iPhone9,4":        @(NOVADevice_iPhone_7_Plus_no_CDMA),
            @"iPhone10,1":       @(NOVADevice_iPhone_8),
            @"iPhone10,2":       @(NOVADevice_iPhone_8_Plus),
            @"iPhone10,3":       @(NOVADevice_iPhone_X),
            @"iPhone10,4":       @(NOVADevice_iPhone_8_no_CDMA),
            @"iPhone10,5":       @(NOVADevice_iPhone_8_Plus_no_CDMA),
            @"iPhone10,6":       @(NOVADevice_iPhone_X_no_CDMA),
            @"iPhone11,2":       @(NOVADevice_iPhone_XS),
            @"iPhone11,4":       @(NOVADevice_iPhone_XS_Max_China),
            @"iPhone11,6":       @(NOVADevice_iPhone_XS_Max),
            @"iPhone11,8":       @(NOVADevice_iPhone_XR),
            @"iPhone12,1":       @(NOVADevice_iPhone_11),
            @"iPhone12,3":       @(NOVADevice_iPhone_11_Pro),
            @"iPhone12,5":       @(NOVADevice_iPhone_11_Pro_Max),

            @"iPod1,1":      @(NOVADevice_iPod_1st_Gen),
            @"iPod2,1":      @(NOVADevice_iPod_2nd_Gen),
            @"iPod3,1":      @(NOVADevice_iPod_3rd_Gen),
            @"iPod4,1":      @(NOVADevice_iPod_4th_Gen),
            @"iPod5,1":      @(NOVADevice_iPod_5th_Gen),
            @"iPod7,1":      @(NOVADevice_iPod_6th_Gen),
            @"iPod9,1":      @(NOVADevice_iPod_7th_Gen),

            @"iPad1,1":      @(NOVADevice_iPad_1st_Gen_WiFi),
            @"iPad1,2":      @(NOVADevice_iPad_1st_Gen_3G),
            @"iPad2,1":      @(NOVADevice_iPad_2nd_Gen_WiFi),
            @"iPad2,2":      @(NOVADevice_iPad_2nd_Gen_GSM),
            @"iPad2,3":      @(NOVADevice_iPad_2nd_Gen_CDMA),
            @"iPad2,4":      @(NOVADevice_iPad_2nd_Gen_New_Revision),
            @"iPad2,5":      @(NOVADevice_iPad_mini_1st_Gen_WiFi),
            @"iPad2,6":      @(NOVADevice_iPad_mini_1st_Gen_GSM_LTE),
            @"iPad2,7":      @(NOVADevice_iPad_mini_1st_Gen_CDMA_LTE),
            @"iPad3,1":      @(NOVADevice_iPad_3rd_Gen_WiFi),
            @"iPad3,2":      @(NOVADevice_iPad_3rd_Gen_CDMA),
            @"iPad3,3":      @(NOVADevice_iPad_3rd_Gen_GSM),
            @"iPad3,4":      @(NOVADevice_iPad_4th_Gen_WiFi),
            @"iPad3,5":      @(NOVADevice_iPad_4th_Gen_GSM_LTE),
            @"iPad3,6":      @(NOVADevice_iPad_4th_Gen_CDMA_LTE),
            @"iPad4,1":      @(NOVADevice_iPad_Air_1st_Gen_WiFi),
            @"iPad4,2":      @(NOVADevice_iPad_Air_1st_Gen_GSM_CDMA),
            @"iPad4,3":      @(NOVADevice_iPad_Air_1st_Gen_China),
            @"iPad4,4":      @(NOVADevice_iPad_mini_2nd_Gen_WiFi),
            @"iPad4,5":      @(NOVADevice_iPad_mini_2nd_Gen_WiFi_Cellular),
            @"iPad4,6":      @(NOVADevice_iPad_mini_2nd_Gen_China),
            @"iPad4,7":      @(NOVADevice_iPad_mini_3rd_Gen_WiFi),
            @"iPad4,8":      @(NOVADevice_iPad_mini_3rd_Gen_WiFi_Cellular),
            @"iPad4,9":      @(NOVADevice_iPad_mini_3rd_Gen_China),
            @"iPad5,1":      @(NOVADevice_iPad_mini_4th_Gen_WiFi),
            @"iPad5,2":      @(NOVADevice_iPad_mini_4th_Gen_WiFi_Cellular),
            @"iPad5,3":      @(NOVADevice_iPad_Air_2_WiFi),
            @"iPad5,4":      @(NOVADevice_iPad_Air_2_WiFi_Cellular),
            @"iPad6,3":      @(NOVADevice_iPad_Pro_1st_Gen_9_7_inch_WiFi),
            @"iPad6,4":      @(NOVADevice_iPad_Pro_1st_Gen_9_7_inch_WiFi_Cellular),
            @"iPad6,7":      @(NOVADevice_iPad_Pro_1st_Gen_12_9_inch_WiFi),
            @"iPad6,8":      @(NOVADevice_iPad_Pro_1st_Gen_12_9_inch_WiFi_Cellular),
            @"iPad6,11":     @(NOVADevice_iPad_5th_Gen_WiFi),
            @"iPad6,12":     @(NOVADevice_iPad_5th_Gen_WiFi_Cellular),
            @"iPad7,1":      @(NOVADevice_iPad_Pro_2nd_Gen_12_9_inch_WiFi),
            @"iPad7,2":      @(NOVADevice_iPad_Pro_2nd_Gen_12_9_inch_WiFi_Cellular),
            @"iPad7,3":      @(NOVADevice_iPad_Pro_2nd_Gen_10_5_inch_WiFi),
            @"iPad7,4":      @(NOVADevice_iPad_Pro_2nd_Gen_10_5_inch_WiFi_Cellular),
            @"iPad7,5":      @(NOVADevice_iPad_6th_Gen_WiFi),
            @"iPad7,6":      @(NOVADevice_iPad_6th_Gen_WiFi_Cellular),
            @"iPad7,11":     @(NOVADevice_iPad_7th_Gen_10_2_inch_WiFi),
            @"iPad7,12":     @(NOVADevice_iPad_7th_Gen_10_2_inch_WiFi_Cellular),
            @"iPad8,1":      @(NOVADevice_iPad_Pro_3rd_Gen_11_inch_WiFi),
            @"iPad8,2":      @(NOVADevice_iPad_Pro_3rd_Gen_11_inch_WiFi_1TB),
            @"iPad8,3":      @(NOVADevice_iPad_Pro_3rd_Gen_11_inch_WiFi_Cellular),
            @"iPad8,4":      @(NOVADevice_iPad_Pro_3rd_Gen_11_inch_WiFi_Cellular_1TB),
            @"iPad8,5":      @(NOVADevice_iPad_Pro_3rd_Gen_12_9_inch_WiFi),
            @"iPad8,6":      @(NOVADevice_iPad_Pro_3rd_Gen_12_9_inch_WiFi_1TB),
            @"iPad8,7":      @(NOVADevice_iPad_Pro_3rd_Gen_12_9_inch_WiFi_Cellular),
            @"iPad8,8":      @(NOVADevice_iPad_Pro_3rd_Gen_12_9_inch_WiFi_Cellular_1TB),
            @"iPad11,1":     @(NOVADevice_iPad_mini_5th_Gen_WiFi),
            @"iPad11,2":     @(NOVADevice_iPad_mini_5th_Gen_WiFi_Cellular),
            @"iPad11,3":     @(NOVADevice_iPad_Air_3rd_Gen_WiFi),
            @"iPad11,4":     @(NOVADevice_iPad_Air_3rd_Gen_WiFi_Cellular),

            @"Watch1,1":     @(NOVADevice_Apple_Watch_1st_Gen_38mm_case),
            @"Watch1,2":     @(NOVADevice_Apple_Watch_1st_Gen_42mm_case),
            @"Watch2,6":     @(NOVADevice_Apple_Watch_Series_1_38mm_case),
            @"Watch2,7":     @(NOVADevice_Apple_Watch_Series_1_42mm_case),
            @"Watch2,3":     @(NOVADevice_Apple_Watch_Series_2_38mm_case),
            @"Watch2,4":     @(NOVADevice_Apple_Watch_Series_2_42mm_case),
            @"Watch3,1":     @(NOVADevice_Apple_Watch_Series_3_38mm_case_GPS_Cellular),
            @"Watch3,2":     @(NOVADevice_Apple_Watch_Series_3_42mm_case_GPS_Cellular),
            @"Watch3,3":     @(NOVADevice_Apple_Watch_Series_3_38mm_case_GPS),
            @"Watch3,4":     @(NOVADevice_Apple_Watch_Series_3_42mm_case_GPS),
            @"Watch4,1":     @(NOVADevice_Apple_Watch_Series_4_40mm_case_GPS),
            @"Watch4,2":     @(NOVADevice_Apple_Watch_Series_4_44mm_case_GPS),
            @"Watch4,3":     @(NOVADevice_Apple_Watch_Series_4_40mm_case_GPS_Cellular),
            @"Watch4,4":     @(NOVADevice_Apple_Watch_Series_4_44mm_case_GPS_Cellular),
            @"Watch5,1":     @(NOVADevice_Apple_Watch_Series_5_40mm_case_GPS),
            @"Watch5,2":     @(NOVADevice_Apple_Watch_Series_5_44mm_case_GPS),
            @"Watch5,3":     @(NOVADevice_Apple_Watch_Series_5_40mm_case_GPS_Cellular),
            @"Watch5,4":     @(NOVADevice_Apple_Watch_Series_5_44mm_case_GPS_Cellular)
        };
    }
    return deviceDic;
}
@end
