#ifndef __SET_H__
#define __SET_H__

#include "FSTool/FSTool.h"
#include "WPTool/WPTool.h"

using namespace FSTool;
using namespace WPTool;

// struct with config information 
struct config{
    std::string lang;   // localization language
    std::string mode;   // message delivery mode
    std::string format; // data and time format
};

// load settings to struct
void loadConfig(std::string filename, config & _config);

#endif