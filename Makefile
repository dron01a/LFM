CC=g++
CFLAGS=-c -Wall

HOME_PATH = ${HOME}

# path to FSTool 
FSTOOL=./src/FSTool_lib/

# path to WPTool
WPTOOL=./src/WPTool_lib/

#path to SXML
SXML=./src/SXML_lib/

# sources of liza 
SOURCES_PATH=./src/*.cpp

# name of executable file   
EXECUTABLE=liza

.PHONY: all clean install 

all: ${EXECUTABLE}

clean: 
	rm -rf *.o *.a ${EXECUTABLE}

file.o: ${FSTOOL}file.cpp
	$(CC) ${FSTOOL}file.cpp -c -o file.o

folder.o: ${FSTOOL}folder.cpp
	$(CC) ${FSTOOL}folder.cpp -c -o folder.o

FSTbase.o: ${FSTOOL}FSTbase.cpp
	$(CC) ${FSTOOL}FSTbase.cpp -c -o FSTbase.o

FSTool.o: ${FSTOOL}FSTool.cpp
	$(CC) ${FSTOOL}FSTool.cpp -c -o FSTool.o

SXML.o: ${SXML}SXML.cpp
	$(CC) ${SXML}SXML.cpp -c -o SXML.o

fstool.a: file.o folder.o FSTbase.o FSTool.o
	ar cr fstool.a file.o folder.o FSTbase.o FSTool.o

wptool.a: ${WPTOOL}WPTool.cpp
	$(CC) ${WPTOOL}WPTool.cpp -c -o wptool.o
	ar cr wptool.a wptool.o

${EXECUTABLE}: fstool.a wptool.a SXML.o
	$(CC) $(SOURCES_PATH) SXML.o fstool.a wptool.a -o ${EXECUTABLE}

install: 
	mkdir -vp ${HOME_PATH}/.liza/
	cp -r ./config.txt ${HOME_PATH}/.liza/
	cp -r ./localization/ ${HOME_PATH}/.liza/
	sudo install ./${EXECUTABLE} /bin