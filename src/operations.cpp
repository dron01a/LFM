#include "operations.h"

using namespace FSTool;

void create(std::string type, std::string name, logger &result){
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

void destroy(std::string type, std::string name, logger &result){
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

void move(std::string name, std::string path, logger &result){
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

void destroy(std::string name, logger &result){
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

void information(std::string name, logger &result){
    if(is_file(name)){
        file * temp = new file(name);
        result.add("File information: " + temp->full_name());
        result.add("size:" + std::to_string(temp->size()) + " bytes");
        result.add("last modification:" + std::to_string(temp->last_modification()->tm_mday) + ":" 
            + std::to_string(temp->last_modification()->tm_mon) + ":" + std::to_string(temp->last_modification()->tm_year) + "\t" 
            + std::to_string(temp->last_modification()->tm_hour) + ":" + std::to_string(temp->last_modification()->tm_min) + ":"
            + std::to_string(temp->last_modification()->tm_sec));
        delete temp;
    }
    else if(is_folder(name)){
        folder * temp = new folder(name);
        result.add("File information: " + temp->full_name());
        result.add("size:" + std::to_string(temp->size()) + " bytes");
        result.add("subdirs:" + std::to_string(temp->folders())); 
        result.add("files:" + std::to_string(temp->files()));
        result.add("total:" + std::to_string(temp->elements()));
        result.add("last modification:" + std::to_string(temp->last_modification()->tm_mday) + ":" 
            + std::to_string(temp->last_modification()->tm_mon) + ":" + std::to_string(temp->last_modification()->tm_year) + "\t"  
            + std::to_string(temp->last_modification()->tm_hour) + ":" + std::to_string(temp->last_modification()->tm_min) + ":"
            + std::to_string(temp->last_modification()->tm_sec));
        delete temp;
    }
    else {
        result.add("object not found");
    }
}

void rename(std::string oldName, std::string newName, logger &result){
    int *res = new int(rename(oldName.c_str(), newName.c_str()));
    if(*res != 0){
        if(*res == ENOENT){
            result.add("liza > \"" + oldName + "\" not found");
        }
        else{
            result.add("liza > renaming error");
        }
    }
    else{
        result.add("liza > \"" + oldName + "\" renamed to \"" + newName + "\"");
    }
    delete res;
}