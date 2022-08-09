#include <cmath>
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

double Rect::xmax() const {
    return rt.x();
}
double Rect::xmin() const {
    return lb.x();
}
double Rect::ymax() const {
    return rt.y();
}
double Rect::ymin() const {
    return lb.y();
}
double Rect::distance(const Point &p) const {
    if (contains(p)) {
        return 0;
    }
    if (xmin() <= p.x() && p.x() <= xmax()) {
        return std::min(absDouble(p.y() - ymin()), absDouble(p.y() - ymax()));
    }
    if (ymin() <= p.y() && p.y() <= ymax()) {
        return std::min(absDouble(p.x() - xmax()), absDouble(p.x() - xmin()));
    }
    return std::min(std::min(pointsDist(p.x(), p.y(), xmin(), ymin()),
                             pointsDist(p.x(), p.y(), xmin(), ymax())),
                    std::min(pointsDist(p.x(), p.y(), xmax(), ymin()),
                             pointsDist(p.x(), p.y(), xmax(), ymax())));
}
bool Rect::contains(const Point &p) const {
    return xmin() <= p.x() && p.x() <= xmax() &&
           ymin() <= p.y() && p.y() <= ymax();
}
bool Rect::intersects(const Rect &r) const {
    return r.contains(lb) || r.contains(rt) ||
           contains(r.lb) || contains(r.rt);
}