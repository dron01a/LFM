#ifndef __OPERATIONS__H__
#define __OPERATIONS__H__

#include "FSTool/FSTool.h"
#include "settings.h"

// create folder/file
void create(std::string type, std::string name, logger &result);    

// destroy folder/file
void destroy(std::string type, std::string name, logger &result);   
void destroy(std::string name, logger &result);                   

// move to directory folde/file
void move(std::string name, std::string path, logger &result);      

// get information of file/folder
void information(std::string name, logger &result);

// rename file/folder
void rename(std::string oldName, std::string newName, logger &result);

#endif