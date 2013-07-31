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
        if (token.compare("v") == 0) {
            shape.vertices.push_back( GetVertex( ss ));
        }
        if (token.compare("vn") == 0) {
            shape.normals.push_back( GetNormal( ss ));
        }

        if (token.compare("f") == 0) {
            do {
                if ( ss.peek() != -1 ){
                    shape.faces.push_back( GetFace( ss) );
                }
            } while (ss);
        }

    }
    
    return shape;
}

std::string ObjReader::GetObjName ( stringstream &ss ) {
    string retval;
    getline(ss, retval);

    return trim(retval);
}

glm::vec4 ObjReader::GetVertex( stringstream &ss ) {
    glm::vec4 retval;

    ss >> retval.x >> retval.y >> retval.z;
    retval.w = 0.0;

    return retval;
}

glm::vec4 ObjReader::GetNormal( stringstream &ss ) {
    glm::vec4 retval;

    ss >> retval.x >> retval.y >> retval.z;
    retval.w = 0.0;

    return retval;
}


Face ObjReader::GetFace( stringstream &ss ) {
    Face face;
    //string split code from cplusplus faq
    string delimiters = "/";
    string result;
    string line;
    size_t current;
    size_t next = -1;
    size_t index = 0;

    ss >> line;
    do
    {
        current = next + 1;
        next = line.find_first_of( delimiters, current );
        result = line.substr( current, next - current ); 
        if (result.compare("") != 0){
            switch (index){
            case 0: face.vertexno = stoi(result);
                break;
            case 1: face.materialno = stoi(result);
                break;
            case 2: face.normalno = stoi(result);
                break;
            default:
                cerr << "too many faces " << endl;
            }
        }
        index++;
    }
    while (next != string::npos);

    return face;
}

