ifeq ($(OS),Windows_NT)
    CXX = g++
	RUN = adventurist.exe
	DELETE = del adventurist.exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CXX = x86_64-w64-mingw32-g++
		RUN = wineconsole adventurist.exe
		DELETE = rm adventurist.exe
    endif
endif

CXXFLAGS = -static
IDIR = ./Include/
SRCDIR = ./Source/
 
SOURCES = $(SRCDIR)*.cpp
 
all: adventurist run remove
 
adventurist:
	$(CXX) $(SOURCES) $(CXXFLAGS) -o $@

run:
	$(RUN)
remove:
	$(DELETE)
