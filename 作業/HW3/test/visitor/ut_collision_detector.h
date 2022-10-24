#pragma once

#include "../../src/visitor/collision_detector.h"
#include "../../src/visitor/shape_visitor.h"
#include "../../src/shape.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/compound_shape.h"
#include <string>

TEST(ListCompoundIteratorTest, CurrentItemShouldBeCorrect)
{
    //Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;
    CompoundShape *cs1, *cs2;
    Iterator* it;

    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(0, 5);
    Point* p3 = new Point(5, 0);
    Point* p4 = new Point(0, 3);

    vec1 = new TwoDimensionalVector(p1, p2);
    vec2 = new TwoDimensionalVector(p1, p3);
    vec3 = new TwoDimensionalVector(p1, p4);

    Triangle *t = new Triangle(vec1, vec2);
    Circle *c = new Circle(vec1);
    Rectangle *r = new Rectangle(vec2, vec3);

    Shape* shapes[] = {t,r,c};
    CompoundShape* cs = new CompoundShape(shapes, 3);
    CollisionDetector *_vistor = new CollisionDetector(target);

    t->accept(_vistor);
    r->accept(_vistor);
    c->accept(_vistor);
    cs->accept(_vistor);

    std::vector<Shape *> v = _vistor->collidedShapes();
    std::vector<Shape *>::iterator v_itr = v.begin();

    ASSERT_EQ(t, *v_it);
    v_itr++;

    ASSERT_EQ(r, *v_it);
    v_itr++;

    ASSERT_EQ(c, *v_it);
    v_itr++;


}