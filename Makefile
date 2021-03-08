CC=g++
CFLAGS=-c -Wall

HOME_PATH = ${HOME}

# sources of liza 
SOURCES_PATH=./src/*.cpp

# name of executable file   
EXECUTABLE=liza

.PHONY: all clean install 

all: liza

clean: 
	rm -rf *.o *.a liza

file.o: src/FSTool/file.cpp
	g++ src/FSTool/file.cpp -c -o file.o

folder.o: src/FSTool/folder.cpp
	g++ src/FSTool/folder.cpp -c -o folder.o

FSTbase.o: src/FSTool/FSTbase.cpp
	g++ src/FSTool/FSTbase.cpp -c -o FSTbase.o

FSTool.o: src/FSTool/FSTool.cpp
	g++ src/FSTool/FSTool.cpp -c -o FSTool.o

SXML.o: src/SXML/SXML.cpp
	g++ src/SXML/SXML.cpp -c -o SXML.o

fstool.a: file.o folder.o FSTbase.o FSTool.o
	ar cr fstool.a file.o folder.o FSTbase.o FSTool.o

wptool.a: src/WPTool/WPTool.cpp
	g++ src/WPTool/WPTool.cpp -c -o wptool.o
	ar cr wptool.a wptool.o

liza: fstool.a wptool.a SXML.o
	$(CC) $(SOURCES_PATH) SXML.o fstool.a wptool.a -o liza

install: 
	mkdir -vp ${HOME_PATH}/.liza/
	cp -r ./config.txt ${HOME_PATH}/.liza/
	cp -r ./localization/ ${HOME_PATH}/.liza/
	sudo install ./liza /bin