 
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
using namespace std;

int hex_to_int(char c){
    int one = (c/16) - 3;
    int two = c % 16;
    int res = (one*10) + two;
    if(res > 9)
        res--;
    return res;
}

int hex_to_ascii(char c, char d){
    int h = hex_to_int(c) * 16;
    int l = hex_to_int(d);
    return h+l;
}

int main(int argc, char* argv[]){
    string input;
    bool binary = false;
    
    if(argc == 3)
        binary = true;
    
    ifstream file(argv[1+(argc-2)]);
    
    while(file.is_open() && file.good() && !file.eof()) {
        getline(file, input);
        if(!binary){
            
        }
        else{
            
        }
    
    }
    
}