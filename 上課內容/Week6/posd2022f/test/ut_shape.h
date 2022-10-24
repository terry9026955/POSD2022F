#include "../src/composite_shape.h"
#include "../src/find_first_visitor.h"

TEST(CompositeShapeTest, TestArea) {
    Shape* circle = new Circle(0, 0, 1);
    Shape* square = new Square(0, 0, 2);
    Shape* shapes[] = {circle, square};
    Shape* compositeShape = new CompositeShape(shapes, 2);

    ASSERT_NEAR(M_PI + 4, compositeShape->area(), 0.001);
}

TEST(CompositeShapeTest, TestInclude) {
    Shape* circle1 = new Circle(0, 0, 1);
    Shape* circle2 = new Circle(0, 0, 2);
    Shape* shapes[] = {circle1, circle2};
    Shape* compositeShape = new CompositeShape(shapes, 2);

    ASSERT_TRUE(compositeShape->include(2, 0));
    ASSERT_TRUE(compositeShape->include(1, 0));
    ASSERT_FALSE(compositeShape->include(1, 0.5));

    delete compositeShape;
}

TEST(CompositeShapeTest, TestIterator) {
    Shape* circle1 = new Circle(0, 0, 1);
    Shape* circle2 = new Circle(0, 0, 2);
    Shape* shapes[] = {circle1, circle2};
    CompositeShape* composite_shape = new CompositeShape(shapes, 2);

    Iterator* it = composite_shape->createIterator();
    it->first();
    ASSERT_EQ(circle1, it->currentItem());

    it->next();
    ASSERT_EQ(circle2, it->currentItem());
    
    it->next();
    ASSERT_TRUE(it->isDone());

    delete composite_shape;
}

TEST(CompositeShape, TestAddShape) {
    Shape* circle1 = new Circle(0, 0, 1);
    Shape* circle2 = new Circle(0, 0, 2);
    Shape* shapes[] = {circle1, circle2};
    CompositeShape* composite_shape = new CompositeShape(shapes, 2);
    Shape* circle3 = new Circle(0, 0, 3);
    composite_shape->add( circle3 );

    Iterator* it = composite_shape->createIterator();
    it->first();
    it->next();
    it->next();
    ASSERT_EQ( circle3, it->currentItem() );

    delete composite_shape;

}


TEST(CompositeShape, TestRemoveShape) {
    Shape* circle1 = new Circle(0, 0, 1);
    Shape* circle2 = new Circle(0, 0, 2);
    Shape* shapes[] = {circle1, circle2};
    CompositeShape* composite_shape = new CompositeShape(shapes, 2);

    composite_shape->remove( circle2 );

    Iterator* it = composite_shape->createIterator();
    for ( it->first(); !it->isDone(); it->next() ) {
        ASSERT_NE( circle2, it->currentItem() );
    }

    delete composite_shape;
}

TEST(CompositeShape, FindFirstVisitor) {
    Shape* circle = new Circle(0, 0, 1);
    Shape* square = new Square(0, 0, 2);
    Shape* shapes[] = {circle, square};
    Shape* compositeShape = new CompositeShape(shapes, 2);

    FindFirstVisitor circleVisitor([](Shape* shape) {
        return shape->area() >= 3.5;
    });

    circle->accept(circleVisitor);
    ASSERT_EQ(nullptr, circleVisitor.result());

    FindFirstVisitor squareVisitor([](Shape* shape) {
        return shape->area() >= 3.5;
    });
    square->accept(squareVisitor);
    ASSERT_EQ(square, squareVisitor.result());

    FindFirstVisitor compositeShapeVisitor([](Shape* shape) {
        return shape->area() >= 3.5;
    });
    compositeShape->accept(compositeShapeVisitor);
    ASSERT_EQ(square, compositeShapeVisitor.result());

    FindFirstVisitor compositeShapeVisitor2([](Shape* shape) {
        return shape->area() >= 5;
    });
    compositeShape->accept(compositeShapeVisitor2);
    ASSERT_EQ(compositeShape, compositeShapeVisitor2.result());
}
