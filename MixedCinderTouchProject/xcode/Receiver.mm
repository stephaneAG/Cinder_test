// Receiver.mm - ObjC++ implementation file
// Stéphane Adam Garnier - 2012

#include "Receiver.h" // include the C++ header file
#import "ReceiverObjC.h" // import the Obj-C file

#import <UIKit/UIKit.h> // as this example uses mobile safari (> iOS ) , import UIKit

// "Obj-C code part"              
@implementation ReceiverObjC


+ ( void ) logSomething{
    NSLog(@"This log was printed using Objective-C code, invoked from C++ code");
}

+ ( void ) logSomethingAndCallbackSomethingInCplusplus{
    NSLog(@".. this log was printed after an ObjectiveC function has been invoked from C++ code ..");
    Receiver().callbackSometingFromObjectiveC();
}

@end
// "C++ code part" 

void Receiver::logSomethingUsingObjC(){
	[ ReceiverObjC logSomething ];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}

void Receiver::initCallbackFromObjectiveC(){
    std::cout << "Initiating callback from C++ to ObjectiveC .." << std::endl;
	[ ReceiverObjC logSomethingAndCallbackSomethingInCplusplus ];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}

void Receiver::callbackSometingFromObjectiveC(){
    std::cout << "This text was printed after a callback from an ObjectiveC function invoking a C++ function" << std::endl;
}

// "Obj-C++ code part"

 Receiver::Receiver(){
     _intBufferReference = NULL;
     _intBufferPointer = NULL;
     //_charBufferReference = NULL;
     _bufferUpdateBool = 0;
     _bufferUpdateBoolPointer = NULL;
     //_callbackFunction = NULL;
     _callbackFunctionPointer = NULL;
 }


void Receiver::setReceiverIntBufferAndBufferUpdateBool( int &theIntBuffer, bool &theBufferUpdateBool ){
    std::cout << " [ Receiver::setReceiverIntBufferAndBufferUpdateBool() ] " << std::endl;
    _intBufferPointer = &theIntBuffer;
    _bufferUpdateBoolPointer = &theBufferUpdateBool;
}

void Receiver::dummyWriteIntBufferAndBufferUpdateBool(){
    std::cout << " [ Receiver::dummyWriteIntBufferAndBufferUpdateBool() ] " << std::endl;
    *_intBufferPointer = 45454545; // update the value pointed by the pointer held by the 'Receiver' class private var
    *_bufferUpdateBoolPointer = 1; // update the bool to indicate new data ( can be used in the 'main' loop , example in cinder maybe in the 'update' fcn (..) )
}

void Receiver::invokeFunctionPassedUsingReference( callback_function &theCallbackFunction  ){
    std::cout << " [ Receiver::invokeFunctionPassedUsingReference() ] " << std::endl;
    theCallbackFunction(); // invoke the function passed by reference
}

void Receiver::setCallbackFunctionPointerByCallbackFunctionReference( callback_function &theCallbackFunction ){ // hold the passed function reference as a pointer var
    std::cout << " [ Receiver::setCallbackFunctionPointerByCallbackFunctionReference() ] " << std::endl;
    _callbackFunctionPointer = theCallbackFunction; // assign the function passed as reference to the class 'callbackFunctionPointer'
}

void Receiver::invokeCallbackFunctionFromHeldCallbackFunctionPointer(){ // invoke function from held pointer var using  explicit or implicit 'dereference'
    std::cout << " [ Receiver::invokeCallbackFunctionFromHeldCallbackFunctionPointer() ] " << std::endl;
    // manner 1: using 'explicit dereference'
    //(*_callbackFunctionPointer)(); // works
    
    // manner 2: using 'implicit dereference'
    _callbackFunctionPointer();
}


// threads part
void Receiver::logOnThatThread(){
    std::cout << "Logged from thread !!! ..." << std::endl;
}