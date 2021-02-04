#include "operations.h"
#include "settings.h"

using namespace FSTool;

int main(int argc, char **argv){
    config config; 
    loadConfig("config.txt",config);
    logger * log= new logger("log.txt");  // result of the program
    log->setMode(config.mode);
    if(log->mode() == "log"){
        log->add(argc, argv);
    }
    if (strcmp(argv[1],"help") == 0){
        if(log->mode() != "log"){
            log->add("Help:");
            log->add("mfl -> make file in work directory");
            log->add("\tExample: liza mfl test.cpp");
            log->add("mdr -> make folder in work directory");
            log->add("\tExample: liza mdr test_folder");
            log->add("rfl -> delete file in work directory");
            log->add("\tExample: liza rfl test.cpp");
            log->add("rdr -> delete folder in work directory");
            log->add("\tExample: liza rdr test_folder");
            log->add("remove -> delete folder/file in work directory");
            log->add("\tExample: liza remove test_folder");
            log->add("info -> print info of folder/file");
            log->add("\tExample: liza info test.cpp");
            log->add("move -> moves folder/file along the specified path");
            log->add("\tExample: liza move test.cpp test_folder");
        }
    }
    else if (argv[1][0] == 'm'){
        if(argc < 2){
            log->add("wrong number of args");
        }
        else{
            if(strcmp(argv[1],"mfl") == 0){
                for(int i = 2; i < argc; i++){
                    create("file", argv[i],*log);
                }
            }
            if (strcmp(argv[1],"mdr") == 0){
                for(int i = 2; i < argc; i++){
                    create("folder", argv[i],*log);
                }
            }
            if (strcmp(argv[1],"move") == 0){
                if(argc < 4 || argc > 4 ){
                    log->add("wrong number of args");
                }
                move(argv[2],argv[3],*log);
            }
        }
    }
    else if (argv[1][0] == 'r'){
        if(argc < 3){
            log->add("wrong number of args");
        }    
        else{
            if(strcmp(argv[1],"rfl") == 0){
                for(int i = 2; i < argc; i++){
                    destroy("file", argv[i],*log);
                }
            }   
            if (strcmp(argv[1],"rdr") == 0){
                for(int i = 2; i < argc; i++){
                    destroy("folder", argv[i],*log);
                }
            }
            if (strcmp(argv[1],"remove") == 0){
                for(int i = 2; i < argc; i++){
                    destroy(argv[i],*log);
                }
            }
            if (strcmp(argv[1],"rename") == 0){
                if(argc < 4 || argc > 4 ){
                    log->add("wrong number of args");
                }
                rename(argv[2],argv[3],*log);
            }
        }
    }
    else if(strcmp(argv[1],"info") == 0){
        information(argv[2],*log);
    }
    else{
      log->add("Liza > unknown command,please call \"help\" to view the list of commands");
    }
    delete log;
    return 0;
}

