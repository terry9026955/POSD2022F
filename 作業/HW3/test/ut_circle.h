#include "../src/circle.h"

TEST(CircleTest, Init_For_Zero_Length_Vector) {
    Point p1(0, 0);
    Point p2(0, 0);
    TwoDimensionalVector v1(&p1, &p2);
    // ASSERT_ANY_THROW(Circle(&v1));
}

TEST(CircleTest, RadiusShouldBeCorrect) {
    Point p1(0, 0);
    Point p2(3, 0);
    TwoDimensionalVector v1(&p1, &p2);
    Circle c1(&v1);
    ASSERT_EQ(3, c1.radius());
}

TEST(CircleTest, AreaShouldBeCorrect) {
    Point p1(0, 0);
    Point p2(3, 0);
    TwoDimensionalVector v1(&p1, &p2);
    Circle c1(&v1);
    ASSERT_NEAR(3*3*M_PI, c1.area(), 0.001);
}

TEST(CircleTest, PerimeterShouldBeCorrect) {
    Point p1(0, 0);
    Point p2(3, 0);
    TwoDimensionalVector v1(&p1, &p2);
    Circle c1(&v1);
    ASSERT_NEAR(3*2*M_PI, c1.perimeter(), 0.001);
}

TEST(CircleTest, InfoShouldBeCorrect) {
    Point p1(0, 0);
    Point p2(3, 0);
    TwoDimensionalVector v1(&p1, &p2);
    Circle c1(&v1);
    ASSERT_EQ("Circle (Vector ((0.00, 0.00), (3.00, 0.00)))", c1.info());
}

TEST(CircleTest, GetPointsShouldBeCorrect) {
    Point p1(0, 0);
    Point p2(3, 0);
    TwoDimensionalVector v1(&p1, &p2);
    Circle c1(&v1);
    auto points = c1.getPoints();
    ASSERT_EQ(2, points.size());
    bool b1 = false;
    bool b2 = false;
    for (auto pointPtr: points) {
        if (Point(3, 3) == *pointPtr) {
            b1 = true;
        }
        if (Point(-3, -3) == *pointPtr) {
            b2 = true;
        }
    }
    ASSERT_TRUE(b1);
    ASSERT_TRUE(b2);
}