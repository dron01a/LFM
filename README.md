# Liza File Manager(LFM) 

Component for Linux that performs operations with the file system using commands <br/>
Designed for quick operations with files and folders<br/>

## Used source code of LIBSs:
    FSTool: https://github.com/ARmodRey/FSTool.git
    WPTool: https://github.com/ARmodRey/WPTool.git
    SXML: https://github.com/ARmodRey/SXML.git
    
#### Install
    git clone https://github.com/ARmodRey/LFM.git
    make
    make install

## List of commands

### Commands to create
    mfl -> make file in work directory 
        Example: liza mfl test.cpp
    mdr -> make folder in work directory
        Example: liza mdr test_folder
### Commands to remove
    rfl -> delete file in work directory
        Example: liza rfl test.cpp
    rdr -> delete folder in work directory
        Example: liza rdr test_folder
    remove -> delete file/folder in work directory
        EXample: liza remove test_folder test_file
### Other commands
    info -> print info of folder/file
        Example: liza info test.cpp
    move -> moves folder/file along the specified path
        Example: liza move test.cpp test_folder
