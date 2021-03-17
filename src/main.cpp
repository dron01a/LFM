#include "operations.h"
#include "settings.h"
#include "localization.h"
#include "output.h"
#include <iostream>

using namespace FSTool;

enum _command{
    _createFile = 0,
    _createFolder,
    _remove,
    _move,
    _rename,
    _info,
    _help,
    _unK_COM
};

// return commnad
_command getCommnad(int argc, char **argv); 

// check count of arguments
bool countArgsCheck( message & _result, int count, int firstLim, int lastLim = 0);

int main(int argc, char **argv){
    std::string homeDir = std::getenv("HOME");                // home dir
    std::string configPath = homeDir + "/.liza/config.txt";   // path to config 
    std::string logPath = homeDir + "/.liza/log.txt";         // path to log 
    std::string localPath = homeDir + "/.liza/localization/"; // path to localization
    config config; 
    loadConfig(configPath,config);
    localPath += config.lang;
    message result;  // result of the program
    _command _command = getCommnad(argc,argv); // get curient comand
    switch(_command){
        case _help: // get info of commands
            if(config.mode != "log"){
                result.add("<HELP>");
            }
            break;
        case _createFile:
            if(countArgsCheck(result,argc,3)){
                for(int i = 2; i < argc; i++){
                    create("<FILE>", argv[i], result);
                }
            }
            break;
        case _createFolder:
            if(countArgsCheck(result,argc,3)){
                for(int i = 2; i < argc; i++){
                    create("<FOLDER>", argv[i], result); 
                }
            }
            break;
        case _remove:
            if(countArgsCheck(result,argc,3)){
                for(int i = 2; i < argc; i++){
                    destroy(argv[i],result); // destroy objects 
                }
            }
            break;
        case _rename:
            if(countArgsCheck(result,argc,4,4)){
                rename(argv[2],argv[3],result); // rename object
            }
            break;
        case _move:
            printf("move\n");
            if(countArgsCheck(result,argc,4,4)){
                printf("move\n");
                move(argv[2],argv[3],result); // move object
            }
            break;
        case _info:
            if(countArgsCheck(result,argc,3) && config.mode != "log"){
                for(int i = 2; i < argc; i++){
                    information(argv[i],result); // return information of files
                }
            }
            break;
        default:
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

_command getCommnad(int argc, char **argv){
    if(strcmp(argv[1],"mfl") == 0){
        return _createFile;
    }
    else if(strcmp(argv[1],"mdr") == 0){
        return _createFolder;
    }
    else if(strcmp(argv[1],"move") == 0){
        return _move;
    }
    else if( strcmp(argv[1],"rfl") == 0 || 
        strcmp(argv[1],"rdr") == 0 || 
        strcmp(argv[1],"remove") == 0 ){
        return _remove;
    }
    else if (strcmp(argv[1],"rename") == 0){
        return _rename;
    }
    else if(strcmp(argv[1],"info") == 0){
        return _info;
    }
    else if(strcmp(argv[1],"help") == 0){
        return _help;
    }
    else{
        return _unK_COM;
    }
}

bool countArgsCheck(message & _result, int count, int firstLim, int lastLim){
    if(count < firstLim || (count > lastLim && lastLim != 0)){
        _result.add("<WRONG_ARGS>"); // if bad args 
        return false;
    }
    return true;
}