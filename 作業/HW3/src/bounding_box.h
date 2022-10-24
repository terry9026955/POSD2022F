#pragma once

#include <set>
#include <string>
#include "shape.h"

class BoundingBox
{
private:
    Point *_max;
    Point *_min;

public:
    BoundingBox(std::set<const Point *> points) {
        if (points.empty()) {
            throw std::string("bounding box should contain at least one point");
        }

        double maxX, maxY, minX, minY;
        bool firstTime = true;
        
        for (auto point: points) {
            if (firstTime) {
                maxX = point->x();
                maxY = point->y();
                minX = point->x();
                minY = point->y();
                firstTime = false;
            } else {
                if (maxX < point->x()) {
                    maxX = point->x();
                } else if (minX > point->x()) {
                    minX = point->x();
                }
                if (maxY < point->y()) {
                    maxY = point->y();
                } else if (minY > point->y()) {
                    minY = point->y();
                }
            }
        }

        _max = new Point(maxX, maxY);
        _min = new Point(minX, minY);
    }


    Point *calMaximumPoint(const std::set<const Point *> points) {
        double maxX, maxY;
        maxX = _max->x();
        maxY = _max->y();

        for (auto point: points) {
            if (maxX < point->x()) {
                maxX = point->x();
            } 

            if (maxY < point->y()) {
                maxY = point->y();
            } 
        }

        return new Point(maxX, maxY);
    }


    Point *calMinimumPoint(const std::set<const Point *> points) {
        double minX, minY;
        minX = _min->x();
        minY = _min->y();

        for (auto point: points) {
            if (minX > point->x()) {
                minX = point->x();
            }
            if (minY > point->y()) {
                minY = point->y();
            }
        }
        
        return new Point(minX, minY);
    }

    const Point *max() {
        return _max;
    }

    const Point *min() {
        return _min;
    }

    bool collide(BoundingBox *box) {
        return !(_max->x() < box->min()->x() || _min->x() > box->max()->x() || _max->y() < box->min()->y() || _min->y() > box->max()->y());
    }
};