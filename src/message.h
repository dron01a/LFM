#ifndef __MESS__H__
#define __MESS__H__

#include <iostream>
#include <string>

class message{
private:
    std::string mes; 
public:
    void set(std::string text); // set text to message
    std::string get();          // get text message
};

void return_message(message mes); //set message to output thread

#endif