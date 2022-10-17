#include "../src/rectangle.h"

TEST(rectangleTest, testEQ_lenth){
    Point p1(0.0, 0.0);
    Point p2(5.0, 0.0);
    Point p3(0.0, 0.0);
    Point p4(0.0, 3.0);
    TwoDimensionalVector lenVec(&p1, &p2);
    TwoDimensionalVector widVec(&p3, &p4);
    Rectangle r(&lenVec, &widVec);
    double expected = 5;
    ASSERT_NEAR(r.length(), expected, 0.001);
}

TEST(rectangleTest, testEQ_width){
    Point p1(0.0, 0.0);
    Point p2(5.0, 0.0);
    Point p3(0.0, 0.0);
    Point p4(0.0, 3.0);
    TwoDimensionalVector lenVec(&p1, &p2);
    TwoDimensionalVector widVec(&p3, &p4);
    Rectangle r(&lenVec, &widVec);
    double expected = 3;
    ASSERT_NEAR(r.width(), expected, 0.001);
}

TEST(rectangleTest, testArea){
    Point p1(0.0, 0.0);
    Point p2(5.0, 0.0);
    Point p3(0.0, 0.0);
    Point p4(0.0, 3.0);
    TwoDimensionalVector lenVec(&p1, &p2);
    TwoDimensionalVector widVec(&p3, &p4);
    Rectangle r(&lenVec, &widVec);
    double expected = 15;
    ASSERT_NEAR(r.area(), expected, 0.001);
}

TEST(rectangleTest, testPerimeter){
    Point p1(0.0, 0.0);
    Point p2(5.0, 0.0);
    Point p3(0.0, 0.0);
    Point p4(0.0, 3.0);
    TwoDimensionalVector lenVec(&p1, &p2);
    TwoDimensionalVector widVec(&p3, &p4);
    Rectangle r(&lenVec, &widVec);
    double expected = 16;
    ASSERT_NEAR(r.perimeter(), expected, 0.001);
}

TEST(rectangleTest, testInfo){
    Point p1(-2.00, 1.00);
    Point p2(1.50, 0.47);
    Point p3(-2.00, 1.00);
    Point p4(-1.47, 4.50);
    TwoDimensionalVector lenVec(&p1, &p2);
    TwoDimensionalVector widVec(&p3, &p4);
    Rectangle r(&lenVec, &widVec);
    ASSERT_EQ("Rectangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50)))", r.info());
}

