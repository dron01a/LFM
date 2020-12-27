# Liza File Manager(LFM) 

Component for Linux that performs operations with the file system using commands <br/>
Designed for quick operations with files and folders<br/>

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
### Other commands
    info -> print info of folder/file
        Example: liza info test.cpp
    move -> moves folder/file along the specified path
        Example: liza move test.cpp test_folder

## Сhanges

v 0.1.0:

    add functions mfl,rdr,rfl,fdr
v 0.1.5:

    add functions info, move