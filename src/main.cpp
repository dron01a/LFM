#include "FSTool/file control.h"
#include "iostream"

using namespace file_control;

int main(int argc, char **argv){
    if(argc < 2){
        return 0; // if programm havent argv
    }
    if( strcmp(argv[1],"mfl") == 0){
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
        }
        catch(const char* error){
            std::cout << "liza: error >> " << error << std::endl; // message 
        }
    }
    return 0;
}