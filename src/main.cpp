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
_command getCommnad(char *arg); 

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
    _command _command = getCommnad(argv[1]); // get curient comand
    switch(_command){
        case _help: // get info of commands
            if(config.mode != "log"){
                result.add("<HELP>");
            }
            break;
        case _createFile:
            if(countArgsCheck(result,argc,3)){
                for(int count = 2; count < argc; count++){
                    create("<FILE>", argv[count], result);
                }
            }
            break;
        case _createFolder:
            if(countArgsCheck(result,argc,3)){
                for(int count = 2; count < argc; count++){
                    create("<FOLDER>", argv[count], result); 
                }
            }
            break;
        case _remove:
            if(countArgsCheck(result,argc,3)){
                for(int count = 2; count < argc; count++){
                    destroy(argv[count],result); // destroy objects 
                }
            }
            break;
        case _rename:
            if(countArgsCheck(result,argc,4,4)){
                rename(argv[2],argv[3],result); // rename object
            }
            break;
        case _move:
            if(countArgsCheck(result,argc,4)){
                for(int count = 2; count < argc - 1; count++){
                    move(argv[count],argv[argc-1],result); // move object
                }
            }
            break;
        case _info:
            if(countArgsCheck(result,argc,3) && config.mode != "log"){
                for(int count = 2; count < argc; count++){
                    information(argv[count],result); // return information of files
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

_command getCommnad(char *arg){
    if(strcmp(arg,"mfl") == 0){
        return _createFile;
    }
    else if(strcmp(arg,"mdr") == 0){
        return _createFolder;
    }
    else if(strcmp(arg,"move") == 0){
        return _move;
    }
    else if( strcmp(arg,"rfl") == 0 || 
        strcmp(arg,"rdr") == 0 || 
        strcmp(arg,"remove") == 0 ){
        return _remove;
    }
    else if (strcmp(arg,"rename") == 0){
        return _rename;
    }
    else if(strcmp(arg,"info") == 0){
        return _info;
    }
    else if(strcmp(arg,"help") == 0){
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