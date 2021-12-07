#ifndef UTIL_HPP
#define UTIL_HPP

enum class Direction
{
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    NONE = 4
};

class Coordinates
{
public:
    Coordinates() = default;
    Coordinates(int const &x, int const &y) : _x(x), _y(y) {}
    Coordinates(Coordinates const &coordo) : _x(coordo.x()),
                                             _y(coordo.y())
    {
    }

    Coordinates &operator=(Coordinates const &coordinates)
    {
        _x = coordinates.x();
        _y = coordinates.y();
        return *this;
    }

    ~Coordinates() = default;

    inline int x() const { return _x; }
    inline int y() const { return _y; }

    void setX(int const &x) { _x = x; }
    void setY(int const &y) { _y = y; }

private:
    int _x;
    int _y;
};

#endif