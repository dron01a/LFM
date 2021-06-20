#ifndef __SET_H__
#define __SET_H__

#include "../../libs/FSTool_lib/FSTool.h"
#include "../../libs/WPTool_lib/WPTool.h"
#include <map>

using namespace FSTool;
using namespace WPTool;

// struct with config information 
struct config{
    std::string lang;   // localization language
    std::string mode;   // message delivery mode
    std::string format; // data and time format
    std::map<std::string,std::string> commnads;  
};

// load settings to struct
void loadConfig(std::string filename, config & _config);

#endif