#include <algorithm>
#include "../src/circle.h"
#include "../src/square.h"

class SortTest : public ::testing::Test {
protected:
    void SetUp() override {
        intArray[0] = 3;
        intArray[1] = 6;
        intArray[2] = 4;
        intArray[3] = 5;
        intArray[4] = 1;
        intArray[5] = 2;

        c1 = new Circle(0, 0, 1);
        c2 = new Circle(0, 0, 2);
        c3 = new Circle(0, 0, 3);

        circleArray[0] = c2;
        circleArray[1] = c1;
        circleArray[2] = c3;
    }
    void TearDown() override {
        // delete c1;
        // delete c2;
        // delete c3;
    }

    int intArray[6]; 
    Circle* c1;
    Circle* c2;
    Circle* c3;
    Circle* circleArray[3];
};

// Test fixture
TEST_F(SortTest, IntAscending) {
    // int intArray[] = {3, 6, 4, 5, 1, 2};

    std::sort(intArray, intArray+6);

    ASSERT_EQ(1, intArray[0]);
    ASSERT_EQ(2, intArray[1]);
    ASSERT_EQ(3, intArray[2]);
    ASSERT_EQ(4, intArray[3]);
    ASSERT_EQ(5, intArray[4]);
    ASSERT_EQ(6, intArray[5]);
}

TEST_F(SortTest, IntDescendingWithLambda) {
    std::sort(intArray, intArray+6, [](int a, int b) -> bool {
        return a > b;
    });

    ASSERT_EQ(6, intArray[0]);
    ASSERT_EQ(5, intArray[1]);
    ASSERT_EQ(4, intArray[2]);
    ASSERT_EQ(3, intArray[3]);
    ASSERT_EQ(2, intArray[4]);
    ASSERT_EQ(1, intArray[5]);
}

bool greaterThan(int a, int b) {
    return a > b;
}

TEST_F(SortTest, IntDescendingWithFunction) {

    std::sort(intArray, intArray+6, greaterThan);

    ASSERT_EQ(6, intArray[0]);
    ASSERT_EQ(5, intArray[1]);
    ASSERT_EQ(4, intArray[2]);
    ASSERT_EQ(3, intArray[3]);
    ASSERT_EQ(2, intArray[4]);
    ASSERT_EQ(1, intArray[5]);
}

class GreaterThan {
public:
    bool operator() (int a, int b) {
        return a > b;
    }
};

// Functor: function like object
TEST_F(SortTest, IntDescendingWithFunctor) {

    std::sort(intArray, intArray+6, GreaterThan());

    ASSERT_EQ(6, intArray[0]);
    ASSERT_EQ(5, intArray[1]);
    ASSERT_EQ(4, intArray[2]);
    ASSERT_EQ(3, intArray[3]);
    ASSERT_EQ(2, intArray[4]);
    ASSERT_EQ(1, intArray[5]);
}

TEST_F(SortTest, CircleDescendingWithArea) {
    std::sort(circleArray, circleArray+3, [](Circle* a, Circle* b) -> bool {
        return a->area() > b->area();
    });

    ASSERT_EQ(c3, circleArray[0]);
    ASSERT_EQ(c2, circleArray[1]);
    ASSERT_EQ(c1, circleArray[2]);
}

TEST_F(SortTest, SquareAndCircleAscendingWithArea) {
    Square* s1 = new Square(0, 0, 1);
    Square* s2 = new Square(0, 0, 2);
    Circle* c = new Circle(0, 0, 10);

    Shape* shapeArray[] = {s2, c, s1};

    std::sort(shapeArray, shapeArray+3, [](Shape* a, Shape* b) -> bool {
        return a->area() < b->area();
    });

    ASSERT_EQ(s1, shapeArray[0]);
    ASSERT_EQ(s2, shapeArray[1]);
    ASSERT_EQ(c, shapeArray[2]);

    // delete s1;
    // delete s2;
    // delete c;
}