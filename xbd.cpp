 
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
using namespace std;

bool isPrintable(char c) {
    int val = (int) c;
    if(val > 32 && val < 127)
        return true;
    else
        return false;
}

bool printValidBinaryNibble(char* str) {
    std::bitset<8> b(*str);
    std::cout << b;
    return isPrintable(*str);
}

bool printValidHexNibble(char* str) {
    if(isPrintable(*str)) {
        stringstream ss;
        ss << hex << unsigned(*str);
            
        unsigned res;
        ss >> res;
            
        cout << hex << res;
        return true;
    }
    else {
        if((int)*str < 16)
            cout << "0";
        cout << hex << (int)*str;
        return false;
    }
}

std::string addressFormat(int ad)
{
  std::stringstream stream;
  stream << std::setfill('0') << std::setw((sizeof(int)*2)-1) 
         << std::hex << ad;
  return stream.str();
}

int main(int argc, char* argv[]){
    char input;
    string lineAscii = "";
    int addr = 0x00;
    
    bool ifFirstLine = true;
    bool outBinary = false;
    
    ifstream fileCon;
    
    if(argc == 3)
        outBinary = true;
    
    fileCon.open(argv[(1+(argc-2))]);
    
    if(!outBinary) {
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
                    cout << lineAscii << endl << addressFormat(addr) << ": ";
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
    else {
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
                    cout << lineAscii << endl << addressFormat(addr) << ": ";
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
    
    fileCon.close();
    
    if(!outBinary && addr % 16 != 0) {
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
        cout << lineAscii << endl;
    }
    else if(addr % 6 != 0) {
       while(addr % 6 != 0) {
           cout << "         ";
           addr += 1;
       }
       cout << lineAscii << endl;
    }
}


//char cmp;
//bool isASCII = false;
//ifstream fileCheck;

/* Checked if file contains only ASCII characters or not, found to be useless.

    fileCheck.open(argv[(1+(argc-2))]);
    
    while(fileCheck.is_open() && fileCheck.good() && !fileCheck.eof()) {
        getline(fileCheck, input);
        for(int i=0; i<input.length(); i++) {
            cmp = input[i];
            if(cmp != '0' && cmp != '1') {
                if(cmp == '\n') {
                    if(ifNewLine) {
                        isASCII = true;
                        printf("found extra newline\n");
                        fileCheck.close();
                        break;
                    }
                    else
                        ifNewLine = true;
                }
                else {
                    isASCII = true;
                    printf("found ASCII char at %d\n", i);
                    fileCheck.close();
                    break;
                }
            }
            printf("checked character\n");
        }
    }
*/