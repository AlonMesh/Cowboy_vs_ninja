#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

namespace ariel {
    /**
     * Represents the location of a Character in the gameboard
     * @param x_value The x value of the Point object
     * @param y_value The y value of the Point object.
    */
    class Point {
        private:
            double x_value;
            double y_value;

        public:
            /**
             * Construct a new Point object with the specified x and y values.
             * If x_value or y_value are negative, throw an exception.
             * 
             * @param x_value The x value of the Point object.
             * @param y_value The y value of the Point object.
             * @throws std::invalid_argument If either x_value or y_value are negative.
             */
            Point(double x_value, double y_value);

            /**
             * Construct a new Point object at (0,0).
             */
            Point();

            /**
             * Calculates the distance between this point and another point.
             * 
             * @param other the other point to calculate the distance to
             * @return the distance between the two points
             */
            double distance(Point other);

            /**
             * Prints Point x and y value accurding to a format (x, y)
            */
            void print();

            /**
             * Moves this point a specified distance towards a target point.
             * 
             * @param currentPoint the current position of the point
             * @param targetPoint the target position to move towards
             * @param distance the distance to move towards the target point
             * @throws invalid_argument if the distance is negative
             * @return the new point that is at least the specified distance away from the current point and as close as possible to the target point
             */
            static Point moveTowards(Point currentPoint, Point targetPoint, int distance);

            /**
             * Determines whether a point is on the line defined by two other points.
             * 
             * @param point1 The first point that defines the line.
             * @param point2 The second point that defines the line.
             * @return true if the point is on the line, false otherwise.
             */
            bool isOnLine(Point point1, Point point2);

            /**
             * Return x value of a point
            */
            double getx();

            /**
             * Return y value of a point
            */
            double gety();
    };
}
#endif