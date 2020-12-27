# Liza File Manager(LFM) 

https://img.shields.io/docker/v/ARmodRey/LFM

Component for Linux that performs operations with the file system using commands <br/>
Designed for quick operations with files and folders<br/>

## List of commands

### Commands to create:
    mfl -> make file in work directory <br/>
        Example: liza mfl test.cpp<br/>
    mdr -> make folder in work directory <br/>
        Example: liza mdr test_folder<br/>
<br/>
### Commands to remove:
    rfl -> delete file in work directory<br/>
        Example: liza rfl test.cpp<br/>
    rdr -> delete folder in work directory<br/>
        Example: liza rdr test_folder<br/>
<br/>
### Other commands:
    info -> print info of folder/file<br/>
        Example: liza info test.cpp<br/>
    move -> moves folder/file along the specified path<br/>
        Example: liza move test.cpp test_folder<br/>
<br/>

## Сhanges

v 0.1.0:<br/>
    add functions mfl,rdr,rfl,fdr<br/>
<br/>

v 0.1.5:<br/>
    add functions info, move<br/>
<br/>