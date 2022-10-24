#include "find_first_visitor.h"
#include "circle.h"
#include "square.h"
#include "shape.h"
#include "composite_shape.h"
#include "iterator.h"

void FindFirstVisitor::visitCircle(Circle *circle)
{
    if (bos_(circle)) {
        result_ = circle;
    }
}

void FindFirstVisitor::visitSquare(Square *square)
{
    if (bos_(square)) {
        result_ = square;
    }
}

void FindFirstVisitor::visitCompositeShape(CompositeShape *cs)
{
    Iterator *it = cs->createIterator();
    for (it->first(); !it->isDone() && result_ == nullptr; it->next()) {
        it->currentItem()->accept(*this);
        
        // if (bos_(it->currentItem())) {
        //     result_ = it->currentItem();
        //     return;
        // }
    }
    if (result_ == nullptr && bos_(cs)) {
        result_ = cs;
    }
}

Shape *FindFirstVisitor::result()
{
    return result_;
}
