/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2010 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#import "TiViewProxy.h"
#import "TiAnimation.h"
#import "TiTab.h"
#import "TiUIWindow.h"
#import "TiUIView.h"

// specialization for TiViews that act like top level 
// windows when opened, closed, etc.
//
@interface TiWindowProxy : TiViewProxy<TiAnimationDelegate> {
@protected
	BOOL opened;
	BOOL focused;
	BOOL fullscreen;
	BOOL modal;
	BOOL restoreFullscreen;
	TiViewProxy<TiTab> *tab;
	UIViewController *controller;
	UINavigationController *navbar;
@private
	BOOL opening;
	BOOL attached;
	BOOL splashTransitionAnimation;
	int transitionAnimation;
	NSMutableArray *reattachWindows;
	UIView *closeView;
}

#pragma mark Public APIs

@property(nonatomic,readonly)	NSNumber *opened;
@property(nonatomic,readonly)	NSNumber *focused;

-(void)open:(id)args;
-(void)close:(id)args;
-(TiProxy*)tabGroup;
-(TiProxy<TiTab>*)tab;

#pragma mark Internal
-(void)attachViewToTopLevelWindow;
-(void)windowReady;
-(BOOL)_isChildOfTab;
-(void)_associateTab:(UIViewController*)controller_ navBar:(UINavigationController*)navbar_ tab:(TiProxy<TiTab>*)tab_;
-(UIViewController*)controller;
-(void)setController:(UIViewController *)controller;
-(void)setNavController:(UINavigationController*)navController;
-(UIWindow*)_window;
-(BOOL)_handleOpen:(id)args;
-(BOOL)_handleClose:(id)args;
-(void)_tabAttached;
-(void)_tabDetached;
-(void)_tabFocus;
-(void)_tabBlur;

-(void)_tabBeforeFocus;
-(void)_tabBeforeBlur;

-(void)setupWindowDecorations;

@end
