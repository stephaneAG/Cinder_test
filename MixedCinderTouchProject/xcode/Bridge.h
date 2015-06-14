// Bridge.h - C++ header file
// Stéphane Adam Garnier - 2012

#pragma once
#include <string>

class Bridge{    
	//typedef void (*callback_function)(void); // typedef for conciseness of callback fcn
    typedef void(*strCallback_function)(std::string); // should work for functions that pass a string (..)
    typedef void(*charCallback_function_ptr)( const char* );
	
    public:
        //static void openURL( const std::string &url); // needed 'static' to invoke Obj-C fcns
    
        // set the callbax function
        //void setCallbackFunction( callback_function pFunc );
        //void setStrCallbackFunction( strCallback_function strCallbackFunc, std::string strParam );
    void setStrCallbackFunction( void(*strCallback_function)(std::string), std::string strCallback_functionParam );
        void setCharCallbackFunction( charCallback_function_ptr charCallbackFcnPtr, char* charCallback_functionParam );
 
    private:
        //callback_function _theCallbackFcn; // a variable to store the callback function
        strCallback_function _theStrCallbackfunction;
        std::string _theStrCallbackFunctionParam;
    
        charCallback_function_ptr _theCharCallbackFunctionPtr;
        char* _theCharCallbackFunctionParamPtr;
        
        // call the callback function
        //void invokeCallbackFunction();
        void invokeStrCallbackfunction();
        void invokeCharCallbackFunction();

};









  