#include "FSTool/file control.h"
#include "iostream"

using namespace file_control;

int main(int argc, char **argv){
    if(argc < 2){
        return 0; // if programm havent argv
    }
    if(strcmp(argv[1],"mfl") == 0){
        try{
            if( argc == 2 ){
                throw "file name not specified";
            }
            if( argc == 3 ){ 
                file * temp = new file(argv[2],"./"); // create file 
                delete temp;
                std::cout << "liza: file " << argv[2] << " created" << std::endl; // message  
            }
            if( argc == 4 ){
                if (!search(argv[2])){
                    throw "incorrect path";
                }else{
                    file * temp = new file(argv[3], argv[2]); // create file 
                    delete temp;
                    std::cout << "liza: file " << argv[3] << " created," 
                       << " in " << argv[2] << std::endl; // message
                }
            }
            if( argc > 4){
                throw "wrong number of argumants"; 
            }
        }
        catch(const char* error){
            std::cout << "liza: error >> " << error << std::endl; // message 
        }
    }
    if (strcmp(argv[1],"mdr") == 0){
        try{
            if( argc == 2 ){
                throw "folder name not specified";
            }
            if( argc == 3 ){ 
                folder * temp = new folder(argv[2],"./");
                if (!temp->verification() ){
                    temp->create();// create folder
                    std::cout << "liza: folder " << argv[2] << " created" << std::endl; // message 
                }
                else{
                    std::cout << "liza: folder " << argv[2] << " already exists" << std::endl; // message
                }
                delete temp; 
            }
            if( argc == 4 ){
                if (!search(argv[2])){
                    throw "incorrect path";
                }else{
                    folder *temp = new folder(argv[3], argv[2]);
                    if (!temp->verification()){
                        temp->create(); // create folder
                        std::cout << "liza: folder " << argv[3] << " created,"
                                  << " in " << argv[2] << std::endl; // message
                    }
                    else{
                        std::cout << "liza: folder " << argv[3] << " in " << argv[2] << " already exists" << std::endl; // message
                    }
                }
            }
            if( argc > 4){
                throw "wrong number of argumants"; 
            }
        }
        catch(const char* error){
            std::cout << "liza: error >> " << error << std::endl; // message 
        }
    }
    if (strcmp(argv[1],"info") == 0){
        try{
            if( argc == 2 ){
                throw "file(folder) name not specified"; // if args bad 
            }
            if( argc == 3 ){
                if(!search(argv[2])){
                        throw -1;
                }
                if(is_folder(argv[2])){ // if is folder                     
                    folder * temp = new folder(argv[2],"./" ); // temp object
                    std::cout <<"full name:\t" << temp->get_full_name() << std::endl;
                    std::cout <<"name:\t\t" << temp->get_name() << std::endl;
                    std::cout <<"path:\t\t" << temp->get_path() << std::endl;
                    std::cout <<"size:\t\t" << temp->get_size()<< " bytes" << std::endl;
                    std::cout <<"folders:\t" << temp->c_folders() << std::endl;
                    std::cout <<"files:\t\t" << temp->c_files() << std::endl;
                    std::cout <<"total:\t\t" << temp->c_elements() << std::endl;
                    delete temp; // free buff
                } 
                else{
                    file * temp = new file(argv[2],"./" ); // temp object
                    std::cout <<"full name:\t" << temp->get_full_name() << std::endl;
                    std::cout <<"name:\t\t" << temp->get_name() << std::endl;
                    std::cout <<"path:\t\t" << temp->get_path() << std::endl;
                    std::cout <<"size:\t\t" << temp->get_size()<< " bytes" << std::endl;
                    delete temp; // free buff
                }
            } 
        }
        catch(const char* error){
            std::cout << "liza: error >> " << error << std::endl; // message 
        }
        catch(int error){
            if(error -1){
                std::cout << "liza: error >> " << argv[2] << " not found\n";
            }
        }
    }
    return 0;
}