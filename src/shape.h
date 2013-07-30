#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <string>

#include <glm/glm.hpp>

struct Shape {
    std::string name;
    std::vector<glm::vec4> vertecies;
    std::vector<glm::vec4> normals;
    std::vector<int> faces;    
};

#endif /* SHAPE_H */
