#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

class ShapeTest: public ::testing::Test
{
protected:
    Point *_p1, *_p2, *_p3;
    TwoDimensionalVector *_v1, *_v2;
    Shape *_r1, *_c1;

    void SetUp() override
    {
        _p1 = new Point(0, 0);
        _p2 = new Point(3, 0);
        _p3 = new Point(0, 4);
        _v1 = new TwoDimensionalVector(_p1, _p2);
        _v2 = new TwoDimensionalVector(_p1, _p3);
        _r1 = new Rectangle(_v1, _v2);
        _c1 = new Circle(_v1);
    }

    void TearDown() override
    {
        delete _p1;
        delete _p2;
        delete _p3;
        delete _v1;
        delete _v2;
        delete _r1;
        delete _c1;
    }
};


TEST_F(ShapeTest, testArea) {
    ASSERT_NEAR(3*3*M_PI, _c1->area(), 0.001);
    ASSERT_NEAR(3*4, _r1->area(), 0.001);
}

TEST_F(ShapeTest, testPerimeter) {
    ASSERT_NEAR(3*2*M_PI, _c1->perimeter(), 0.001);
    ASSERT_NEAR(14, _r1->perimeter(), 0.001);
}

TEST_F(ShapeTest, testInfo) {
    ASSERT_EQ("Circle (Vector ((0.00, 0.00), (3.00, 0.00)))", _c1->info());
    ASSERT_EQ("Rectangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((0.00, 0.00), (0.00, 4.00)))", _r1->info());
}

TEST_F(ShapeTest, testAddShape) {
    ASSERT_ANY_THROW(_c1->addShape(_r1));
    ASSERT_ANY_THROW(_r1->addShape(_c1));
}

TEST_F(ShapeTest, testDeleteShape) {
    ASSERT_ANY_THROW(_c1->deleteShape(_r1));
    ASSERT_ANY_THROW(_r1->deleteShape(_c1));
}

TEST_F(ShapeTest, testGetShapes) {
    ASSERT_TRUE(_c1->shapes().empty());
    ASSERT_TRUE(_r1->shapes().empty());
}

// TEST_F(ShapeTest, testCreateDFSIterator) {
//     Iterator* it1 = _c1->createDFSIterator();
//     ASSERT_ANY_THROW(it1->next());
//     ASSERT_ANY_THROW(it1->currentItem());
//     ASSERT_ANY_THROW(it1->first());
//     ASSERT_TRUE(it1->isDone());
//     Iterator* it2 = _r1->createDFSIterator();
//     ASSERT_ANY_THROW(it2->next());
//     ASSERT_ANY_THROW(it2->currentItem());
//     ASSERT_ANY_THROW(it2->first());
//     ASSERT_TRUE(it2->isDone());
// }

// TEST_F(ShapeTest, testCreateBFSIterator) {
//     Iterator* it1 = _c1->createBFSIterator();
//     ASSERT_ANY_THROW(it1->next());
//     ASSERT_ANY_THROW(it1->currentItem());
//     ASSERT_ANY_THROW(it1->first());
//     ASSERT_TRUE(it1->isDone());
//     Iterator* it2 = _r1->createBFSIterator();
//     ASSERT_ANY_THROW(it2->next());
//     ASSERT_ANY_THROW(it2->currentItem());
//     ASSERT_ANY_THROW(it2->first());
//     ASSERT_TRUE(it2->isDone());
// }



