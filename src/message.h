#ifndef __MESS__H__
#define __MESS__H__

#include <iostream>
#include <string>

class message{
private:
    std::string mes; 
    std::string text_color = "\033[30m"; 
public:
    void set_text_color(std::string color); // set text color
    std::string get_text_color();           // get text color
    void set(std::string text);             // set text to message
    std::string get();                      // get text message
};

void return_message(message mes); //set message to output thread

#endif