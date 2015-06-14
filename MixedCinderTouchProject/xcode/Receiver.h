// Receiver.h - C++ header file
// Stéphane Adam Garnier - 2012

#ifndef Receiver_h
#define Receiver_h

#pragma once
#include <string>
#include <iostream>

class Receiver{ // declare class 'Receiver'
    
    //typedef void (&callback_function)(void);
    typedef void (&callback_function)(void); // for the fcn passed as reference
    typedef void (*callback_function_ptr)(); // for the fcn passed as pointer
	
public:
    Receiver(); // class Constructor
    
    
    // main set of functions //
    
    // setup class pointers to int 'intBufferPointer' & bool 'bufferUpdatePointer' from references taken from the variables passed as function parameters
    void setReceiverIntBufferAndBufferUpdateBool( int &theIntBuffer, bool &theBufferUpdateBool );
    // write dummy data to the variable pointed by private class member 'intBufferPointer' & set the bool pointed by private class member 'bufferUpdatePointer' to 1 ( true )
    void dummyWriteIntBufferAndBufferUpdateBool();
    
    // invoke the passed function immediatly by using a reference to it to init the call 
    void invokeFunctionPassedUsingReference( callback_function &theCallbackFunction );
    // setup a pointer to the function passed as parameter to the class public member function as a class private member
    void setCallbackFunctionPointerByCallbackFunctionReference( callback_function &theCallbackFunction );
    // invoke the function pointed by the class privat member pointer '_callbackFunctionPointer'
    void invokeCallbackFunctionFromHeldCallbackFunctionPointer(); // nb: implementation file hold code for both explicit and implicit 'dereference' (..)
    
    // objective-C++ part //
    
    // do a log test using a C++ 'ObjectiveC-function-wrapper' function ( uses 'NSLog' internally to print out infos to the console )
    void logSomethingUsingObjC();
    // init a callback from C++ -> ObjectiveC ( wich will invoke the function below in the opposite way , C++ <- ObjectiveC )
    void initCallbackFromObjectiveC();
    // callback invoked by some ObjetiveC code, itself initiated by the function above
    void callbackSometingFromObjectiveC();
    
    // threads part //
    void logOnThatThread();
    
private:
    int _intBufferReference;
    int *_intBufferPointer;
    
    bool _bufferUpdateBool;
    bool *_bufferUpdateBoolPointer;
    
    callback_function_ptr _callbackFunctionPointer;
};

#endif
