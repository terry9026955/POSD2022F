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


