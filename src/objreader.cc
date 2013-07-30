#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "objreader.h"
#include "shape.h"

using namespace std;

// trim from start. nicked from stackoverflow
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end. nicked from stackoverflow
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends. nicked from stackoverflow
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}

Shape ObjReader::ReadShape() {    
    string line;
    string token, rest;
    ifstream infile;
    Shape shape;
    
    infile.open(file_name);

    while(infile.good()){
        getline(infile, line);
        trim(line); //remove spaces and new lines..

        stringstream ss(line);
        ss >> token;

        if (token.compare("#") == 0) {
            continue;
        }
        if (token.compare("o") == 0) {
            shape.name = GetObjName( ss );
        }
    }
    
    return shape;
}

std::string ObjReader::GetObjName ( stringstream &ss ) {
    string retval;
    getline(ss, retval);

    return trim(retval);
}
