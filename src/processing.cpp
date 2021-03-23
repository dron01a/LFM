#include "processing.h"

_command getCommnad(std::string commandName){
    if(commandName == "mfl"){
        return _createFile;
    }
    else if(commandName == "mdr"){
        return _createFolder;
    }
    else if(commandName == "move"){
        return _move;
    }
    else if(commandName == "copy"){
        return _copy;
    }
    else if(commandName == "rfl" || commandName == "rdr" || commandName == "remove"){
        return _remove;
    }
    else if (commandName == "rename"){
        return _rename;
    }
    else if(commandName == "info"){
        return _info;
    }
    else if(commandName == "help"){
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

void loopFunc(contrlFunc func, message & result, strvect& argv, int firstLim, int lastLim){
    if(countArgsCheck(result,argv.size(),firstLim,lastLim)){
        for(int count = 2; count < argv.size() - 1; count++){
            func(argv[count], argv[argv.size() - 1] , result); // run func
        }
    }
}

void loopFunc(lowFunc func, message & result, strvect & argv, int firstLim, int lastLim ){
    if(countArgsCheck(result,argv.size(),firstLim,lastLim)){
        for(int count = 2; count < argv.size(); count++){
            func(argv[count], result); // run func
        }
    }
}


void commandExexc( message & result, config & config ,strvect & argv){
    _command _command = getCommnad(argv[1]); // get curient comand
    switch(_command){
        case _help: // get info of commands
            if(config.mode != "log"){
                result.add("<HELP>");
            }
            break;
        case _createFile:
            argv.push_back("<FILE>");
            loopFunc(create, result , argv, 4);
            break;
        case _createFolder:
            argv.push_back("<FOLDER>");
            loopFunc(create, result , argv, 4);
            break;
        case _remove:
            loopFunc(destroy, result , argv, 3);
            break;
        case _rename:
            loopFunc(rename, result, argv, 4, 4);
            break;
        case _move:
            loopFunc(move, result , argv, 4);
            break;
        case _copy:
            loopFunc(copy, result , argv, 4);
            break;
        case _info:
            loopFunc(information, result , argv, 3);
            break;
        default:
            if(config.mode != "log"){
                result.add("<NON_COMMAND>");
            }
            break;
    }
}