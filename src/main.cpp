#include "operations.h"
#include "settings.h"
#include "localization.h"

using namespace FSTool;

int main(int argc, char **argv){
    std::string homeDir = std::getenv("HOME");                         // home dir
    std::string configPath = homeDir + "/.armodrey/liza/config.txt";   // path to config 
    std::string logPath = homeDir + "/.armodrey/liza/log.txt";         // path to log 
    std::string localPath = homeDir + "/.armodrey/liza/localization/"; // path to localization
    config config; 
    loadConfig(configPath,config);
    localPath += config.lang;
    logger * log = new logger(logPath);  // result of the program
    log->loadSettings(config);
    log->add(argc, argv);
    if (strcmp(argv[1],"help") == 0){
        if(log->mode() != "log"){
            log->add("<HELP>");
        }
    }
    else if(strcmp(argv[1],"mfl") == 0){
        if(argc < 3){
            log->add("<WRONG_ARGS>"); // if bad args 
        }
        for(int i = 2; i < argc; i++){
            create("<FILE>", argv[i],*log);
        }
    }
    else if (strcmp(argv[1],"mdr") == 0){
        if(argc < 3){
            log->add("<WRONG_ARGS>"); // if bad args 
        }
        for(int i = 2; i < argc; i++){
            create("<FOLDER>", argv[i],*log);
        }
    }
    else if (strcmp(argv[1],"move") == 0){
        if(argc < 4 || argc > 4 ){
            log->add("<WRONG_ARGS>");
        }
        move(argv[2],argv[3],*log);
    }
    else if(strcmp(argv[1],"rfl") == 0){
        if(argc < 3){
            log->add("<WRONG_ARGS>");
        }    
        for(int i = 2; i < argc; i++){
            destroy("<FILE>", argv[i],*log);
        }
    }   
    else if (strcmp(argv[1],"rdr") == 0){
        if(argc < 3){
            log->add("<WRONG_ARGS>");
        }    
        for(int i = 2; i < argc; i++){
            destroy("<FOLDER>", argv[i],*log);
        }
    }
    else if (strcmp(argv[1],"remove") == 0){
        for(int i = 2; i < argc; i++){
            destroy(argv[i],*log);
        }
    }
    else if (strcmp(argv[1],"rename") == 0){
        if(argc < 4 || argc > 4 ){
            log->add("<WRONG_ARGS>");
        }
        rename(argv[2],argv[3],*log);
    }
    else if(strcmp(argv[1],"info") == 0){
        information(argv[2],*log);
    }
    else{
        if(log->mode() != "log"){
            log->add("<NON_COMMAND>");
        }
    }
    log->setText(localization(localPath,log->text())); 
    delete log;
    return 0;
}

