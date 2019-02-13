 
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

void printHexNibble(char* str) {
    stringstream ss;
    ss << hex << unsigned(*str);
    
    unsigned res;
    ss >> res;
    cout << hex << res;
}

int main(int argc, char* argv[]){
    string input;
    string lineAscii;
    int addr = 0x00;
    int lineChk = 0;
    char cmp;
    bool isASCII = false;
    bool ifNewLine = false;
    bool outBinary = false;
    ifstream fileCheck;
    ifstream fileCon;
    
    if(argc == 3)
        outBinary = true;
    
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
    
    fileCon.open(argv[(1+(argc-2))]);
    
    while(fileCon.is_open() && fileCon.good() && !fileCon.eof()) {
        getline(fileCon, input);
        /*if(isASCII) {
            cout << addr << ": ";
            for(int i=0; i<input.length(); i++) {
                printHexNibble(&input[i]);
                i++;
                printHexNibble(&input[i]);
                cout << " ";
            }
            addr += 16;
            cout << endl;
        }
        else {
            
        }
    */
        printf("sup");
    }
    
}