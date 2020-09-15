#include "FSTool/file.h"
#include "FSTool/folder.h"
#include "WPTool/string_content.h"
#include "message.h"

using namespace FSTool;
using namespace WPTool;

std::string lang_file_path;

static inline void load_settings();
static inline void load_language(std::string language);

int main(int argc, char **argv){
    if(argc < 2){
        return 0; // if programm havent argv
    }
    else if(strcmp(argv[1],"mfl") == 0){
        
    }
    else if(strcmp(argv[1],"mdr") == 0){

    }
    else if(strcmp(argv[1],"info") == 0){

    }
    else if(strcmp(argv[1],"delete") == 0){
        
    }
    return 0;
}

static inline void load_settings(){
    if(folder("./settings/").exists()){
        // ...
    }
    else{
        file *config = new file("./settings/config.txt"); // for file config.txt
        if(config->exists()){  // set default settings
            config->add("lang: rus");
            config->add("message text color: 01m");
            config->add("message border color: 30m");
            config->add("bc color: black");
        }
        string_content lang(config->get(0), ": "); // load info for language 
        load_language(lang[1]); // load language 
    }
}

static inline void load_language(std::string language){
    lang_file_path = "./language/" + language + ".txt";
    file * lan = new file(lang_file_path); // temp file to check 
    if (lan->exists()){
        message * error_mes = new message;
        error_mes->set("LiZA > not found settings file");
        return_message(*error_mes); // return message of not found
        delete error_mes;
    }
    delete lan;
