#include "operations.h"

using namespace FSTool;

void create(std::string name, std::string type, message &result){
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

void copy(std::string source, std::string dest, message &result){
    FST_object *tempDest; // temp dest object
    FST_object *tempSrc; // temp source object
    if(!exists(dest)){         
        result.add("liza > \"" + dest + "\" <NOT_FOUND>");
    }
    if(!exists(source)){         
        result.add("liza > \"" + source + "\" <NOT_FOUND>");
    }
    if(is_file(source)){
        tempSrc = new file(source); 
        if(is_file(dest)){
            tempDest = new file(dest); 
            tempDest->create();
            tempDest->copy(source); // copy
            result.add("liza > \"" + source +"\" <COPY> \"" + dest +"\"");
        }
        if(is_folder(dest)){
            tempDest = new file(tempSrc->name(), dest); 
            tempDest->create();
            tempDest->copy(source); // copy
            result.add("liza > \"" + source +"\" <COPY> \"" + dest +"\"");
        }
    }
    if(is_folder(source)){
        tempSrc = new folder(source); 
        if(is_file(dest)){
            tempDest = new file(dest); 
        } 
        if(is_folder(dest)){
            tempDest = new folder(tempSrc->name(), dest);
            tempDest->create();
            tempDest->copy(source); // copy
            result.add("liza > \"" + source +"\" <COPY> \"" + dest +"\"");
        }
    }
    delete tempSrc; // free memory
    delete tempDest;
}