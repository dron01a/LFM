#include "operations.h"
#include "message.h"

using namespace FSTool;

int main(int argc, char **argv){
    message resultMessage;  // message with the result of the program
    if (strcmp(argv[1],"help") == 0){
        resultMessage.set_text("Help:");
        resultMessage.add("mfl -> make file in work directory");
        resultMessage.add("\tExample: liza mfl test.cpp");
        resultMessage.add("mdr -> make folder in work directory");
        resultMessage.add("\tExample: liza mdr test_folder");
        resultMessage.add("rfl -> delete file in work directory");
        resultMessage.add("\tExample: liza rfl test.cpp");
        resultMessage.add("rdr -> delete folder in work directory");
        resultMessage.add("\tExample: liza rdr test_folder");
        resultMessage.add("remove -> delete folder/file in work directory");
        resultMessage.add("\tExample: liza remove test_folder");
        resultMessage.add("info -> print info of folder/file");
        resultMessage.add("\tExample: liza info test.cpp");
        resultMessage.add("move -> moves folder/file along the specified path");
        resultMessage.add("\tExample: liza move test.cpp test_folder");
    }
    else if (argv[1][0] == 'm'){
        if(argc < 2){
            resultMessage.set_text("wrong number of args");
        }
        else{
            if(strcmp(argv[1],"mfl") == 0){
                for(int i = 2; i < argc; i++){
                    create("file", argv[i],resultMessage);
                }
            }
            if (strcmp(argv[1],"mdr") == 0){
                for(int i = 2; i < argc; i++){
                    create("folder", argv[i],resultMessage);
                }
            }
            if (strcmp(argv[1],"move") == 0){
                if(argc < 4 || argc > 4 ){
                    resultMessage.set_text("wrong number of args");
                }
                move(argv[2],argv[3],resultMessage);
            }
        }
    }
    else if (argv[1][0] == 'r'){
        if(argc < 3){
            resultMessage.set_text("wrong number of args");
        }    
        else{
            if(strcmp(argv[1],"rfl") == 0){
                for(int i = 2; i < argc; i++){
                    destroy("file", argv[i],resultMessage);
                }
            }   
            if (strcmp(argv[1],"rdr") == 0){
                for(int i = 2; i < argc; i++){
                    destroy("folder", argv[i],resultMessage);
                }
            }
            if (strcmp(argv[1],"remove") == 0){
                for(int i = 2; i < argc; i++){
                    destroy(argv[i],resultMessage);
                }
            }
        }
    }
    else if(strcmp(argv[1],"info") == 0){
        information(argv[2],resultMessage);
    }
    else{
       resultMessage.set_text("Liza > unknown command,please call \"help\" to view the list of commands");
    }
    printMessage(resultMessage);
    return 0;
}

