#include "FSTool/file.h"
#include "FSTool/folder.h"
#include "FSTool/FSTool.h"

#include <iostream>

using namespace FSTool;

bool find(std::string type, std::string name);   // find file/folder
void create(std::string type, std::string name); // create folder/file
void destroy(std::string name);                  // destroy folder/file

int main(int argc, char **argv){
    if(argc < 0){
        return 0; // if programm havent argv
    }
    else if (argv[1][0] == 'm'){
        try{
            if(strcmp(argv[1],"mfl") == 0){
                create("file", argv[2]);
            }
            else if (strcmp(argv[1],"mdr") == 0){
                create("folder", argv[2]);
            }
            else{
                throw "Liza > unknown command";
            }
        }
        catch(std::string _err){
            std::cout << _err << std::endl;
        }
    }
    else if(strcmp(argv[1],"info") == 0){ 
        if(is_file(argv[2])){
            file * temp = new file(argv[2]);
            std::cout << "File information:\n";
            std::cout << temp->get_info().full_name << std::endl;
            std::cout << "name: "<<temp->get_info().name << std::endl;
            std::cout << "path: "<<temp->get_info().path << std::endl;
            std::cout << "type: " <<temp->get_info().type << std::endl;
            std::cout << "size: " <<temp->get_info().size << " bytes" << std::endl;
            std::cout << "last modification: " <<temp->get_info().lm_day << ":" << temp->get_info().lm_month <<":" 
                << temp->get_info().lm_year << " " << temp->get_info().lm_hour << ":"
                << temp->get_info().lm_min << ":" << temp->get_info().lm_sec << std::endl;
            delete temp;
        }
        if(is_folder(argv[2])){
            folder * temp = new folder(argv[2]);
            std::cout << "File information:\n";
            std::cout << temp->get_info().full_name << std::endl;
            std::cout << "name: "<<temp->get_info().name << std::endl;
            std::cout << "path: "<<temp->get_info().path << std::endl;
            std::cout << "size: " <<temp->get_info().size << " bytes" << std::endl;
            std::cout << "subdirs: " << temp->get_info().folders << std::endl;
            std::cout << "files: " << temp->get_info().files << std::endl;
            std::cout << "total: " << temp->get_info().elements << std::endl;
            std::cout << "last modification: " <<temp->get_info().lm_day << ":" << temp->get_info().lm_month <<":" 
                << temp->get_info().lm_year << " " << temp->get_info().lm_hour << ":"
                << temp->get_info().lm_min << ":" << temp->get_info().lm_sec << std::endl;
            delete temp;
        }
    }
    else if(strcmp(argv[1],"rfl") == 0){
        try{
            if(argc < 3){
                throw "wrong number of arguments";
            }
            if(!file(argv[2]).exists()){
                std::cout << "liza > folder \""<< argv[2] <<"\" not found\n";
            }
            else{
                file(argv[2]).destroy(); // delete file
                std::cout << "liza > file \""<< argv[2] <<"\" deleted\n";
            }
        }
        catch(std::string _text){
            std::cout << "liza > " << _text << std::endl; // return error message
        }
    }
    else if(strcmp(argv[1],"rdr") == 0){
        file(argv[2]).destroy(); // delete file
        try{
            if(!folder(argv[2]).exists()){
                std::cout << "liza > folder \""<< argv[2] <<"\" not found\n";
            }
            else{
                folder(argv[2]).destroy(); // delete file
                std::cout << "liza > folder \""<< argv[2] <<"\" deleted\n";
            }
        }
        catch(std::string _text){
            std::cout << "liza > " << _text << std::endl; // return error message
        }
    }
    else{
        std::cout << "Liza > unknown command\n";
    }
    return 0;
}

bool find(std::string type, std::string name){
    if(type == "fl"){
         return file(name).exists();      
    }
    if(type == "dr"){
        return folder(name).exists();
    }
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
        std::cout << "liza > "<< type << " \""<< name <<"\" already exists\n";
    }else{
        if(temp->create() == 0){
            std::cout << "liza > "<< type << " \""<< name <<"\" created\n";
        }
        else{
            throw "liza > " + type + " creation error";
            delete temp;
        }
    }
    delete temp;
}



