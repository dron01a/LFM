#ifndef __SET_H__
#define __SET_H__

#include "FSTool.h"
#include "WPTool.h"

using namespace FSTool;
using namespace WPTool;

// struct with config information 
struct config{
    std::string lang;   // localization language
    std::string mode;   // message delivery mode
    std::string format; // data and time format
};

class logger{
private: 
    file * logFile;
    std::string _text;   // log text
    std::string _mode;   // output mode
    std::string _format; // data format
    std::string _args;   // args passed to program
public:
    logger(std::string logFile);     // constructors
    ~logger();  
    void loadSettings(config config); // load config  
    std::string mode();               // return output mode    
    std::string text();               // return message text
    void add(std::string text);       // added text to message
    void add(int argc, char **argv);  // set args tolog
};


// check file with program settings
void checkConfig(std::string filename); 

// load settings to struct
void loadConfig(std::string filename, config & _config);

#endif 