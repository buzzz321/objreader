#ifndef OBJREADER_H
#define OBJREADER_H
#include <string>

struct Shape;

class ObjReader {
public:
ObjReader()
    :file_name(""){};
    
ObjReader(std::string file_name)
    :file_name(file_name){};
    
    Shape ReadShape();
    
private:
    std::string file_name;
    Shape shape;
};

#endif //OBJREADER_H
