#ifndef __OPERATIONS__H__
#define __OPERATIONS__H__

#include "../../libs/FSTool_lib/FSTool.h"
#include "settings.h"
#include "output.h"

// create folder/file
void create(std::string name, std::string type, message &result);    

// destroy folder/file
void destroy(std::string name, message &result);                   

// move to directory folde/file
void move(std::string name, std::string path, message &result);      

// get information of file/folder
void information(std::string name, message &result);

// rename file/folder
void rename(std::string oldName, std::string newName, message &result);

// copy file/folder
void copy(std::string source, std::string dest, message &result);

#endif