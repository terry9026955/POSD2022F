#pragma once 
#include <list>
class Shape;

class CompositeShape;

class Iterator {
public:
    virtual ~Iterator() {}
    virtual void first() {}
    virtual Shape * currentItem() const {
        return nullptr;
    }
    virtual void next() {}
    virtual bool isDone() const{
        return true;
    }
};

class ShapeIterator : public Iterator {
public:
    ShapeIterator(CompositeShape* composite);
    void first();
    Shape * currentItem() const;
    void next();
    bool isDone() const;

private:
    CompositeShape* const _host;
    std::list<Shape *>::iterator _current;
};