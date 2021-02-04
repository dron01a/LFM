#ifndef __SET_H__
#define __SET_H__

#include "FSTool.h"
#include "WPTool.h"

using namespace FSTool;
using namespace WPTool;

class logger{
private: 
    file * logFile;
    std::string _text; // log text
    std::string _mode;  // output mode
public:
    logger(std::string logFile);     // constructors
    ~logger(); 
    std::string mode();              // return output mode    
    void setMode(std::string mode);  // set output mode 
    std::string text();              // return message text
    void add(std::string text);      // added text to message
    void add(int argc, char **argv); // set args tolog
};

// struct with config information 
struct config{
    std::string lang; // localization language
    std::string mode; // message delivery mode
};

// check file with program settings
void checkConfig(std::string filename); 

// load settings to struct
void loadConfig(std::string filename, config & _config);

#endif 