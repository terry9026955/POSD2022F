#pragma once

#include "shape_visitor.h"
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include "../bounding_box.h"
#include "../iterator/factory/list_iterator_factory.h"
#include <vector>

class CollisionDetector : public ShapeVisitor {
public:
    CollisionDetector(Shape *shape) {
        _targetBoundingBox = new BoundingBox(shape->getPoints());
    }

    void visitCircle(Circle *circle) override {
        if (_targetBoundingBox->collide(new BoundingBox(circle->getPoints()))) {
            _collideResult.push_back(circle);
        };
    }

    void visitTriangle(Triangle *triangle) override {
        if (_targetBoundingBox->collide(new BoundingBox(triangle->getPoints()))) {
            _collideResult.push_back(triangle);
        };
    }

    void visitRectangle(Rectangle *rectangle) override {
        if (_targetBoundingBox->collide(new BoundingBox(rectangle->getPoints()))) {
            _collideResult.push_back(rectangle);
        };
    }

    void visitCompoundShape(CompoundShape *compoundShape) override {
        if (_targetBoundingBox->collide(new BoundingBox(compoundShape->getPoints()))) {
            
            for (auto it = compoundShape->createIterator(new ListIteratorFactory()); !it->isDone(); it->next()){
                it->currentItem()->accept(this);
            }
        };
    }

    std::vector<Shape *> collidedShapes() const {
        return _collideResult;
    }
    
private:
    std::vector<Shape *> _collideResult;
    BoundingBox *_targetBoundingBox;
};