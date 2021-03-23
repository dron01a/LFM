#include "operations.h"
#include "settings.h"
#include "localization.h"
#include "output.h"
#include "processing.h"
#include <iostream>

using namespace FSTool;

int main(int argc, char **argv){
    strvect params; // vector with argv 
    std::string homeDir = std::getenv("HOME");                // home dir
    std::string configPath = homeDir + "/.liza/config.txt";   // path to config 
    std::string logPath = homeDir + "/.liza/log.txt";         // path to log 
    std::string localPath = homeDir + "/.liza/localization/"; // path to localization
    config config; 
    loadConfig(configPath,config);
    localPath += config.lang;
    message result;  // result of the program
    for(int count = 0; count < argc; count++){
        params.push_back(argv[count]);
    }
    commandExexc(result, config, params);
    result.setText(localization(localPath,result.text()));
    if(config.mode == "display"){
        std::cout << result.text() << std::endl;
    } 
    log(config, logPath, result); // output log 
    return 0;
}