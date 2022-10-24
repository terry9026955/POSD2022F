#include "../src/rectangle.h"

class RectangleTest : public ::testing::Test
{
protected:
    Point* _p1;
    Point* _p2;
    Point* _p3;
    TwoDimensionalVector* _v1;
    TwoDimensionalVector* _v2;
    Rectangle *_r1;

    void SetUp() override
    {
        _p1 = new Point(0, 0);
        _p2 = new Point(3, 0);
        _p3 = new Point(0, 4);
        _v1 = new TwoDimensionalVector(_p1, _p2);
        _v2 = new TwoDimensionalVector(_p1, _p3);
        _r1 = new Rectangle(_v1, _v2);
    }

    void TearDown() override
    {
        delete _p1;
        delete _p2;
        delete _p3;
        delete _v1;
        delete _v2;
        delete _r1;
    }
};

TEST_F(RectangleTest, testInitWithVerticalVectors) {
    Point p1(-2, 1);
    Point p2(1.5, 0.47);
    Point p3(-1.47, 4.5);
    TwoDimensionalVector v1(&p1, &p2);
    TwoDimensionalVector v2(&p1, &p3);
    ASSERT_NO_THROW(Rectangle(&v1, &v2));
}

TEST_F(RectangleTest, testInitWithTwoVectorsWithoutASamePoint) {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 1);
    Point p4(0, 2);
    TwoDimensionalVector v1(&p1, &p2);
    TwoDimensionalVector v2(&p3, &p4);
    ASSERT_ANY_THROW(Rectangle(&v1, &v2));
}

TEST_F(RectangleTest, testWidth) {
    ASSERT_EQ(4, _r1->width());
}

TEST_F(RectangleTest, testLength) {
    ASSERT_EQ(3, _r1->length());
}


TEST_F(RectangleTest, testArea) {
    ASSERT_EQ(12, _r1->area());
}

TEST_F(RectangleTest, testPerimeter) {
    ASSERT_EQ(14, _r1->perimeter());
}

TEST_F(RectangleTest, testInfo) {
    ASSERT_EQ("Rectangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((0.00, 0.00), (0.00, 4.00)))", _r1->info());
}

TEST_F(RectangleTest, testGetPoints1) {
    auto points = _r1->getPoints();
    ASSERT_EQ(4, points.size());
    bool b1 = false;
    bool b2 = false;
    bool b3 = false;
    bool b4 = false;
    for (auto pointPtr: points) {
        std::cout << std::string(pointPtr->info());
        if (Point(0, 0) == *pointPtr && b1 == false) {
            b1 = true;
        } else if (Point(0, 4) == *pointPtr && b2 == false) {
            b2 = true;
        } else if (Point(3, 0) == *pointPtr && b3 == false) {
            b3 = true;
        } else if (Point(3, 4) == *pointPtr && b4 == false) {
            b4 = true;
        } else {
            throw std::string(pointPtr->info());
        }
    }
    ASSERT_TRUE(b1);
    ASSERT_TRUE(b2);
    ASSERT_TRUE(b3);
    ASSERT_TRUE(b4);
}

TEST_F(RectangleTest, testGetPoints2) {
    auto v1 = new TwoDimensionalVector(_p2, _p1);
    auto v2 = new TwoDimensionalVector(_p1, _p3);
    auto r1 = new Rectangle(v1, v2);
    auto points = r1->getPoints();
    ASSERT_EQ(4, points.size());
    bool b1 = false;
    bool b2 = false;
    bool b3 = false;
    bool b4 = false;
    for (auto pointPtr: points) {
        std::cout << std::string(pointPtr->info());
        if (Point(0, 0) == *pointPtr && b1 == false) {
            b1 = true;
        } else if (Point(0, 4) == *pointPtr && b2 == false) {
            b2 = true;
        } else if (Point(3, 0) == *pointPtr && b3 == false) {
            b3 = true;
        } else if (Point(3, 4) == *pointPtr && b4 == false) {
            b4 = true;
        } else {
            throw std::string(pointPtr->info());
        }
    }
    ASSERT_TRUE(b1);
    ASSERT_TRUE(b2);
    ASSERT_TRUE(b3);
    ASSERT_TRUE(b4);
}

TEST_F(RectangleTest, testGetPoints3) {
    auto v1 = new TwoDimensionalVector(_p1, _p2);
    auto v2 = new TwoDimensionalVector(_p3, _p1);
    auto r1 = new Rectangle(v1, v2);
    auto points = r1->getPoints();
    ASSERT_EQ(4, points.size());
    bool b1 = false;
    bool b2 = false;
    bool b3 = false;
    bool b4 = false;
    for (auto pointPtr: points) {
        std::cout << std::string(pointPtr->info());
        if (Point(0, 0) == *pointPtr && b1 == false) {
            b1 = true;
        } else if (Point(0, 4) == *pointPtr && b2 == false) {
            b2 = true;
        } else if (Point(3, 0) == *pointPtr && b3 == false) {
            b3 = true;
        } else if (Point(3, 4) == *pointPtr && b4 == false) {
            b4 = true;
        } else {
            throw std::string(pointPtr->info());
        }
    }
    ASSERT_TRUE(b1);
    ASSERT_TRUE(b2);
    ASSERT_TRUE(b3);
    ASSERT_TRUE(b4);
}

TEST_F(RectangleTest, testGetPoints4) {
    auto v1 = new TwoDimensionalVector(_p2, _p1);
    auto v2 = new TwoDimensionalVector(_p3, _p1);
    auto r1 = new Rectangle(v1, v2);
    auto points = r1->getPoints();
    ASSERT_EQ(4, points.size());
    bool b1 = false;
    bool b2 = false;
    bool b3 = false;
    bool b4 = false;
    for (auto pointPtr: points) {
        std::cout << std::string(pointPtr->info());
        if (Point(0, 0) == *pointPtr && b1 == false) {
            b1 = true;
        } else if (Point(0, 4) == *pointPtr && b2 == false) {
            b2 = true;
        } else if (Point(3, 0) == *pointPtr && b3 == false) {
            b3 = true;
        } else if (Point(3, 4) == *pointPtr && b4 == false) {
            b4 = true;
        } else {
            throw std::string(pointPtr->info());
        }
    }
    ASSERT_TRUE(b1);
    ASSERT_TRUE(b2);
    ASSERT_TRUE(b3);
    ASSERT_TRUE(b4);
}