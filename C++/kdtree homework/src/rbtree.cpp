#include <set>
#include <ostream>
#include "primitives.h"
#include <vector>
#include <algorithm>



namespace  rbtree
{
    using ForwardIt = rbIterator;
    bool rbIterator::operator==(const rbIterator it) const {
        return src.size() - pos == it.src.size() - it.pos;
    }
    bool rbIterator::operator!=(const rbIterator it) const {
        return !(this->operator==(it));
    }
    Point * rbIterator::operator->() {
        return &*(src.begin() + pos);
    }
    Point rbIterator::operator*() {
        return *(src.begin() + pos);
    }
    rbIterator rbIterator::operator++(int) {
        auto ret = *this;
        pos++;
        return ret;
    }
    rbIterator rbIterator::operator++() {
        pos++;
        return *this;
    }


    bool PointSet::empty() const {
        return rb.empty();
    }
    std::size_t PointSet::size() const {
        return rb.size();
    }
    void PointSet::put(const Point & pnt) {
        rb.insert(pnt);
    }
    bool PointSet::contains(const Point & pnt) const {
        return rb.find(pnt) != rb.end();
    }
    std::pair<ForwardIt , ForwardIt> PointSet::range(const Rect & r) const {
        std::set<Point> res;
        for (Point p : rb) {
            if (r.contains(p)) {
                res.insert(p);
            }
        }
        return std::make_pair(ForwardIt(res, 0), ForwardIt(res, res.size()));
    }
    ForwardIt PointSet::begin() const {
        return ForwardIt(rb, 0);
    }
    ForwardIt PointSet::end() const {
        return ForwardIt(rb, rb.size());
    }
    std::optional<Point> PointSet::nearest(const Point &p) const {
        if (empty()) {
            return std::nullopt;
        }
        std::optional<Point> op = *rb.begin();
        double mindist = p.distance(op.value());
        for (Point px : rb) {
            if (p.distance(px) < mindist) {
                op = px;
                mindist = p.distance(px);
            }
        }
        return op;
    }
    std::pair<ForwardIt, ForwardIt> PointSet::nearest(const Point &p, std::size_t k) const {
        std::vector<Point> pnts (rb.begin(), rb.end());
        std::sort(pnts.begin(), pnts.end(),
                  [p](const Point &p1, const Point &p2) {
                      return p1.distance(p) < p2.distance(p);});
        if (k < pnts.size()) {
            pnts.resize(k);
        }
        return {ForwardIt(pnts, 0), ForwardIt(pnts, std::min(k, pnts.size()))};
    }
    std::ostream& operator<<(std::ostream &s, const rbtree::PointSet &ps) {
        for (auto p : ps) {
            s << p << ", ";
        }
        return s;
    }
}

