# MTZSplitViewController

A small project to improve the API for `UISplitViewController`.


### Current API

The current API for setting the view controllers on a `UISplitViewController` is currently just an `NSArray`:

```objc
@property (nonatomic, copy) NSArray *viewControllers;
```

The array must only contain two elements, and they must be of type `UIViewController` (or a subclass). The first view controller is used as the master view controller (left), and the second as the detail view controller (right). However, these cannot be enforced by the compiler, and can only be enforced at run-time. Based on this, maybe `NSArray` is not the best structure to use in this situation. Not only will it require run-time checks to enforce the restrictions, but the design of the interface does not hint at how to (successfully) use it. The user *must* read the documentation. These are not signs of good API.


### Proposed API Changes

Since the previous array required two view controllers, why not just have each of the view controllers as properties? In Xcode's Interface Builder, those two view controllers are even named "Master View Controller" and "Detail View Controller". Naturally, I designed the new interface as:

```objc
@property (nonatomic, assign) UIViewController *masterViewController;
@property (nonatomic, assign) UIViewController *detailViewController;
```

Each view controller is clearly labelled and little documentation is needed.

One issue with this API is that each of these properties *must* be set, otherwise it won't work.  One potential solution for this is to add an `init` function with both parameters:

```objc
- (instancetype)initWithMasterViewController:(UIViewController *)masterViewController
                     andDetailViewController:(UIViewController *)detailViewController;
```