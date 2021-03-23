#include "settings.h"

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

