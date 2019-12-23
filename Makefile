CXX = g++

IDIR = ./Include/
SRCDIR = ./Source/

SOURCES = $(SRCDIR)*.cpp

all: adventurist

adventurist: 
	$(CXX) $(SOURCES) -o $@