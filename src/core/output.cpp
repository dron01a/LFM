#include "output.h"

void log( struct config conf , std::string filename , message & message ){
    file logFile(filename);
    if(!logFile.exists()){
        logFile.create();
        logFile.add("File with results of work \"Liza file manager\"");
    }
    time_t now = time(0);
    struct tm logTime;
    char buf[80];
    char timeFormat[conf.format.size()];
    logTime = *localtime(&now);
    strcpy(timeFormat,conf.format.c_str());
    strftime(buf, sizeof(buf), timeFormat, &logTime);
    logFile.add(buf); 
    logFile.add(message.text() + "\n"); // add iformation to file
}

std::string message::text(){
    return _text;
}

void message::setText(std::string text){
    _text = text;
}

void message::add(std::string text){
    if(_text.size() == 0){
        _text = text;
    }
    else{
        _text += "\n" + text;
    } 
}