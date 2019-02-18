###########################################################
# Rhythm  Mecwan (cssc0048), Patrick Perrine   
# CS 530 Spring 2019    
# Assignment #1, XBD  
# Makefile
###########################################################

# Variables

CXX = g++

# Targets

xbd: xbd.o
	$(CXX) -o xbd xbd.o

xbd.o: xbd.cpp xbd.hpp
	$(CXX) -c xbd.cpp

clean:
	rm -rf xbd

#######################[ EOF: Makefile ]###################
