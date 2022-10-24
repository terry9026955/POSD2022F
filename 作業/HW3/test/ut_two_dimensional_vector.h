#include "../src/two_dimensional_vector.h"


TEST(TwoDimensionalVectorTest, TestGet){
    Point p1(1, 1);
    Point p2(3, 3);
    TwoDimensionalVector v1(&p1, &p2);
    ASSERT_EQ(p1, *v1.a());
    ASSERT_EQ(p2, *v1.b());
}

TEST(TwoDimensionalVectorTest, TestVectorPoint){
    Point p1(1, 1);
    Point p2(3, 3);
    TwoDimensionalVector v1(&p1, &p2);
    ASSERT_EQ(Point(2, 2), v1.vp());
}

TEST(TwoDimensionalVectorTest, TestLength){
    Point p1(1, 1);
    Point p2(3, 3);
    TwoDimensionalVector v1(&p1, &p2);
    ASSERT_NEAR(sqrt(8), v1.length(), 0.01);
}

TEST(TwoDimensionalVectorTest, TestCross){
    Point p1(1, 1);
    Point p2(3, 3);
    TwoDimensionalVector v1(&p1, &p2);
    ASSERT_EQ(0, v1.cross(&v1));
}

TEST(TwoDimensionalVectorTest, TestDot){
    Point p1(1, 1);
    Point p2(3, 3);
    TwoDimensionalVector v1(&p1, &p2);
    ASSERT_EQ(8, v1.dot(&v1));
}

TEST(TwoDimensionalVectorTest, TestInfo){
    Point p1(1, 1);
    Point p2(3, 3);
    TwoDimensionalVector v1(&p1, &p2);
    ASSERT_EQ("Vector ((1.00, 1.00), (3.00, 3.00))", v1.info());
}