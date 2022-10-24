#pragma once

#include "iterator.h"
#include "../shape.h"
#include <list>
#include <iostream>
#include <queue>

class CompoundShape;

template<class ForwardIterator>

// BFS by List(or Queue) 寫法
class BFSCompoundIterator : public Iterator
{
public:
    BFSCompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end) {
        first();
    }

    void first() override {   
        // To clear 
        std::list<Shape*> empty;    // queue
        std::swap(_shapesQueue, empty);

        _shapesQueue = {};

        for(ForwardIterator it = _begin; it != _end; ++it) {
            _shapesQueue.push_back(*it);    // queue.push()
        }
    }

    Shape* currentItem() const override {
        if(!isDone()) {
            return _shapesQueue.front();    // queue.front()
        } else {
            throw std::string("The element is done at the end of the point");
        }
    }

    void next() override {
        if(isDone()) {
            throw std::string("No next element can iterate");      
        } 
        
        for(auto shapeIt: _shapesQueue.front()->shapes()){
            _shapesQueue.push_back(shapeIt);    // queue.push()
        }

        _shapesQueue.pop_front();   // queue.pop()
    }

    bool isDone() const override {
        return _shapesQueue.empty();
    }

private:
    ForwardIterator _begin;
    ForwardIterator _end;
    // ForwardIterator _current;
    std::list<Shape*> _shapesQueue;
};