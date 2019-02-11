 
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
    string addr = "0000000: ";
    bool binary = false;
    
    if(argc == 3)
        binary = true;
    
    ifstream file(argv[(1+(argc-2))]);
    
    while(file.is_open() && file.good() && !file.eof()) {
        getline(file, input);
        if(!binary) {
            for(int i=0; i<input.length(); i++) {
                printHexNibble(&input[i]);
            }
        }
        else {
            
        }
    
    }
    
}