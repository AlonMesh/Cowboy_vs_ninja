#include "Point.hpp"
#include <cmath> // for sqrt()

namespace ariel {

    Point::Point(double x_value, double y_value) : x_value(x_value), y_value(y_value) {
        // if (x_value < 0 || y_value < 0) {
        //     throw std::invalid_argument("Point value's must be non-negative");
        // }
    }

    Point::Point() : x_value(0), y_value(0) {};
    
    double Point::distance(Point other) {
        return sqrt(pow((this->getx()-other.getx()), 2) + pow((this->gety()-other.gety()), 2));
    }
    
    void Point::print() {
        std::cout << "(" << this->getx() << ", " << this->gety() << ")" << std::endl;
    }
    
    Point Point::moveTowards(Point currentPoint, Point targetPoint, int distance) {
        // First check for invalid argument
        if (distance < 0) {
            throw std::invalid_argument("Distance must be non-negative number"); 
        }

        // Calculate the distance between the current point and the target point
        double dist = currentPoint.distance(targetPoint);

        // If the distance is less than the desired distance, just return the target point
        if (dist <= distance) {
            return targetPoint;
        }

        // Calculate the displacement vector between the current and target points
        double dx = targetPoint.getx() - currentPoint.getx();
        double dy = targetPoint.gety() - currentPoint.gety();

        // Calculate the unit vector of the displacement vector
        double unitDx = dx / dist;
        double unitDy = dy / dist;

        // Calculate the new x and y coordinates that are distance away from the current point
        double newX = currentPoint.getx() + (unitDx * distance);
        double newY = currentPoint.gety() + (unitDy * distance);

        // Create and return the new point
        return Point(newX, newY);
    }
    
    bool Point::isOnLine(Point point1, Point point2) {
        // Check if the point is on the line defined by point1 and point2
        // using the equation of a line: y - y1 = (y2 - y1)/(x2 - x1) * (x - x1)
        // Rearrange the equation to: (y - y1) * (x2 - x1) - (x - x1) * (y2 - y1) = 0
        int x1 = point1.getx();
        int y1 = point1.gety();
        int x2 = point2.getx();
        int y2 = point2.gety();
        int x = this->getx();
        int y = this->gety();
        return (y - y1) * (x2 - x1) - (x - x1) * (y2 - y1) == 0;
    }
    
    double Point::getx() {
        return this->x_value;
    }
    
    double Point::gety() {
        return this->y_value;
    }
}
