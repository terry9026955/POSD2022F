#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

TEST(ShapeTest, testCircleArea) {
    Point p1(0, 0);
    Point p2(1, 0);

    TwoDimensionalVector v1(&p1, &p2);

    Circle c1(&v1);
    Shape *s1 = &c1;

    ASSERT_NEAR(M_PI, s1->area(), 0.001);
}

TEST(ShapeTest, testCirclePerimeter) {
    Point p1(0, 0);
    Point p2(3, 0);
    
    TwoDimensionalVector v1(&p1, &p2);
    
    Circle c1(&v1);
    Shape *s1 = &c1;
    
    ASSERT_NEAR(3 * 2 * M_PI, s1->perimeter(), 0.001);
}

TEST(ShapeTest, testCircleInfo) {
    Point p1(0, 0);
    Point p2(1, 0);
    
    TwoDimensionalVector v1(&p1, &p2);
    
    Circle c1(&v1);
    Shape *s1 = &c1;
   
    ASSERT_EQ("Circle (Vector ((0.00, 0.00), (1.00, 0.00)))", s1->info());
}