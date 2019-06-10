#------------------------------------------------------------------------------
#  Makefile for CMPS 101 Programming Assignment 2
#
#  make                     makes GraphProperties
#  make clean               removes .o files
#  make checkGraph          tests Graph for memory leaks
#------------------------------------------------------------------------------

BASE_SOURCES   = Graph.c List.c
BASE_OBJECTS   = Graph.o List.o
HEADERS        = Graph.h List.h
COMPILE        = gcc -c -std=c99 -Wall
LINK           = gcc -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes GraphProperties

GraphProperties : GraphProperties.o $(BASE_OBJECTS)
	$(LINK) GraphProperties GraphProperties.o $(BASE_OBJECTS)

GraphProperties.o : GraphProperties.c $(HEADERS)
	$(COMPILE) GraphProperties.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE) GraphProperties GraphProperties.o $(BASE_OBJECTS)

checkGraph : GraphProperties
	$(MEMCHECK) ./GraphProperties input output
 
