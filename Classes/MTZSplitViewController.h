//
//  MTZSplitViewController.h
//  SplitViewController
//
//  Created by Matt Zanchelli on 4/27/14.
//  Copyright (c) 2014 Matt Zanchelli. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <AvailabilityMacros.h>

@interface MTZSplitViewController : UISplitViewController

/// Initializes and returns a newly created split view controller.
/// @param masterViewController The view controller to be shown on the left side of the interface.
/// @param detailViewController The view controller to be shown on the right side of the interface.
/// @return The initialized split view controller object or @c nil if there was a problem initializing the object.
- (instancetype)initWithMasterViewController:(UIViewController *)masterViewController
					 andDetailViewController:(UIViewController *)detailViewController;

/// The view controller to display on the left side of the interface and purpose as the master view controller.
/// This view controller is typically hidden when the device is in a portrait orientation, and displayed alongside @c detailViewController when in landscape orientation.
@property (nonatomic, assign) UIViewController *masterViewController;

/// The view controller to display on the right side of the interface and purpose as the detail view controller.
@property (nonatomic, assign) UIViewController *detailViewController;


#pragma mark - Deprecated

/// The array of view controllers managed by the receiver.
/// @discussion The array in this property must contain exactly two view controllers. The view controllers are presented left-to-right in the split view interface when it is in a landscape orientation. Thus, the view controller at index 0 is displayed on the left side and the view controller at index 1 is displayed on the right side of the interface.
/// @discussion The first view controller in this array is typically hidden when the device is in a portrait orientation. Assign a delegate object to the receiver if you want to coordinate the display of this view controller using a popover.
@property (nonatomic, copy) NSArray *viewControllers DEPRECATED_ATTRIBUTE;

@end
