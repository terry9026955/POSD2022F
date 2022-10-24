#include "../src/circle.h"
#include "../src/shape.h"

TEST(CircleTest, testArea) {
    Circle circle(0, 0, 5);

    ASSERT_NEAR(78.5, circle.area(), 0.1);
}

TEST(CircleTest, TestInclude) {
    Shape* circle = new Circle(0, 0, 5);

    ASSERT_TRUE(circle->include(5, 0));
    ASSERT_TRUE(circle->include(3, 4));
    ASSERT_FALSE(circle->include(6, 0));

    delete circle;
}

TEST(CircleTest, AddShapeToCircleShouldThrowException) {
    Shape* circle1 = new Circle(0, 0, 1);
    // ASSERT_ANY_THROW(circle1->add(new Circle(0, 0, 2)));
    try {
        circle1->add(new Circle(0, 0, 2));
        FAIL();
    } catch(std::string exception) {
        ASSERT_EQ( "cannot add shape", exception );
    }
}