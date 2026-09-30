#include "point.h"
#include <sstream>
#include <iomanip>

Point::Point() : _x(0.0), _y(0.0) {}

Point::Point(double x, double y) : _x(x), _y(y) {}

double Point::GetX() const {
    return _x;
}

double Point::GetY() const {
    return _y;
}

double Point::Distance(const Point& p) const {
    double dx = _x - p._x;
    double dy = _y - p._y;
    return sqrt(dx * dx + dy * dy);
}

std::string Point::ToString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << "(" << _x << ", " << _y << ")";
    return oss.str();
}