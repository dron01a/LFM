#include "localization.h"

std::string localization(std::string locFile, std::string text){
    std::string result; 
    int found = 0; // element with <TAG>
    file loc(locFile); // file with translation
    string_content message(text," ");
    found = message.find("<");
    while(found != -1){
        std::string tag = message.get(found); // get name of tag
        std::string tagText;
        int beginTAG = loc.find(tag);
        tag.insert(1,"/");
        int endTAG = loc.find(tag);
        for (int count = beginTAG + 1; count < endTAG; count++){
            tagText += loc.get(count); // add text to translation
        }
        message.edit(found,tagText); // replase tag from tag text
        found = message.find("<");
    }
    result = message.string();
    return result;
}