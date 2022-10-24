#include "iterator.h"
#include "composite_shape.h"

ShapeIterator::ShapeIterator(CompositeShape* composite)
    :_host(composite) {}

void ShapeIterator::first() {
    _current = _host->_shapes.begin();
}

Shape * ShapeIterator::currentItem() const {
    return *_current;
}

void ShapeIterator::next() {
    _current++;    
}

bool ShapeIterator::isDone() const {
    return _current == _host->_shapes.end();
}
