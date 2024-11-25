#ifndef CASE_HPP
#define CASE_HPP

class Case {
public:
    int x, y;

    Case(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(const Case& other) const {
        return x == other.x && y == other.y;
    }
};

#endif
