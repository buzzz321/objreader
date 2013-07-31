#ifndef OBJREADER_H
#define OBJREADER_H
#include <string>
#include <sstream>

#include <glm/glm.hpp>

#include "shape.h"


class ObjReader {
public:
ObjReader()
    :file_name(""){};
    
ObjReader(std::string file_name)
    :file_name(file_name){};
    
    Shape ReadShape();
    std::string GetObjName( std::stringstream &ss );
    glm::vec4 GetVertex( std::stringstream &ss );
    Face GetFace( std::stringstream &ss );
    
private:
    std::string file_name;
    Shape shape;
};

#endif //OBJREADER_H
