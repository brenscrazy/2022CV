#pragma once
#include <set>
#include <vector>
#include <memory>
class Point {
public:
    Point() = default;
	Point(double x, double y);

	double x() const;
	double y() const;
	double distance(const Point &) const;

	bool operator< (const Point &) const;
	bool operator> (const Point &) const;
	bool operator<= (const Point &) const;
	bool operator>= (const Point &) const;
	bool operator== (const Point &) const;
	bool operator!= (const Point &) const;

    friend std::ostream & operator << (std::ostream &, const Point &) ;

private:
    double px, py;

};

class Rect {
public:

	Rect(const Point & left_bottom, const Point & right_top)
    {
	    lb = left_bottom;
        rt = right_top;
    };

	double xmin() const;
	double ymin() const;
	double xmax() const;
	double ymax() const;
	double distance(const Point & p) const;

	bool contains(const Point & p) const;
	bool intersects(const Rect &) const;

private:
    Point lb;
    Point rt;
};

namespace rbtree {
class rbIterator : public std::iterator<std::forward_iterator_tag, Point> {
public:
    rbIterator() = default;
    rbIterator(const std::set<Point> & s, int pos) {
        src = std::vector<Point>(s.begin(), s.end());
        this->pos = pos;
    }
    rbIterator(const std::vector<Point> & s, int pos) {
        src = s;
        this->pos = pos;
    }
    Point * operator-> ();
    bool operator== (const rbIterator it) const ;
    bool operator!= (const rbIterator it) const ;
    Point operator* ();
    rbIterator operator++(int);
    rbIterator operator++();
private:
    std::vector<Point> src;
    int pos = 0;
};


class PointSet {
public:

    using ForwardIt = rbIterator;
    PointSet() = default;

    bool empty() const;
    std::size_t size() const;
    void put(const Point &);
    bool contains(const Point &) const;

    // second iterator points to an element out of range
    std::pair<ForwardIt, ForwardIt> range(const Rect &) const;
    ForwardIt begin() const;
    ForwardIt end() const;

    std::optional<Point> nearest(const Point &) const;
    // second iterator points to an element out of range
    std::pair<ForwardIt, ForwardIt> nearest(const Point & p, std::size_t k) const;

    friend std::ostream & operator << (std::ostream &, const PointSet &);

private:
    std::set<Point> rb;

};

}

namespace kdtree {
    class kdIterator : public std::iterator<std::forward_iterator_tag, Point> {
    public:
        kdIterator() = default;
        kdIterator(const std::vector<Point> & s, int pos) {
            src = s;
            this->pos = pos;
        }
        bool operator== (const kdIterator& it) const ;
        bool operator!= (const kdIterator& it) const ;
        Point operator* ();
        kdIterator operator++(int);
        kdIterator operator++();
        Point * operator-> ();
    private:
        std::vector<Point> src;
        int pos = 0;
    };

    class node {
        public:
            node() = default;
            node(Point p) {
                point = p;
                is_null = false;
                left = nullptr;
                right = nullptr;
            }

            std::shared_ptr<node> left;
            std::shared_ptr<node> right;
            Point point;
            void getEuler(std::vector<Point> & res) const;
            bool insert(const Point & ins);
            bool contains(const Point & finding) const;
            void range(const Rect & rect,std::vector<Point> & res, int h) const;
            std::pair<Point, double> closest(const Point & pnt, double mindist, Point curpoint, int h) const;
            bool is_null = true;

        private:
            void constr_node(const Point & ins);
            node* find(const Point & ins, int hgt) const;

        };
    class PointSet {
public:

    using ForwardIt = kdIterator;

    PointSet() = default;

    bool empty() const;
    std::size_t size() const;
    void put(const Point &);
    bool contains(const Point &) const;

    std::pair<ForwardIt, ForwardIt> range(const Rect &) const;
    ForwardIt begin() const;
    ForwardIt end() const;

    std::optional<Point> nearest(const Point &) const;
    std::pair<ForwardIt, ForwardIt> nearest(const Point & p, std::size_t k) const;

    friend std::ostream & operator << (std::ostream &, const PointSet &);
    private:
       node kd;
       int len = 0;

};
}
