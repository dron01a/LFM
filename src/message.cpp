#include "message.h"

std::string message::get_text_color(){
    return this->text_color;
}

void message::set_text_color(std::string color){
    text_color = "\033[" + color;
}

std::string message::get(){
    return this->mes;
}

void message::set(std::string text){
    mes = text;
}

void return_message(message mes){
    std::cout << mes.get_text_color() << mes.get() << "\033[00m" <<std::endl;
}

