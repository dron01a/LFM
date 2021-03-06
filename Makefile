CC=g++
CFLAGS=-c -Wall

# sources of liza 
SOURCES_PATH=./src/*.cpp

# sources of FSTool lib
FSTOOL_PATH=./src/FSTool/*.cpp

# sources of WPTool lib
WPTOOL_PATH=./src/WPTool/*.cpp

# name of executable file   
EXECUTABLE=liza

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

fstool.a: file.o folder.o FSTbase.o FSTool.o
	ar cr fstool.a file.o folder.o FSTbase.o FSTool.o

wptool.a: src/WPTool/WPTool.cpp
	g++ src/WPTool/WPTool.cpp -c -o wptool.o
	ar cr wptool.a wptool.o

liza: fstool.a wptool.a 
	$(CC) $(SOURCES_PATH) fstool.a wptool.a -o liza
	
