#include "../src/square.h"

TEST(SquareTest, area) {
    Square s(0, 0, 3.1);
    
    ASSERT_NEAR(9.61, s.area(), 0.001);
}