#include "operations.h"

using namespace FSTool;

void create(std::string type, std::string name, message &result){
    FST_object *temp; // temp object
    if(type == "<FILE>"){
        temp = new file(name); 
    }
    if(type == "<FOLDER>"){
        temp = new folder(name); 
    }
    if(temp->exists()){ 
        result.add("liza > "+ type + " \"" + name +"\" <EXISTS>");
    }
    else{
        if(temp->create() == 0){
            result.add("liza > " + type + " \"" + name + "\" <CREATED>");
        }
        else{
            result.add("liza > " + type + " <C_ERROR>");
            delete temp;
        }
    }
    delete temp;
}

void destroy(std::string type, std::string name, message &result){
    FST_object *temp; // temp object
    if(type == "<FILE>"){
        temp = new file(name); 
    }
    if(type == "<FOLDER>"){
        temp = new folder(name); 
    }
    if(!temp->exists()){ 
        result.add("liza > "+ type + " \"" + name +"\" <NOT_FOUND>");
    }
    else{
        temp->destroy(); // delete 
        result.add("liza > " + type + " \"" + name +"\" <DELETED>");
    }
    delete temp; // free memory
}

void move(std::string name, std::string path, message &result){
    FST_object *temp; // temp object
    if(is_file(name)){
        temp = new file(name); 
    }
    if(is_folder(name)){
        temp = new folder(name); 
    }
    if(!temp->exists()){         
        result.add("liza > \"" + name + "\" <NOT_FOUND>");
    }
    else{
        temp->move(path); // moving 
        result.add("liza > \"" + name +"\" <MOVE> \"" + path +"\"");
    }
    delete temp; // free memory
}

void destroy(std::string name, message &result){
    FST_object *temp; // base class 
    if(is_file(name)){ 
        temp = new file(name);  //if is file
    }
    else if(is_folder(name)){
        temp = new folder(name); //if is folder
    }
    else {
        result.add("liza > \"" + name +"\" <NOT_FOUND>");
        return;
    }
    temp->destroy(); // delete object 
    result.add("liza > \"" + name +"\" <DELETED>");
    delete temp; // free memory
}

void information(std::string name, message &result){
    if(is_file(name)){
        file * temp = new file(name);
        result.add("<FILE_INFO>: " + temp->full_name());
        result.add("<SIZE>: " + std::to_string(temp->size()) + " <BYTES>");
        result.add("<L_MOD>: " + std::to_string(temp->last_modification()->tm_mday) + ":" 
            + std::to_string(temp->last_modification()->tm_mon) + ":" + std::to_string(temp->last_modification()->tm_year) + "\t" 
            + std::to_string(temp->last_modification()->tm_hour) + ":" + std::to_string(temp->last_modification()->tm_min) + ":"
            + std::to_string(temp->last_modification()->tm_sec));
        delete temp;
    }
    else if(is_folder(name)){
        folder * temp = new folder(name);
        result.add("<FILE_INFO>: " + temp->full_name());
        result.add("<SIZE>: " + std::to_string(temp->size()) + " <BYTES>");
        result.add("<SUB_DR>: " + std::to_string(temp->folders())); 
        result.add("<FILES>: " + std::to_string(temp->files()));
        result.add("<TOTAL_FL>: " + std::to_string(temp->elements()));
        result.add("<L_MOD>: " + std::to_string(temp->last_modification()->tm_mday) + ":" 
            + std::to_string(temp->last_modification()->tm_mon) + ":" + std::to_string(temp->last_modification()->tm_year) + "\t"  
            + std::to_string(temp->last_modification()->tm_hour) + ":" + std::to_string(temp->last_modification()->tm_min) + ":"
            + std::to_string(temp->last_modification()->tm_sec));
        delete temp;
    }
    else {
        result.add(name + " <NOT_FOUND>");
    }
}

void rename(std::string oldName, std::string newName, message &result){
    int *res = new int(rename(oldName.c_str(), newName.c_str()));
    if(*res != 0){
        if(*res == ENOENT){
            result.add("liza > \"" + oldName + "\" <NOT_FOUND>");
        }
        else{
            result.add("liza > <RENAME_ERROR>");
        }
    }
    else{
        result.add("liza > \"" + oldName + "\" <RENAME> \"" + newName + "\"");
    }
    delete res;
}