#ifndef __FSTOOL__H__
#define __FSTOOL__H__

#include "file.h"
#include "folder.h"

namespace FSTool{
    
    //check functions 
    bool is_file(std::string file_name);
    bool is_folder(std::string folder_name);

}; 

#endif