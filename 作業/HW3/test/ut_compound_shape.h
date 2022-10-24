#include "../src/compound_shape.h"

class CompoundShapeTest : public ::testing::Test
{
protected:
    Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;
    CompoundShape *cs1, *cs2;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);

        vec1 = new TwoDimensionalVector(p1, p2);
        vec2 = new TwoDimensionalVector(p1, p3);
        vec3 = new TwoDimensionalVector(p1, p4);

        cs1 = new CompoundShape();
        cs1->addShape(new Circle(vec1));
        cs1->addShape(new Rectangle(vec1,vec2));

        cs2 = new CompoundShape();
        cs2->addShape(new Circle(vec3));
        cs2->addShape(cs1);
    }

    void TearDown() override
    {
        delete cs2;
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete vec1;
        delete vec2;
        delete vec3;
    }
};

TEST_F(CompoundShapeTest, CS1_AreaShouldBeCorrect)
{
    ASSERT_EQ(5 * 5 * M_PI + 25, cs1->area());
}

TEST_F(CompoundShapeTest, CS2_AreaShouldBeCorrect)
{
    ASSERT_EQ((5 * 5 + 3 * 3) * M_PI + 25, cs2->area());
}

TEST_F(CompoundShapeTest, CS1_PerimeterShouldBeCorrect)
{
    ASSERT_EQ(5 * 2 * M_PI + 20, cs1->perimeter());
}

TEST_F(CompoundShapeTest, CS2_PerimeterShouldBeCorrect)
{
    ASSERT_EQ((5 + 3) * 2 * M_PI + 20, cs2->perimeter());
}

TEST_F(CompoundShapeTest, InfoShouldBeCorrect)
{
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (0.00, 5.00)), Vector ((0.00, 0.00), (5.00, 0.00))))", cs1->info());
}

TEST_F(CompoundShapeTest, DeleteReference_ShouldBeCorrect)
{
    CompoundShape *tempCompound = new CompoundShape();
    Shape *c1 = new Circle(vec1);
    Shape *r1 = new Rectangle(vec1, vec2);
    tempCompound->addShape(c1);
    tempCompound->addShape(r1);
    ASSERT_EQ(5 * 5 * M_PI + 25, tempCompound->area());
    tempCompound->deleteShape(c1);
    ASSERT_EQ(25, tempCompound->area());
    delete c1;
    delete r1;
    delete tempCompound;
}

TEST_F(CompoundShapeTest, DeleteValue_ShouldBeCorrect)
{
    CompoundShape *tempCompound = new CompoundShape();
    Shape *c1 = new Circle(vec1);
    Shape *r1 = new Rectangle(vec1, vec2);
    tempCompound->addShape(c1);
    tempCompound->addShape(r1);
    ASSERT_EQ(5 * 5 * M_PI + 25, tempCompound->area());
    tempCompound->deleteShape(new Circle(vec1));
    ASSERT_EQ(25, tempCompound->area());
    delete c1;
    delete r1;
    delete tempCompound;
}

TEST_F(CompoundShapeTest, GetShapes_ShouldBeCorrect)
{
    auto shapes = cs2->shapes();
    auto it = shapes.begin();
    ASSERT_EQ(3*3*M_PI, (*it)->area());
    it++;
    ASSERT_EQ(cs1->area(), (*it)->area());
    it++;
    ASSERT_EQ(it, shapes.end());
}

TEST_F(CompoundShapeTest, GetPoints_ShouldBeCorrect)
{
    auto points = cs2->getPoints();
    // 2 circle: 2*2, 1 rec: 1*4
    ASSERT_EQ(8, points.size());
}