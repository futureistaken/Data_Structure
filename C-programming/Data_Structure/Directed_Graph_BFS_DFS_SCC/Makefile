#------------------------------------------------------------------------------
#  Makefile for CMPS 101 Programming Assignment 4
#
#  make                     makes GraphProperties
#  make clean               removes binaries
#  make checkGraph          tests Graph for memory leaks
#------------------------------------------------------------------------------

BASE_SOURCES   = Digraph.c List.c
BASE_OBJECTS   = Digraph.o List.o
HEADERS        = Digraph.h List.h
COMPILE        = gcc -c -std=c99 -Wall
LINK           = gcc -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes DigraphProperties

DigraphProperties : DigraphProperties.o $(BASE_OBJECTS)
	$(LINK) DigraphProperties DigraphProperties.o $(BASE_OBJECTS)

DigraphProperties.o : DigraphProperties.c $(HEADERS)
	$(COMPILE) DigraphProperties.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE) DigraphProperties DigraphProperties.o $(BASE_OBJECTS)

checkGraph : DigraphProperties
	$(MEMCHECK) ./DigraphProperties input output
 
