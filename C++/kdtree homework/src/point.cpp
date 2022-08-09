#include <cmath>
#include <ostream>
#include "primitives.h"
namespace {
    double absDouble(double b) {
        if (b < 0) {
            return -b;
        }
        return b;
    }

    double pointsDist(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
}

Point::Point(double x, double y) {
    px = x;
    py = y;
}
double Point::x() const {
    return px;
}
double Point::y() const {
    return py;
}
double Point::distance(const Point &p) const {
    return pointsDist(x(), y(), p.x(), p.y());
}
bool Point::operator<(const Point &p) const {
    if (absDouble(x() - p.x()) < 0.00001) {
        if (absDouble(y() - p.y()) < 0.00001) {
            return false;
        }
        return y() < p.y();
    }
    return x() < p.x();
}
bool Point::operator==(const Point &p) const {
    return (absDouble(x() - p.x()) < 0.00001) && (absDouble(y() - p.y()) < 0.00001);
}
bool Point::operator<=(const Point &p) const {
    return *this < p || *this == p;
}
bool Point::operator>(const Point &p) const {
    return !(*this <= p);
}
bool Point::operator>=(const Point &p) const {
    return *this > p || *this == p;
}
bool Point::operator!=(const Point &p) const {
    return !(*this == p);
}
std::ostream& operator<<(std::ostream &s, const Point &p) {
    s << "(" << p.x() << ", " << p.y() << ')';
    return s;
}