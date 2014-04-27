//
//  MTZMasterViewController.h
//  SplitViewController
//
//  Created by Matt Zanchelli on 4/27/14.
//  Copyright (c) 2014 Matt Zanchelli. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MTZDetailViewController;

@interface MTZMasterViewController : UITableViewController

@property (strong, nonatomic) MTZDetailViewController *detailViewController;

@end
