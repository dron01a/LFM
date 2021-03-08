#include "localization.h"

std::string localization(std::string locFile, std::string text){
    file locXML(locFile);
    XML * loc = loadXML(locXML.buff()); 
    std::string result; 
    int found = 0; // element with <TAG>
    string_content message(text," \t\n");
    for (int i = 0; i < message.size(); i++){
        if(message[i].find("<") != std::string::npos && message[i].find(">") != std::string::npos){
            std::string tag = message[i];
            tag = tag.substr(tag.find("<") + 1, tag.find(">") - tag.find("<") -1);
            std::string tagText = loc->getTAG(tag).value;
            message.edit(i,tagText); // replase tag from tag text
        }
    }
    result = message.string();
    return result;
}