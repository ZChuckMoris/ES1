//
//  ViewController.h
//  ES1-Question-Answer
//
//  Created by Moris on 10/03/2020.
//  Copyright © 2020 Moris. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ViewController : NSViewController


#pragma mark - Buttons
- (IBAction)ActionBtn1:(NSButton *)sender;
- (IBAction)ActionBtn2:(NSButton *)sender;
- (IBAction)ActionBtn3:(NSButton *)sender;
- (IBAction)ActionBtn4:(NSButton *)sender;
- (IBAction)ActionBtn5:(NSButton *)sender;

@property (weak) IBOutlet NSButton *OutBtn1;
@property (weak) IBOutlet NSButton *OutBtn2;
@property (weak) IBOutlet NSButton *OutBtn3;
@property (weak) IBOutlet NSButton *OutBtn4;
@property (weak) IBOutlet NSButton *OutBtn5;

#pragma mark - Answers

@property (weak) IBOutlet NSTextField *Answer1;
@property (weak) IBOutlet NSTextField *Answer2;
@property (weak) IBOutlet NSTextField *Answer3;
@property (weak) IBOutlet NSTextField *Answer4;
@property (weak) IBOutlet NSTextField *Answer5;


@property (weak) IBOutlet NSTextField *Question;






@end

