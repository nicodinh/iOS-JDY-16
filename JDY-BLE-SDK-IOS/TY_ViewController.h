//
//  TY_ViewController.h
//  YGHTabBar
//
//  Created by apple on 17/2/8.
//  Copyright © 2017年 YangGH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>
#import "JDY_BLE.h"
@protocol TY_Delegate
@optional

/*
 -(void) TY_send_data_hex:(NSString*)data : (Boolean) uart_function_select :(Boolean)hex_or_string
 
uart_function_select=true表示透传
uart_function_select=false表示功能
hex_or_string=true表示十六进制发
hex_or_string=false表示字符串发
*/
-(void) TY_send_data_hex:(NSString*)data : (Boolean) uart_function_select :(Boolean)hex_or_string;



-(void) first_ble_scan:(Boolean)p;


-(void)send_data:(Byte *)bytes :(int)len : (Boolean) p;

- (JDY_BLE *) fetch_t;

-(int) read_rssi_event;


@end

@interface TY_ViewController : UIViewController<UITextViewDelegate,UITextViewDelegate,CBCentralManagerDelegate>


@property (nonatomic,assign) id <TY_Delegate> delegate;

@property (weak, nonatomic) IBOutlet UIImageView *chek_image_button1;
@property (weak, nonatomic) IBOutlet UIImageView *chek_image_button2;



@property (weak, nonatomic) IBOutlet UIImageView *IO_Button1;
@property (weak, nonatomic) IBOutlet UIImageView *IO_Button2;
@property (weak, nonatomic) IBOutlet UIImageView *IO_Button3;
@property (weak, nonatomic) IBOutlet UIImageView *IO_Button4;

@property (weak, nonatomic) IBOutlet UILabel *rx_len_text;
@property (weak, nonatomic) IBOutlet UILabel *tx_len_text;
@property (weak, nonatomic) IBOutlet UILabel *freq_test;

@property (weak, nonatomic) IBOutlet UILabel *pwm1_thrust;

@property (weak, nonatomic) IBOutlet UILabel *pwm2_thrust;

@property (weak, nonatomic) IBOutlet UILabel *pwm3_thrust;

@property (weak, nonatomic) IBOutlet UILabel *pwm4_thrust;

@property (weak, nonatomic) IBOutlet UILabel *pwm_ratio;

@property (weak, nonatomic) IBOutlet UITextView *rx_text;
@property (weak, nonatomic) IBOutlet UITextView *tx_text;



@property (weak, nonatomic) IBOutlet UISwitch *switch_pwm;
@property (weak, nonatomic) IBOutlet UISwitch *switch_intg;


@property (weak, nonatomic) IBOutlet UILabel *pwm_pen_text;

@property (weak, nonatomic) IBOutlet UIButton *send_button;
@property (weak, nonatomic) IBOutlet UIButton *clear_button;
@property (weak, nonatomic) IBOutlet UIButton *add_button;

@property (weak, nonatomic) IBOutlet UISwitch *accelorator;

@property (weak, nonatomic) IBOutlet UISlider *pwm1_pulse_slide;
@property (weak, nonatomic) IBOutlet UISlider *pwm2_pulse_slide;
@property (weak, nonatomic) IBOutlet UISlider *pwm3_pulse_slide;
@property (weak, nonatomic) IBOutlet UISlider *pwm4_pulse_slide;
@property (weak, nonatomic) IBOutlet UISlider *pwm_freq_slide;
@property (weak, nonatomic) IBOutlet UISlider *pwm_ratio_slide;
@property (weak, nonatomic) IBOutlet UISlider *pwm3_hori_slide;




@property (weak, nonatomic) IBOutlet UISegmentedControl *pwm_switch;
-(void)rx_ble_event:(Byte *)bytes :(int)len;//特征UUID FFE1透传接收
-(void)rx_ble_function_event:(Byte *)bytes :(int)len;//功能特征UUID FFE2接收数据函数

@end
