#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
public:
    Point();
    Point(double x, double y);
    double GetX() const;
    double GetY() const;
    double Distance(const Point& p) const;
    std::string ToString() const;
private:
    double _x;
    double _y;
};

#endif // POINT_H