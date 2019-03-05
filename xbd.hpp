/**
 * Name: Rhythm Mecwan (cssc0448) & Patrick Perine (cssc0426)
 * Project: CS530 Assignment 1
 * File: xbd.hpp
 * Notes: Header file with all data types, declarations, and macro definitions.
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
using namespace std;

// Determines if a given char is a printable character.
bool isPrintable(char c);

// Converts a hex integer into a proper address format.
std::string addressFormat(int ad);

// Prints a Binary byte (not nibble!), uses isPrintable to determine
// if it would be printable in ASCII format.
bool printValidBinaryNibble(char* str);

// Prints a Hex nibble, uses isPrintable to determine
// if it would be printable in ASCII format.
bool printValidHexNibble(char* str);

// Accounts for unfinished lines in a binary output line.
void binaryCleanup(string lineAscii, int addr);

// Accounts for unfinished lines in a hex output line.
void hexCleanup(string lineAscii, int addr);

// Main function. Declares variables to be used by helper methods.
// Also contains the core loops for printing each line of output
// in both hex and binary.
int main(int argc, char* argv[]);

/**************************[ EOF: xbd.hpp ]************************/
