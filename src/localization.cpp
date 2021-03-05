#include "localization.h"

std::string localization(std::string locFile, std::string text){
    std::string result; 
    int found = 0; // element with <TAG>
    file loc(locFile); // file with translation
    string_content message(text," \n");
    for (int i = 0; i < message.size(); i++){
        if(message[i].find("<") != std::string::npos && message[i].find(">") != std::string::npos){
            std::string tag = message[i];
            std::string tagText;
            int beginTAG = loc.find(tag);
            tag.insert(1,"/");
            int endTAG = loc.find(tag);
            for (int count = beginTAG + 1; count < endTAG; count++){
                tagText += loc.get(count); // add text to translation
            }
            message.edit(i,tagText); // replase tag from tag text
        }
    }
    result = message.string();
    return result;
}