#include "../src/triangle.h"

TEST(triangleTest, testArea) {
    // 宣告Point
    // 點一
    Point p1(0.0, 0.0); // (0, 0)
    Point p2(3.0, 0.0); // (3, 0)
    // 點二
    Point p3(3.0, 4.0); // (3, 4)   
    Point p4(3.0, 0.0); // (3, 0)
    // 塞Point的address
    TwoDimensionalVector t1(&p1,  &p2);   
    TwoDimensionalVector t2(&p3,  &p4); 
    // 宣告三角形
    Triangle triangle(&t1, &t2);    // 吃address
    double expected = 6;
    ASSERT_NEAR(triangle.area(), expected, 0.001);
}

TEST(triangleTest, testPerimeter) {
    Point p1(0.0, 0.0); // (0, 0)
    Point p2(3.0, 0.0); // (3, 0)
    Point p3(3.0, 4.0); // (0, 0)   
    Point p4(3.0, 0.0); // (0, 4)

    TwoDimensionalVector t1(&p1,  &p2);   
    TwoDimensionalVector t2(&p3,  &p4); 

    Triangle triangle(&t1, &t2);    
    double expected = 7;
    ASSERT_NEAR(triangle.perimeter(), expected, 0.001);
}

TEST(triangleTest, testInfo){
    Point p1(0.00, 0.00);
    Point p2(3.00, 0.00);
    Point p3(3.00, 4.00);
    Point p4(3.00, 0.00);
    TwoDimensionalVector t1(&p1, &p2);
    TwoDimensionalVector t2(&p3, &p4);
    Triangle triangle(&t1, &t2);
    ASSERT_EQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))", triangle.info());
}

TEST(triangleTest, ParallelException){
    Point p1(0.00, 0.00);
    Point p2(3.00, 0.00);
    Point p3(3.00, 4.00);
    Point p4(2.00, 0.00);
    TwoDimensionalVector t1(&p1, &p2);
    TwoDimensionalVector t2(&p3, &p4);
    // Triangle triangle(&t1, &t2);
    try{
        Triangle triangle(&t1, &t2);
    }catch(std::string msg){
        ASSERT_EQ("This is not a Triangle", msg);
    }
}