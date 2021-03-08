#include "operations.h"
#include "settings.h"
#include "localization.h"
#include "output.h"
#include <iostream>

using namespace FSTool;

int main(int argc, char **argv){
    std::string homeDir = std::getenv("HOME");                         // home dir
    std::string configPath = homeDir + "/.liza/config.txt";   // path to config 
    std::string logPath = homeDir + "/.liza/log.txt";         // path to log 
    std::string localPath = homeDir + "/.liza/localization/"; // path to localization
    config config; 
    loadConfig(configPath,config);
    localPath += config.lang;
    message result;  // result of the program
    if (strcmp(argv[1],"help") == 0){
        if(config.mode != "log"){
            result.add("<HELP>");
        }
    }
    else if(strcmp(argv[1],"mfl") == 0){
        if(argc < 3){
            result.add("<WRONG_ARGS>"); // if bad args 
        }
        for(int i = 2; i < argc; i++){
            create("<FILE>", argv[i], result);
        }
    }
    else if (strcmp(argv[1],"mdr") == 0){
        if(argc < 3){
            result.add("<WRONG_ARGS>"); // if bad args 
        }
        for(int i = 2; i < argc; i++){
            create("<FOLDER>", argv[i],result);
        }
    }
    else if (strcmp(argv[1],"move") == 0){
        if(argc < 4 || argc > 4 ){
            result.add("<WRONG_ARGS>");
        }
        move(argv[2],argv[3],result);
    }
    else if(strcmp(argv[1],"rfl") == 0){
        if(argc < 3){
            result.add("<WRONG_ARGS>");
        }    
        for(int i = 2; i < argc; i++){
            destroy("<FILE>", argv[i],result);
        }
    }   
    else if (strcmp(argv[1],"rdr") == 0){
        if(argc < 3){
            result.add("<WRONG_ARGS>");
        }    
        for(int i = 2; i < argc; i++){
            destroy("<FOLDER>", argv[i],result);
        }
    }
    else if (strcmp(argv[1],"remove") == 0){
        for(int i = 2; i < argc; i++){
            destroy(argv[i],result);
        }
    }
    else if (strcmp(argv[1],"rename") == 0){
        if(argc < 4 || argc > 4 ){
            result.add("<WRONG_ARGS>");
        }
        rename(argv[2],argv[3],result);
    }
    else if(strcmp(argv[1],"info") == 0){
        information(argv[2],result);
    }
    else{
        if(config.mode != "log"){
            result.add("<NON_COMMAND>");
        }
    }
    result.setText(localization(localPath,result.text()));
    if(config.mode == "display"){
        std::cout << result.text() << std::endl;
    } 
    log(config, logPath, result); // output log 
    return 0;
}
