#include "settings.hpp"
#include <iostream>
class Snake
{
    struct segment
    {
        Vector2 Pos{settings::BoardPos};
    } HistorySeg;
    std::vector<segment> segments;

    Vector2 direction{settings::SnakeBlockSize.x, 0.0f};
    bool turn{true}; // true = +value  |  false = -value

public:
    Snake();
    void Draw();
    void Move();
    void ChangeDirection(bool, bool);

    void AddSegment();
};