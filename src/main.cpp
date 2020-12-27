#include "FSTool/FSTool.h"

#include <iostream>

using namespace FSTool;

void create(std::string type, std::string name);    // create folder/file
void destroy(std::string type, std::string name);   // destroy folder/file
void destroy(std::string name);                     // destroy folder/file
void move(std::string name, std::string path);      // move folde/file

int main(int argc, char **argv){
    if(argc == 1){
        return 0; // if programm havent argv
    }
    else if (strcmp(argv[1],"help") == 0){
        printf("%s\n\t%s\n","mfl -> make file in work directory","Example: liza mfl test.cpp");
        printf("%s\n\t%s\n","mdr -> make folder in work directory","Example: liza mdr test_folder");
        printf("%s\n\t%s\n","rfl -> delete file in work directory","Example: liza rfl test.cpp");
        printf("%s\n\t%s\n","rdr -> delete folder in work directory","Example: liza rdr test_folder");
        printf("%s\n\t%s\n","remove -> delete folder/file in work directory","Example: liza remove test_folder");
        printf("%s\n\t%s\n","info -> print info of folder/file","Example: liza info test.cpp");
        printf("%s\n\t%s\n","move -> moves folder/file along the specified path","Example: liza move test.cpp test_folder");
    }
    else if (argv[1][0] == 'm'){
        if(argc < 2){
            printf("%s/n","wrong number of args");
        }
        else{
            if(strcmp(argv[1],"mfl") == 0){
                for(int i = 2; i < argc; i++){
                    create("file", argv[i]);
                }
            }
            if (strcmp(argv[1],"mdr") == 0){
                for(int i = 2; i < argc; i++){
                    create("folder", argv[i]);
                }
            }
            if (strcmp(argv[1],"move") == 0){
                if(argc < 4 || argc > 4 ){
                    printf("%s/n","wrong number of args");
                }
                move(argv[2],argv[3]);
            }
        }
    }
    else if (argv[1][0] == 'r'){
        if(argc < 3){
            printf("%s/n","wrong number of args");
        }    
        else{
            if(strcmp(argv[1],"rfl") == 0){
                for(int i = 2; i < argc; i++){
                    destroy("file", argv[i]);
                }
            }   
            if (strcmp(argv[1],"rdr") == 0){
                for(int i = 2; i < argc; i++){
                    destroy("folder", argv[i]);
                }
            }
            if (strcmp(argv[1],"remove") == 0){
                for(int i = 2; i < argc; i++){
                    destroy(argv[i]);
            }
        }
    }
    }
    else if(strcmp(argv[1],"info") == 0){ 
        if(is_file(argv[2])){
            file * temp = new file(argv[2]);
            printf("File information:\n%s\nsize:%i bytes\n",temp->get_info().full_name.c_str(),temp->get_info().size);
            printf("last modification: %i:%i:%i:%i:%i:%i\n",temp->get_info().lm_day,
                temp->get_info().lm_month,temp->get_info().lm_year,temp->get_info().lm_hour,
                temp->get_info().lm_min, temp->get_info().lm_sec);
            delete temp;
        }
        else if(is_folder(argv[2])){
            folder * temp = new folder(argv[2]);
            printf("File information:\n%s\nsize:%i bytes",temp->get_info().full_name,temp->get_info().size);
            printf("subdirs:%i\nfiles:%i\ntotal:%i\n",temp->get_info().folders,temp->get_info().files,temp->get_info().elements);
            printf("last modification:%i:%i:%i:%i:%i:%i\n",temp->get_info().lm_day,
                temp->get_info().lm_month,temp->get_info().lm_year,temp->get_info().lm_hour,
                temp->get_info().lm_min, temp->get_info().lm_sec);
            delete temp;
        }
        else {
            printf("%s\n","object not found");
        }
    }
    else{
        printf("%s\n","Liza > unknown command,please call \"help\" to view the list of commands");
    }
    return 0;
}

void create(std::string type, std::string name){
    _base *temp; // temp object
    if(type == "file"){
        temp = new file(name); 
    }
    if(type == "folder"){
        temp = new folder(name); 
    }
    if(temp->exists()){ 
        printf("%s\n",std::string("liza > "+ type + " \"" + name +"\" already exists").c_str());
    }else{
        if(temp->create() == 0){
            printf("%s\n",std::string("liza > " + type + " \"" + name + "\" created").c_str());
        }
        else{
            printf("%s\n",std::string("liza > " + type + " creation error").c_str());
            delete temp;
        }
    }
    delete temp;
}

void destroy(std::string type, std::string name){
    _base *temp; // temp object
    if(type == "file"){
        temp = new file(name); 
    }
    if(type == "folder"){
        temp = new folder(name); 
    }
    if(!temp->exists()){ 
        printf("%s\n",std::string("liza > " + type + " \"" + name +"\" not found").c_str());
    }
    else{
        temp->destroy(); // delete 
        printf("%s\n",std::string("liza > " + type + " \"" + name +"\" deleted").c_str());
    }
    delete temp; // free memory
}

void move(std::string name, std::string path){
    _base *temp; // temp object
    if(is_file(name)){
        temp = new file(name); 
    }
    if(is_folder(name)){
        temp = new folder(name); 
    }
    if(!temp->exists()){         
        printf("%s\n",std::string("liza > \"" + name + "\" not found").c_str());
    }
    else{
        temp->move(path); // moving 
        printf("%s\n",std::string("liza > \"" + name +"\" moved to \"" + path +"\"\n").c_str());
    }
    delete temp; // free memory
}

void destroy(std::string name){
    _base *temp; // base class 
    if(is_file(name)){ 
        temp = new file(name);  //if is file
    }
    else if(is_folder(name)){
        temp = new folder(name); //if is folder
    }
    else {
        printf("%s\n",std::string("liza > \"" + name + "\" not found").c_str());
        return;
    }
    temp->destroy(); // delete object 
    printf("%s\n",std::string("liza > \"" + name + "\" deleted").c_str());
    delete temp; // free memory
}