#include <iostream>
#include <string>
#include <sstream>

#include "gtest/gtest.h"
#include "src/objreader.h"

using namespace std;

TEST(shape_name_empty, name) {
    ObjReader uat("../test1_wavefront.obj");
    
    Shape sp = uat.ReadShape();
    EXPECT_EQ("Cube", sp.name);
}

TEST(ObjReader_name_get, GetObjName) {
    ObjReader uat("../test1_wavefront.obj");
    string data("Dragon");
    stringstream ss(data);
    
    string result( uat.GetObjName(ss) );
    EXPECT_EQ("Dragon", result);
}

TEST(shape_name_get, name) {
    ObjReader uat("../test1_wavefront.obj");
    
    Shape result = uat.ReadShape();
    EXPECT_EQ("Cube", result.name);
}


TEST(shape_getvertex_t1, GetVertex) {
    ObjReader uat("../test1_wavefront.obj");
    string data("1.0 2.0 3.0");
    glm::vec4 expected( 1.0,2.0,3.0,0.0 );
    
    stringstream ss(data);
    
    glm::vec4 result = uat.GetVertex(ss) ;
    EXPECT_EQ(expected.x, result.x);
    EXPECT_EQ(expected.y, result.y);
    EXPECT_EQ(expected.z, result.z);
    EXPECT_EQ(expected.w, result.w);
}

TEST(ObjReader_getvertex_t1, GetVertex) {
    ObjReader uat("../test1_wavefront.obj");
    glm::vec4 expected( 1.060198, -0.969736, -1.173598, 0.0 );
    
    Shape sp = uat.ReadShape();
    //could be fatal to compare doubles like this.. Fragile test :(
    EXPECT_EQ(expected.x, sp.vertices[0].x);
    EXPECT_EQ(expected.y, sp.vertices[0].y);
    EXPECT_EQ(expected.z, sp.vertices[0].z);
    EXPECT_EQ(expected.w, sp.vertices[0].w);      
}

TEST(ObjReader_getface_two_numbers, GetFace) {
    ObjReader uat("../test1_wavefront.obj");
    string data("1//2");
    stringstream ss(data);

    Face expected;
    expected.vertexno = 1;
    expected.materialno = 0;
    expected.normalno = 2;
    
    Face result = uat.GetFace(ss);

    EXPECT_EQ(expected.vertexno, result.vertexno);
    EXPECT_EQ(expected.materialno, result.materialno);
    EXPECT_EQ(expected.normalno, result.normalno); 
}

TEST(ObjReader_getface_one_numbers, GetFace) {
    ObjReader uat("../test1_wavefront.obj");
    string data("1");
    stringstream ss(data);

    Face expected;
    expected.vertexno = 1;
    expected.materialno = 0;
    expected.normalno = 0;
        
    Face result = uat.GetFace(ss);
    EXPECT_EQ(expected.vertexno, result.vertexno);
    EXPECT_EQ(expected.materialno, result.materialno);
    EXPECT_EQ(expected.normalno, result.normalno); 
}

TEST(shape_getface_three_numbers, GetFace) {
    ObjReader uat("../test1_wavefront.obj");
    Face expected;
    expected.vertexno = 1;
    expected.materialno = 0;
    expected.normalno = 1;
        
    Shape sp = uat.ReadShape();

    EXPECT_EQ(expected.vertexno, sp.faces[0].vertexno);
    EXPECT_EQ(expected.materialno, sp.faces[0].materialno);
    EXPECT_EQ(expected.normalno, sp.faces[0].normalno); 
}
