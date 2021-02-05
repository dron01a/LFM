#include "settings.h"

logger::logger(std::string logFile){
    this->logFile = new file(logFile); 
    if(!this->logFile->exists()){
        this->logFile->create(); // create file to write information
    }
}

logger::~logger(){
    if(_mode == "display"){
        printf("%s\n", _text.c_str()); 
    }
    time_t now = time(0);
    struct tm logTime;
    char buf[80];
    char timeFormat[_format.size()];
    logTime = *localtime(&now);
    strcpy(timeFormat,_format.c_str());
    strftime(buf, sizeof(buf), timeFormat, &logTime);
    logFile->add(buf); 
    logFile->add(_args); // add user input to file
    logFile->add(_text + "\n"); // add iformation to file
    delete logFile;
}

std::string logger::mode(){
    return _mode;
}

void logger::add(int argc, char **argv){
    for(int i = 0; i < argc; i++){
        _args += argv[i];
        _args += " ";
    }
}

void logger::loadSettings(config config){
    _mode = config.mode;     // set output mode
    _format = config.format; // set datatime format  
}

std::string logger::text(){
    return _text;
}

void logger::setText(std::string text){
    _text = text;
}

void logger::add(std::string text){
    if(_text.size() == 0){
        _text = text;
    }
    else{
        _text += "\n" + text;
    } 
}

void checkConfig(std::string filename){
    if(!exists(filename)){
        throw "file with config not found!"; // if file not exists
    }
    if(is_file(filename)){
        file confFile(filename);
        if(confFile.empty()){ // it is impossible to get data from an empty file
            throw "bad config"; 
        }
    }
}

void loadConfig(std::string filename, config & _config){
    file confFile(filename); // file with config 
    string_content confLine(confFile.buff(),":;\n");
    for(int count = 0; count < confLine.size(); count+=2){  // load params
        if(confLine[count] == "language"){
            _config.lang = confLine[count+1];
        }
        if(confLine[count] == "mode"){
            _config.mode = confLine[count+1];
        }
        if(confLine[count] == "format"){
            _config.format = confLine[count+1];
        }        
    }
}

