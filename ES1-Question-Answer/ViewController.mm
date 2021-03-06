//
//  ViewController.m
//  ES1-Question-Answer
//
//  Created by Moris on 10/03/2020.
//  Copyright © 2020 Moris. All rights reserved.
//

#import "ViewController.h"
#import "ESQuestion.h"

@interface ViewController ()

@property ESQuestion *questions;

@end

@implementation ViewController

@synthesize OutBtn1, OutBtn2, OutBtn3, OutBtn4, OutBtn5;
@synthesize Answer1, Answer2, Answer3, Answer4, Answer5;
@synthesize Question;

@synthesize questions;

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    *questions = ESQuestion("questions.json");

//    OutBtn1.hidden = YES;
//    OutBtn2.hidden = YES;
    OutBtn3.hidden = YES;
    OutBtn4.hidden = YES;
    OutBtn5.hidden = YES;
    
    Answer1.hidden = YES;
    Answer2.hidden = YES;
    Answer3.hidden = YES;
    Answer4.hidden = YES;
    Answer5.hidden = YES;
    
//    Question.hidden = YES;
    // Do any additional setup after loading the view.
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


- (IBAction)ActionBtn1:(NSButton *)sender {
    ESQuestion testES;
    
    
    Question.stringValue = [NSString stringWithCString: testES.testGet().c_str() encoding: [NSString defaultCStringEncoding]];
}

- (IBAction)ActionBtn2:(NSButton *)sender {
    NSOpenPanel *panel = [[NSOpenPanel alloc] init];
    
    panel.title = @"Open palette file";
    
    panel.showsResizeIndicator    = true;
    panel.showsHiddenFiles        = false;
    panel.canChooseDirectories    = true;
    panel.canCreateDirectories    = true;
    panel.allowsMultipleSelection = false;
    panel.allowedFileTypes        = @[@"json", @"tiff", @"tif"];
    
    if ([panel runModal] == NSModalResponseOK) {
        // Pathname of the file
        NSURL *result = panel.URL;
        
        NSLog(@"%@", result.path);
    } else {
        return;
    }
}

- (IBAction)ActionBtn3:(NSButton *)sender {
}

- (IBAction)ActionBtn4:(NSButton *)sender {
}

- (IBAction)ActionBtn5:(NSButton *)sender {
}
@end
