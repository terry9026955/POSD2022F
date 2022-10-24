#include "../src/point.h"

TEST(PointTest, testInfo) {
    Point point(-4.59, -3.47);
    ASSERT_EQ("(-4.59, -3.47)", point.info());
}

TEST(PointTest, testEQ_x){
    Point point(-4.59, -3.47);
    ASSERT_EQ(-4.59, point.x());
    ASSERT_EQ(-3.47, point.y());
}

TEST(PointTest, testEQ_y){
    Point point(-4.59, -3.47);
    ASSERT_EQ(-3.47, point.y());
}

TEST(PointTest, testEQ_Of_2Point) {
    Point point1(3.123, 4.321);
    Point point2(3.123, 4.321);
    ASSERT_TRUE(point1==point2);
}

TEST(PointTest, testGet) {
    Point point(4.444, 5.555);
    ASSERT_EQ(4.444, point.x());
    ASSERT_EQ(5.555, point.y());
}


TEST(PointTest, testSubtract) {
    Point point1(1.0, 2.0);
    Point point2(2.0, 1.0);
    ASSERT_EQ(Point(-1.0, 1.0), point1 - point2);
}

TEST(PointTest, testAdd) {
    Point point1(1.0, 2.0);
    Point point2(2.0, 1.0);
    ASSERT_EQ(Point(3.0, 3.0), point1+point2);
}





