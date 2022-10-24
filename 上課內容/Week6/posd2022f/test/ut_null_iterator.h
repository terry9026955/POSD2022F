#include "../src/null_iterator.h"

TEST(NullIteratorTest, TestIsDoneGetTrue) {
    Shape* circle = new Circle(0, 0, 1);
    Iterator *it = circle->createIterator();

    ASSERT_TRUE(it->isDone());

    delete it;
    delete circle;
}
