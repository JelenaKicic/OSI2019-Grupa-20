CXX = g++

IDIR = ./Include/
SRCDIR = ./Source/

SOURCES = $(SRCDIR)*.cpp

all: adventurist run clean

adventurist: 
	$(CXX) $(SOURCES) -o $@

run:
	./adventurist

clean:
	rm adventurist