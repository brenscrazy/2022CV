#include <memory>
#include <set>
#include <ostream>
#include "primitives.h"
#include <vector>
#include <algorithm>
#include <cmath>
namespace {
    double absDouble(double b) {
        if (b < 0) {
            return -b;
        }
        return b;
    }
}
namespace  kdtree {
        void node::getEuler(std::vector<Point> & res) const {
            if (is_null) {
                return;
            }
            this->left->getEuler(res);
            res.push_back(this->point);
            this->right->getEuler(res);
        }
        void node::constr_node(const Point &ins) {
            point = ins;
            is_null = false;
            left = std::make_shared<node>();
            right = std::make_shared<node>();
        }
        node* node::find(const Point &ins, int hgt = 0) const {
            if (is_null) {
                return const_cast<node *>(this);
            }
            if (this->point == ins) {
                return const_cast<node *>(this);
            }
            if ((hgt % 2 == 0 && ins.x() < this->point.x()) || (hgt % 2 == 1 && ins.y() < this->point.y())) {
                return this->left->find(ins, hgt + 1);
            } else {
                return this->right->find(ins, hgt + 1);
            }
        }
        bool node::insert(const Point & ins) {
            auto res = find(ins);
            if (res->is_null) {
                res->constr_node(ins);
                return true;
            }
            return false;
        }
        bool node::contains(const Point & finding) const {
            auto res = find(finding);
            return !res->is_null;

        }
        void node::range(const Rect &rect, std::vector<Point> &res, int h = 0) const {

            if (is_null) {
                return;
            }
            if (rect.contains(this->point)) {
                res.push_back(this->point);
            }
            double c, rmin, rmax;
            if (h % 2 == 0) {
                c = this->point.x();
                rmin = rect.xmin();
                rmax = rect.xmax();
            } else {
                c = this->point.y();
                rmin = rect.ymin();
                rmax = rect.ymax();
            }
            if (rmin <= c && c <= rmax) {
                left->range(rect, res, h + 1);
                right->range(rect, res, h + 1);
            } else if (rmax < c) {
                left->range(rect, res, h + 1);
            } else if (c < rmin) {
                right->range(rect, res, h + 1);
            }
        }
        std::pair<Point, double> node::closest(const Point & pnt, double dist = 1e9, Point curpoint = Point(), int h = 0) const {
            if (!is_null) {
                if (pnt.distance(this->point) < dist) {
                    dist = pnt.distance(this->point);
                    curpoint = this->point;
                }
                double c, kdc;
                if (h % 2 == 0) {
                    c = pnt.x();
                    kdc = this->point.x();
                } else {
                    c = pnt.y();
                    kdc = this->point.y();
                }
                std::shared_ptr<node> fst;
                std::shared_ptr<node> snd;
                if (c < kdc) {
                    fst = this->left;
                    snd = this->right;
                } else {
                    fst = this->right;
                    snd = this->left;
                }
                auto k = fst->closest(pnt, dist, curpoint, h++);
                if (k.second < dist) {
                    dist = k.second;
                    curpoint = k.first;
                }
                if (absDouble(c - kdc) < dist) {
                    auto l = snd->closest(pnt, dist, curpoint, h++);
                    if (l.second < dist) {
                        dist = l.second;
                        curpoint = l.first;
                    }
                }
        }
            return {curpoint, dist};
    }

    using ForwardIt = kdIterator;
    bool kdIterator::operator==(const kdIterator& it) const {
        return src.size() - pos == it.src.size() - it.pos;
    }
    bool kdIterator::operator!=(const kdIterator& it) const {
        return !(this->operator==(it));
    }
    Point kdIterator::operator*() {
        return *(src.begin() + pos);
    }
    kdIterator kdIterator::operator++(int) {
        auto ret = *this;
        pos++;
        return ret;
    }
    kdIterator kdIterator::operator++() {
        pos++;
        return *this;
    }
    Point * kdIterator::operator->() {
        return &*(src.begin() + pos);
    }
    bool PointSet::empty() const {
        return kd.is_null;
    }
    std::size_t PointSet::size() const {
        return len;
    }
    void PointSet::put(const Point & pnt) {
        bool ch = kd.insert(pnt);
        if (ch) {
            len++;
        }
    }
    bool PointSet::contains(const Point & pnt) const {
        return kd.contains(pnt);
    }
    std::pair<ForwardIt , ForwardIt> PointSet::range(const Rect & r) const {
        std::vector<Point> res;
        kd.range(r, res);
        return {ForwardIt(res, 0), ForwardIt(res, res.size())} ;
    }
    ForwardIt PointSet::begin() const {
        std::vector<Point> res;
        kd.getEuler(res);
        return ForwardIt(res, 0);
    }
    ForwardIt PointSet::end() const {
        return ForwardIt();
    }
    std::optional<Point> PointSet::nearest(const Point &p) const {
        if (empty()) {
            return std::nullopt;
        }
        auto pr = kd.closest(p);
        return pr.first;
    }
    std::pair<ForwardIt, ForwardIt> PointSet::nearest(const Point &p, std::size_t k) const {
        std::vector<Point> pnts;
        kd.getEuler(pnts);
        std::sort(pnts.begin(), pnts.end(),
                  [p](const Point &p1, const Point &p2) {
                      return p1.distance(p) < p2.distance(p);});
        std::vector<Point> ans;
        for (size_t i = 0; i < k && i < pnts.size(); i++) {
            ans.push_back(pnts[i]);
        }
        return {ForwardIt(ans, 0), ForwardIt(ans, ans.size())};
    }
    std::ostream& operator<<(std::ostream &s, const rbtree::PointSet &ps) {
        for (auto p : ps) {
            s << p << ", ";
        }
        return s;
    }
}

