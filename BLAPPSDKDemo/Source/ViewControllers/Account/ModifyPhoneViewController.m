//
//  ModifyPhoneViewController.m
//  BLAPPSDKDemo
//
//  Created by hongkun.bai on 2018/7/4.
//  Copyright © 2018 BroadLink. All rights reserved.
//

#import "ModifyPhoneViewController.h"
#import "BLUserDefaults.h"
#import "BLStatusBar.h"
#import <BLLetAccount/BLLetAccount.h>

@interface ModifyPhoneViewController () <UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UITextField *countryField;
@property (weak, nonatomic) IBOutlet UITextField *phoneField;

@end

@implementation ModifyPhoneViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.countryField.delegate = self;
    self.phoneField.delegate = self;
}

- (IBAction)next:(id)sender {
    [self sendModifyPhoneVCode:self.phoneField.text countryCode:self.countryField.text];

    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"Please input verification code"
                                                                   message:nil
                                                            preferredStyle:UIAlertControllerStyleAlert];
    
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"Verification code";
    }];
    
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"Password";
    }];
    
    UIAlertAction *defaultAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction * action) {
                                                              NSString *vcode = alert.textFields.firstObject.text;
                                                              NSString *password = alert.textFields[1].text;
                                                              [self modifyPhone:self.phoneField.text countryCode:self.countryField.text vcode:vcode password:password];
                                                          }];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {}];
    
    [alert addAction:defaultAction];
    [alert addAction:cancelAction];
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)sendModifyPhoneVCode:(NSString *)phone countryCode:(NSString *)countryCode {
    [[BLAccount sharedAccount] sendModifyVCode:phone countryCode:countryCode completionHandler:^(BLBaseResult * _Nonnull result) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (result.succeed ) {
                [BLStatusBar showTipMessageWithStatus:@"Send verification code success!"];
            } else {
                [BLStatusBar showTipMessageWithStatus:[result getMsg]?:@""];
            }
        });
    }];
}

- (void)modifyPhone:(NSString *)phone countryCode:(NSString *)countryCode vcode:(NSString *)vcode password:(NSString *)password {

    [[BLAccount sharedAccount] modifyPhone:phone countryCode:countryCode vcode:vcode password:password newpassword:password completionHandler:^(BLBaseResult * _Nonnull result) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (result.succeed ) {
                [BLStatusBar showTipMessageWithStatus:@"Modify phone number success!"];
                [self.navigationController popViewControllerAnimated:YES];
            } else {
                [BLStatusBar showTipMessageWithStatus:[result getMsg]?:@""];
            }
        });
        
    }];
}

#pragma mark - text field delegate
- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return YES;
}

- (void)textFieldDidEndEditing:(UITextField *)textField {
    [textField resignFirstResponder];
}
@end
