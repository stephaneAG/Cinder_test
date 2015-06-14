// Link.mm --- Obj-C++

#include "Link.h" // include the C++ file
#import "Url.h" // import the Obj-C file

#import <UIKit/UIKit.h> // as this example uses mobile safari (> iOS ) , import UIKit

// Obj-C part             
@implementation Url

+ ( void ) open: (NSString*) url {
	[ [ UIApplication sharedApplication ] openURL: [ NSURL URLWithString: url ]  ];                                                                                                                                                                                                                                                   
}

@end

// "C++ part"       
void Link::openURL ( const std::string &url ){ // C++ fcn ...
    
    // ... wrapping an Obj-C fcn !
	[ Url open: [ NSString stringWithCString: url.c_str() encoding: [ NSString defaultCStringEncoding ] ] ];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             

}