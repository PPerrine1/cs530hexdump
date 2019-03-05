/**
 * Name: Rhythm Mecwan (cssc0448) & Patrick Perine (cssc0426)
 * Project: CS530 Assignment 1
 * File: xbd.cpp
 * Notes: Source file for HexDump functions, including main.
 */

#include "xbd.hpp"

// Determines if a given char is a printable character.
bool isPrintable(char c) {
    int val = (int) c;
    if(val > 32 && val < 127)
        return true;
    else
        return false;
}

// Converts a hex integer into a proper address format.
std::string addressFormat(int ad) {
  std::stringstream stream;
  stream << std::setfill('0') << std::setw((sizeof(int)*2)-1) 
         << std::hex << ad;
  return stream.str();
}

// Prints a Binary byte (not nibble!), uses isPrintable to determine
// if it would be printable in ASCII format.
bool printValidBinaryNibble(char* str) {
    std::bitset<8> b(*str);
    std::cout << b;
    return isPrintable(*str);
}

// Prints a Hex nibble, uses isPrintable to determine
// if it would be printable in ASCII format.
bool printValidHexNibble(char* str) {
    int len = sizeof(*str)/sizeof(char);
    static const char* const lut = "0123456789abcdef";
    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = str[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    cout << output;
    return isPrintable(*str);
}

// Accounts for unfinished lines in a binary output line.
void binaryCleanup(string lineAscii, int addr) {
    if(addr % 6 != 0) {
       while(addr % 6 != 0) {
           cout << "         ";
           addr += 1;
       }
       cout << " " << lineAscii << endl;
    }
}

// Accounts for unfinished lines in a hex output line.
void hexCleanup(string lineAscii, int addr) {
    if(addr % 16 != 0) {
        while(addr % 16 != 0) {
            if(addr % 2 != 0) {
                cout << "   ";
                addr += 1;
            }
            else {
                cout << "     ";
                addr += 2;
            }
        }
        cout << " " << lineAscii << endl;
    }
}

// Main function. Declares variables to be used by helper methods.
// Also contains the core loops for printing each line of output
// in both hex and binary.
int main(int argc, char* argv[]){
    char input;
    string lineAscii = "";
    int addr = 0x00;
    bool outBinary = false;
    ifstream fileCon;
    
    if(argc == 3)
        outBinary = true;
    
    fileCon.open(argv[(1+(argc-2))]);
    
    if(outBinary) {
        bool ifFirstLine = true;
        while(fileCon.is_open() && fileCon.good()) {
                fileCon.get(input);
                if(fileCon.eof())
                    break;
                else {
                    if(ifFirstLine) {
                        cout << addressFormat(addr) << ": ";
                        ifFirstLine = false;
                    }
                    else if(addr % 6 == 0) {
                        cout << " " << lineAscii << endl << addressFormat(addr) << ": ";
                        lineAscii = "";
                    }
                    
                    if(printValidBinaryNibble(&input))
                        lineAscii += input;
                    else
                        lineAscii += ".";
                    
                    addr += 1;
                    cout << " ";
                }
        }
    }
    else {
        bool ifFirstLine = true;
        while(fileCon.is_open() && fileCon.good()) {
            fileCon.get(input);
            if(fileCon.eof())
                break;
            else {
                if(ifFirstLine) {
                    cout << addressFormat(addr) << ": ";
                    ifFirstLine = false;
                }
                else if(addr % 16 == 0) {
                    cout << " " << lineAscii << endl << addressFormat(addr) << ": ";
                    lineAscii = "";
                }
                
                if(printValidHexNibble(&input))
                    lineAscii += input;
                else
                    lineAscii += ".";
                
                addr += 1;
                
                if(addr % 2 == 0)
                    cout << " ";
            }
        }
    }
    
    fileCon.close(); // For safety
    
    if(outBinary)
        binaryCleanup(lineAscii, addr);
    else
        hexCleanup(lineAscii, addr);
}

/**************************[ EOF: xbd.cpp ]************************/