#ifndef __OPERATIONS__H__
#define __OPERATIONS__H__

#include "FSTool/FSTool.h"
#include "message.h"

// create folder/file
void create(std::string type, std::string name, message &result);    

// destroy folder/file
void destroy(std::string type, std::string name, message &result);   
void destroy(std::string name, message &result);                   

// move folde/file
void move(std::string name, std::string path, message &result);      

// get information of file/folder
void information(std::string name, message &result);

#endif