#include "../src/bounding_box.h"
#include <set>


class BoundingBoxTest : public ::testing::Test
{
protected:
    Point *p1, *p2, *p3, *p4;
    BoundingBox *bb1;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, -1);
        std::set<const Point*> set1{p1, p2, p3, p4};

        bb1 = new BoundingBox(set1);
    }

    void TearDown() override
    {
        delete p1;
        delete p2;
        delete p3;
        delete p4;
    }
};


TEST_F(BoundingBoxTest, CurrentItemShouldBeCorrect)
{
    ASSERT_EQ(5, bb1->max()->x());
    ASSERT_EQ(5, bb1->max()->y());
    ASSERT_EQ(0, bb1->min()->x());
    ASSERT_EQ(-1, bb1->min()->y());
}

TEST_F(BoundingBoxTest, Collision)
{
    std::set<const Point*> set2{new Point(1, 1)};
    BoundingBox bb2(set2);
    ASSERT_TRUE(bb1->collide(&bb2));
}

TEST_F(BoundingBoxTest, No_Collision)
{
    std::set<const Point*> set2{new Point(-1, -1)};
    BoundingBox bb2(set2);
    ASSERT_FALSE(bb1->collide(&bb2));
}


TEST_F(BoundingBoxTest, MaxPointShouldBeCorrect)
{
    std::set<const Point*> set2{new Point(6, 4), new Point(7, -2)};
    Point *maxPoint = bb1->calMaximumPoint(set2);
    ASSERT_EQ(7, maxPoint->x());
    ASSERT_EQ(5, maxPoint->y());
}

TEST_F(BoundingBoxTest, MinPointShouldBeCorrect)
{
    std::set<const Point*> set2{new Point(6, 4), new Point(7, -2)};
    Point *minPoint = bb1->calMinimumPoint(set2);
    ASSERT_EQ(0, minPoint->x());
    ASSERT_EQ(-2, minPoint->y());
}