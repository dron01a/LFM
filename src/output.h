#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "FSTool/FSTool.h"
#include "WPTool/WPTool.h"
#include "settings.h"

using namespace FSTool;
using namespace WPTool;

class message{
private: 
    std::string _text;   // log text
public: 
    std::string text();               // return message text
    void setText(std::string text);   // reset message text
    void add(std::string text);       // added text to message
};

// output result message to log file
void log( struct config conf , std::string filename , message & message );

#endif