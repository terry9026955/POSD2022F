#pragma once

class Shape;
class Circle;
class Square;
class CompositeShape;

typedef bool (*BooleanOnShape)(Shape *shape);

class FindFirstVisitor
{
public:
    FindFirstVisitor(BooleanOnShape bos) : bos_{bos} {}
  
    void visitCircle(Circle *circle);
    
    void visitSquare(Square *square);

    void visitCompositeShape(CompositeShape * cs);

    Shape* result();

private:
    BooleanOnShape bos_;
    Shape *result_ = nullptr;
};
