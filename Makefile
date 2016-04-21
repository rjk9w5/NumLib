###############################################################################
# -->Makefile<--
###############################################################################

###############################################################################
#
# Programmer :  Rob Wiehage
# Modified by:  Billy Rhoades
# Assignment :  Program 4
#
# Instructor :  Dr. Michael Hilgers
# Course     :  CS236 Winter 2001
# Semester   :  Fall 2001
#
###############################################################################

###############################################################################
# This makefile will build an executable for the assignment.
###############################################################################

.PHONY: all clean

CXX = /usr/bin/g++
CXXFLAGS = -O3 -std=c++11 -Wall -W -pedantic-errors -g -pg

# The following 2 lines only work with gnu make.
# It's much nicer than having to list them out,
# and less error prone.
SOURCES = $(wildcard *.cpp) $(wildcard include/common/*.cpp)
HEADERS = $(wildcard include/solvers/*.h) $(wildcard include/matrices/*.h) $(wildcard include/vector/*.h)
# With Sun's make it has to be done like this, instead of
# using wildcards.
# Well, I haven't figured out another way yet.
#SOURCES = signal.cpp tokentype.cpp token.cpp tokenlist.cpp driver.cpp
#HEADERS = signal.h tokentype.h token.h tokenlist.h

# Looks like it can be done like this, but won't work for gmake.
#SOURCES:sh = ls *.cpp
#HEADERS:sh = ls *.h

OBJECTS = $(SOURCES:%.cpp=%.o)

default: driver

%.o: %.cpp
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

driver: $(OBJECTS)
	@echo "Building $@"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@
	@echo ""
	@echo "Everything worked :-) "
	@echo ""

clean:
	-@rm -f core
	-@rm -f driver
	-@rm -f depend
	-@rm -f $(OBJECTS)

# Automatically generate dependencies and include them in Makefile
depend: $(SOURCES) $(HEADERS)
	@echo "Generating dependencies"
	@$(CXX) -MM -std=c++11 *.cpp > $@


-include depend
# Put a dash in front of include when using gnu make.
# It stops gmake from warning us that the file
# doesn't exist yet, even though it will be properly
# made and included when all is said and done.
