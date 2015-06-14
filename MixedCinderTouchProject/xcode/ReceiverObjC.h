// ReceiverObjC.h - Objective-C header file
// Stéphane Adam Garnier - 2012

#ifndef ReceiverObjC_h
#define ReceiverObjC_h

#pragma once
#import <CoreFoundation/CoreFoundation.h>

@interface ReceiverObjC : NSObject {
}   

//+ ( void ) open: (NSString*) url;
+ ( void ) logSomething;
+ ( void ) logSomethingAndCallbackSomethingInCplusplus;

@end

#endif
