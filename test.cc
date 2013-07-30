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


