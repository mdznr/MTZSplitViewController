# MTZSplitViewController

A small project to improve the API for `UISplitViewController`.


### Current API

The current API for setting the view controllers on a `UISplitViewController` is currently just an `NSArray`:

```objc
@property (nonatomic, copy) NSArray *viewControllers;
```

The array must only contain two elements, and they must be of type `UIViewController` (or a subclass). However, these cannot be enforced by the compiler, and can only be enforced at run-time. Based on this, maybe `NSArray` is not the best structure to use in this situation. Not only will it require runtime checks to enforce the restrictions, but the design of the interface does not hint at how to (successfully) use it. The user *must* read the documentation. This is not a sign of good API.


### Proposed API Changes

Since the previous array required two view controllers, why not just have each of the view controllers as properties? In Xcode's Interface Builder, those two view controllers are even named "Master View Controller" and "Detail View Controller". Naturally, I designed the new interface as:

```objc
@property (nonatomic, assign) UIViewController *masterViewController;
@property (nonatomic, assign) UIViewController *detailViewController;
```
