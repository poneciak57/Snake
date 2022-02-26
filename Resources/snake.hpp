#include "settings.hpp"
#include <iostream>
class Snake
{
    struct segment
    {
        Vector2 Pos{settings::BoardPos};
        Vector2 direction{settings::SnakeBlockSize.x, 0.0f};
        bool turn{true}; // true = +value  |  false = -value
    } HistorySeg;
    std::vector<segment> segments;
    void UpdateSegments();

public:
    Snake();
    void Draw();
    void Move();
    void ChangeDirection(bool, bool);

    void AddSegment();
};