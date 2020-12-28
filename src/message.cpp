#include "message.h"

message::message(std::string text){
    this->text = text; 
}

void message::set_text(std::string text){
    this->text = text;
}

std::string message::get_text(){
    return text;
}

void message::add(std::string text){
    this->text +="\n" + text;
}

void printMessage(message message){
    printf("%s\n", message.get_text().c_str());
}