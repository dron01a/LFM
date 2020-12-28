#include "operations.h"

using namespace FSTool;

void create(std::string type, std::string name, message &result){
    _base *temp; // temp object
    if(type == "file"){
        temp = new file(name); 
    }
    if(type == "folder"){
        temp = new folder(name); 
    }
    if(temp->exists()){ 
        result.add("liza > "+ type + " \"" + name +"\" already exists");
    }
    else{
        if(temp->create() == 0){
            result.add("liza > " + type + " \"" + name + "\" created");
        }
        else{
            result.add("liza > " + type + " creation error");
            delete temp;
        }
    }
    delete temp;
}

void destroy(std::string type, std::string name, message &result){
    _base *temp; // temp object
    if(type == "file"){
        temp = new file(name); 
    }
    if(type == "folder"){
        temp = new folder(name); 
    }
    if(!temp->exists()){ 
        result.add("liza > "+ type + " \"" + name +"\" ot found");
    }
    else{
        temp->destroy(); // delete 
        result.add("liza > " + type + " \"" + name +"\" deleted");
    }
    delete temp; // free memory
}

void move(std::string name, std::string path, message &result){
    _base *temp; // temp object
    if(is_file(name)){
        temp = new file(name); 
    }
    if(is_folder(name)){
        temp = new folder(name); 
    }
    if(!temp->exists()){         
        result.add("liza > \"" + name + "\" not found");
    }
    else{
        temp->move(path); // moving 
        result.add("liza > \"" + name +"\" moved to \"" + path +"\"");
    }
    delete temp; // free memory
}

void destroy(std::string name, message &result){
    _base *temp; // base class 
    if(is_file(name)){ 
        temp = new file(name);  //if is file
    }
    else if(is_folder(name)){
        temp = new folder(name); //if is folder
    }
    else {
        result.add("liza > \"" + name +"\" ot found");
        return;
    }
    temp->destroy(); // delete object 
    result.add("liza > \"" + name +"\" deleted");
    delete temp; // free memory
}

void information(std::string name, message &result){
    if(is_file(name)){
            file * temp = new file(name);
            result.set_text("File information: " + temp->get_info().full_name);
            result.add("size:" + std::to_string(temp->get_info().size) + " bytes");
            result.add("last modification:" + std::to_string(temp->get_info().lm_day) + ":" 
                + std::to_string(temp->get_info().lm_month) + ":" + std::to_string(temp->get_info().lm_year) + ":" 
                + std::to_string(temp->get_info().lm_hour) + ":" + std::to_string(temp->get_info().lm_min) + ":"
                + std::to_string(temp->get_info().lm_sec));
            delete temp;
        }
        else if(is_folder(name)){
            folder * temp = new folder(name);
            result.set_text("File information: " + temp->get_info().full_name);
            result.add("size:" + std::to_string(temp->get_info().size) + " bytes");
            result.add("subdirs:" + std::to_string(temp->get_info().folders)); 
            result.add("files:" + std::to_string(temp->get_info().files));
            result.add("total:" + std::to_string(temp->get_info().elements));
            result.add("last modification:" + std::to_string(temp->get_info().lm_day) + ":" 
                + std::to_string(temp->get_info().lm_month) + ":" + std::to_string(temp->get_info().lm_year) + ":" 
                + std::to_string(temp->get_info().lm_hour) + ":" + std::to_string(temp->get_info().lm_min) + ":"
                + std::to_string(temp->get_info().lm_sec));
            delete temp;
        }
        else {
            result.set_text("object not found");
        }
}