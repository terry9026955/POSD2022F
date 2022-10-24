#include "../src/triangle.h"

TEST(TriangleTest, testInitWithParallelVectors) {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(1, 0);
    TwoDimensionalVector v1(&p1, &p2);
    TwoDimensionalVector v2(&p3, &p2);
    ASSERT_ANY_THROW(Triangle(&v1, &v2));
}

TEST(TriangleTest, testInitWithTwoVectorsWithoutASamePoint) {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(1, 0);
    Point p4(1, 1);
    TwoDimensionalVector v1(&p1, &p2);
    TwoDimensionalVector v2(&p3, &p4);
    ASSERT_ANY_THROW(Triangle(&v1, &v2));
}

TEST(TriangleTest, testArea) {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);
    TwoDimensionalVector v1(&p1, &p2);
    TwoDimensionalVector v2(&p3, &p2);
    Triangle t1(&v1, &v2);
    ASSERT_EQ(6, t1.area());
}

TEST(TriangleTest, testPerimeter) {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);
    TwoDimensionalVector v1(&p1, &p2);
    TwoDimensionalVector v2(&p3, &p2);
    Triangle t1(&v1, &v2);
    ASSERT_EQ(12, t1.perimeter());
}

TEST(TriangleTest, testInfo) {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);
    TwoDimensionalVector v1(&p1, &p2);
    TwoDimensionalVector v2(&p3, &p2);
    Triangle t1(&v1, &v2);
    ASSERT_EQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((0.00, 4.00), (3.00, 0.00)))", t1.info());
}

TEST(TriangleTest, testGetPoints) {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);
    TwoDimensionalVector v1(&p1, &p2);
    TwoDimensionalVector v2(&p3, &p2);
    Triangle t1(&v1, &v2);
    auto points = t1.getPoints();
    ASSERT_NE(points.end(), points.find(&p1));
    ASSERT_NE(points.end(), points.find(&p2));
    ASSERT_NE(points.end(), points.find(&p3));
}