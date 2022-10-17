#include "../src/circle.h"

#include <cmath>

TEST(circleTest, testRadius){
    Point p1(0.0, 0.0);
    Point p2(5.0, 0.0);
    TwoDimensionalVector radiusVec(&p1, &p2);
    Circle circle(&radiusVec);
    double expected = 5;
    ASSERT_NEAR(circle.radius(), expected, 0.001);
}

TEST(circleTest, testArea){
    Point p1(0.0, 0.0);
    Point p2(5.0, 0.0);
    TwoDimensionalVector radiusVec(&p1, &p2);
    Circle circle(&radiusVec);
    double expected = 78.539;
    ASSERT_NEAR(circle.area(), expected, 0.001);
}

TEST(circleTest, testPerimeter){
    Point p1(0.0, 0.0);
    Point p2(5.0, 0.0);
    TwoDimensionalVector radiusVec(&p1, &p2);
    Circle circle(&radiusVec);
    double expected = 31.415;
    ASSERT_NEAR(circle.perimeter(), expected, 0.001);
}

TEST(circleTest, testInfo) {
    Point point1(-4.28, 0.26);
    Point point2(-4.83, 0.73);
    TwoDimensionalVector radiusVec(&point1, &point2);
    Circle circle(&radiusVec);
    ASSERT_EQ("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))", circle.info());
}
