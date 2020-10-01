#include "FSTool/file.h"
#include "FSTool/folder.h"
#include "FSTool/FSTool.h"

#include <iostream>

using namespace FSTool;

int main(int argc, char **argv){
    if(argc < 1){
        return 0; // if programm havent argv
    }
    else if(strcmp(argv[1],"mfl") == 0){
        try{
            if(argc < 2 || argc > 5){
                throw "wrong number of arguments";
            }
            else if( argc == 3 ){
                file *temp = new file(argv[2]); // temp object
                if(temp->exists()){ 
                    std::cout << "liza > file \""<< argv[2] <<"\" already exists\n";
                }
                else{
                    if(temp->create() == 0){
                        std::cout << "liza > file \""<< argv[2] <<"\" created\n";
                    }
                    else{
                        throw "liza > file creation error\n";
                    }
                }
                delete temp;
            }
            else if(argc == 4){
                folder *tmp_dir = new folder(argv[2]);   // temp object for folder
                file *temp = new file(argv[3], argv[2]); // temp object for file
                if(!tmp_dir->exists()){
                    throw "folder not found\n";
                }
                else{
                    if(temp->exists()){ 
                        std::cout << "liza > file \""<< argv[3] <<"\" already exists\n";
                    }
                    else{
                        if(temp->create() == 0){
                            std::cout << "liza > file \""<< argv[3] <<"\" created\n";
                        }
                        else{
                            throw "liza > file creation error\n";
                        }
                    }
                }
                delete tmp_dir;
                delete temp;
            }
        }
        catch(std::string _text){
            std::cout << "liza > " << _text << std::endl; // return error message
        }
    }
    else if(strcmp(argv[1],"mdr") == 0){
        try{
            if(argc < 2 || argc > 5){
                throw "wrong number of arguments";
            }
            else if(argc == 3){
                folder *temp = new folder(argv[2]); // temp object
                if(temp->exists()){
                    std::cout << "liza > folder \""<< argv[2] <<"\" already exists\n";
                }
                else{
                    temp->create(); // create folder
                    std::cout << "liza > folder \""<< argv[2] <<"\" created\n";
                } 
                delete temp;
            }          
        }
        catch(std::string _text){
            std::cout << "liza > " << _text << std::endl; // return error message
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
            std::cout << "size: " <<temp->get_info().size << "bytes" << std::endl;
            std::cout << "last modification: " <<temp->get_info().lm_day << ":" << temp->get_info().lm_month <<":" 
                << temp->get_info().lm_year << " " << temp->get_info().lm_hour 
                << temp->get_info().lm_min << temp->get_info().lm_sec << std::endl;
            delete temp;
        }
        if(is_folder(argv[2])){
            folder * temp = new folder(argv[2]);
            std::cout << "File information:\n";
            std::cout << temp->get_info().full_name << std::endl;
            std::cout << "name: "<<temp->get_info().name << std::endl;
            std::cout << "path: "<<temp->get_info().path << std::endl;
            std::cout << "size: " <<temp->get_info().size << "bytes" << std::endl;
            std::cout << "subdirs: " << temp->get_info().folders << std::endl;
            std::cout << "files: " << temp->get_info().files << std::endl;
            std::cout << "total: " << temp->get_info().elements << std::endl;
            std::cout << "last modification: " <<temp->get_info().lm_day << ":" << temp->get_info().lm_month <<":" 
                << temp->get_info().lm_year << " " << temp->get_info().lm_hour 
                << temp->get_info().lm_min << temp->get_info().lm_sec << std::endl;
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