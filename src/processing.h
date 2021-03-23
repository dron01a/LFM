#ifndef __COMMAND_PROC__H__
#define __COMMAND_PROC__H__

#include "output.h"
#include "operations.h"
#include "settings.h"

typedef void (*contrlFunc)(std::string, std::string, message&); // for move, create, rename
typedef void (*lowFunc)(std::string,message&); // for destroy , information

// enum with commands
enum _command{
    _createFile = 0,
    _createFolder,
    _remove,
    _move,
    _rename,
    _info,
    _help,
    _cc_COM,
    _unK_COM
};

// return commnad
_command getCommnad(std::string commandName);

// check count of arguments
bool countArgsCheck( message & _result, int count, int firstLim, int lastLim = 0);

// run func from operations,h in loop 
void loopFunc(contrlFunc func, message & result, strvect & argv, int firstLim, int lastLim = 0);
void loopFunc(lowFunc func, message & result, strvect & argv, int firstLim, int lastLim = 0);

// execution of standard commands
void commandExexc( message & _result, config & config, strvect & argv); 

#endif