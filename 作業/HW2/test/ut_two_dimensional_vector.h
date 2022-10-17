#include "../src/two_dimensional_vector.h"

TEST(vectorTest, testEQ_a){
    Point p1(5.0, 5.0);
    ASSERT_EQ(5.0, p1.x());
    ASSERT_EQ(5.0, p1.y());
}

TEST(vectorTest, testEQ_b){
    Point p2(1.0, 1.0);
    ASSERT_EQ(1.0, p2.x());
    ASSERT_EQ(1.0, p2.y());
}

// 測長度
TEST(vectorTest, testLength) {
    // 宣告Point
    Point p1(5.0, 5.0);     
    Point p2(1.0, 1.0);
    // 取址
    const Point *pp1 = &p1;     
    const Point *pp2 = &p2;
    // 塞Point的address
    TwoDimensionalVector t1(pp1,  pp2);     
    double expected = sqrt(pow(4.0, 2) + pow(4.0, 2));
    ASSERT_NEAR(t1.length(), expected, 0.001);
}

// 測內積
TEST(vectorTest, testDot) {
    // 宣告Point
    // my_vector(點一)
    Point p1(1.0, 1.0);     
    Point p2(2.0, 4.0);
    // to_dot_vector(點二)
    Point p3(2.0, 3.0);     
    Point p4(5.0, 6.0);
    // 取Point物件的位址
    const Point *pp1 = &p1;     
    const Point *pp2 = &p2;
    const Point *pp3 = &p3;     
    const Point *pp4 = &p4;
    // 把Point的address作為參數代進TwoDimensionalVector物件
    TwoDimensionalVector t1(pp1, pp2); 
    TwoDimensionalVector t2(pp3, pp4);
    TwoDimensionalVector *vec = &t2; 
    double expected = 12;
    ASSERT_NEAR(t1.dot(vec), expected, 0.001);
}

// 測外積
TEST(vectorTest, testCross) {
    Point p1(1.0, 1.0);     
    Point p2(2.0, 4.0);

    Point p3(2.0, 3.0);     
    Point p4(5.0, 6.0);

    const Point *pp1 = &p1;     
    const Point *pp2 = &p2;
    const Point *pp3 = &p3;     
    const Point *pp4 = &p4;

    TwoDimensionalVector t1(pp1, pp2); 
    TwoDimensionalVector t2(pp3, pp4);
    TwoDimensionalVector *vec = &t2; 
    double expected = -6;
    ASSERT_NEAR(t1.cross(vec), expected, 0.001);
}


TEST(vectorTest, testInfo) {
    Point point1(-8.42, 3.42);
    Point point2(-3.38, 4.30);
    TwoDimensionalVector t1(&point1, &point2);
    ASSERT_EQ("Vector ((-8.42, 3.42), (-3.38, 4.30))", t1.info());
}
