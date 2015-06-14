// Bridge.cpp - C++ implementation file
// Stéphane Adam Garnier - 2012

#include "Bridge.h" // include the C++ header file

// "C++ part"       
//void Bridge::setCallbackFunction( callback_function pFunc ){
//    _theCallbackFcn = pFunc; // store the callback function ( > wich is probably in the 'main' (..) )
//}

//void Bridge::setStrCallbackFunction(strCallback_function anStrCallbackFunction, std::string anStrCallbackFunctionParam){
//    _theStrCallbackfunction = anStrCallbackFunction;
//    _theStrCallbackFunctionParam = anStrCallbackFunctionParam;
//}

void Bridge::setStrCallbackFunction( strCallback_function strCallbackFunction, std::string strCallback_functionParam ){
    _theStrCallbackfunction = strCallbackFunction;
    _theStrCallbackFunctionParam = strCallback_functionParam;
}

void Bridge::setCharCallbackFunction( charCallback_function_ptr charCallbackFcnPtr, char* charCallback_functionParam ){
    _theCharCallbackFunctionPtr = charCallbackFcnPtr;
    _theCharCallbackFunctionParamPtr = charCallback_functionParam;
}

// call the callback function
//void Bridge::invokeCallbackFunction(){
//    _theCallbackFcn(); // call the stored callback function
//}

void Bridge::invokeStrCallbackfunction(){
        _theStrCallbackfunction( _theStrCallbackFunctionParam );
}


void Bridge::invokeCharCallbackFunction(){
    _theCharCallbackFunctionPtr( _theCharCallbackFunctionParamPtr );
}

