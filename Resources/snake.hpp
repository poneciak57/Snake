#include "settings.hpp"

class Snake
{
    struct segment
    {
        Vector2 Pos;
    } HistorySeg;
    std::vector<segment> segments;

    Vector2 direction{settings::SnakeBlockSize, 0.0f};
    bool vertical{false};
    bool turn{true}; // true = +value  |  false = -value

    bool CheckIfIsOnBoard();

public:
    Snake();
    void Draw();
    void Move();
    void ChangeDirection(bool, bool);

    void AddSegment();
};