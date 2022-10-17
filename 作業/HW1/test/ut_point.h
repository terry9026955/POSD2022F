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




