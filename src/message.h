#ifndef __MESSAGE__H__
#define __MESSAGE__H__

#include <string>

class message{
friend void printMessage(message message); // output message
private:
    std::string text;
public:
    message(std::string text);       // constructors
    message(){};
    void set_text(std::string text); // set message text 
    std::string get_text();          // return message text
    void add(std::string text);      // added text to message
};

#endif