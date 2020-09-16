#include "FSTool/file.h"
#include "FSTool/folder.h"

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
                        std::cout << "liza > file creation error\n";
                    }
                }
                delete temp;
            }
            else if(argc == 4){
                folder *tmp_dir = new folder(argv[2]);   // temp object for folder
                file *temp = new file(argv[2], argv[3]); // temp object for file
                if(!tmp_dir->exists()){
                    std::cout << "liza > folder not found\n";
                }
                else{
                    if(temp->exists()){ 
                        std::cout << "liza > file \""<< argv[3] <<"\" already exists\n";
                    }
                    else{
                        if(temp->create() == 0){
                            std::cout << "liza > file \""<< argv[2] <<"\" created\n";
                        }
                        else{
                            std::cout << "liza > file creation error\n";
                        }
                    }
                }
                delete tmp_dir;
                delete temp;
            }
        }
        catch(std::string _text){
            std::cout << "liza > " << _text << std::endl; 
        }
    }
    else if(strcmp(argv[1],"mdr") == 0){

    }
    else if(strcmp(argv[1],"info") == 0){

    }
    else if(strcmp(argv[1],"rfl") == 0){
        
    }
    else if(strcmp(argv[1],"rdl") == 0){
        
    }
    else{
        std::cout << "Liza > unknown command\n";
    }
    return 0;
}