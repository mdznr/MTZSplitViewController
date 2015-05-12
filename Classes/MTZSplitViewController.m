//
//  MTZSplitViewController.m
//  SplitViewController
//
//  Created by Matt Zanchelli on 4/27/14.
//  Copyright (c) 2014 Matt Zanchelli. All rights reserved.
//

#import "MTZSplitViewController.h"

@interface MTZSplitViewController ()

@end

@implementation MTZSplitViewController

- (instancetype)initWithMasterViewController:(UIViewController *)masterViewController
					 andDetailViewController:(UIViewController *)detailViewController
{
	// Both masterViewController and detailViewController must be non-nil.
	if ( !masterViewController || !detailViewController ) {
		NSLog(@"Both masterViewController and detailViewController must be non-nil.");
		return nil;
	}
	
	self = [super init];
	if (self) {
		_masterViewController = masterViewController;
		_detailViewController = detailViewController;
		[self udpateViewControllersArray];
	}
	return self;
}

- (void)setMasterViewController:(UIViewController *)masterViewController
{
	_masterViewController = masterViewController;
	[self udpateViewControllersArray];
}

- (UIViewController *)masterViewController
{
	if ([super.viewControllers count] >= 0) {
		return super.viewControllers[0];
	}
	
	return nil;
}

- (void)setDetailViewController:(UIViewController *)detailViewController
{
	_detailViewController = detailViewController;
	[self udpateViewControllersArray];
}

- (UIViewController *)detailViewController
{
	if ([super.viewControllers count] > 0) {
		return super.viewControllers[1];
	}
	
	return nil;
}

- (void)udpateViewControllersArray
{
	// Both must be non-nil to initialize array.
	if ( _masterViewController && _detailViewController ) {
		super.viewControllers = @[_masterViewController, _detailViewController];
	}
}

@end
