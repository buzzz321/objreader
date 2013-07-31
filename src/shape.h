#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <string>

#include <glm/glm.hpp>

struct Face {
    int vertexno;
    int materialno;
    int normalno;

Face(): vertexno(0), materialno(0), normalno(0) {};
};

struct Shape {
    std::string name;
    std::vector<glm::vec4> vertices;
    std::vector<glm::vec4> normals;
    std::vector<Face> faces;    
};

#endif /* SHAPE_H */
