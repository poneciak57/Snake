#include "settings.hpp"

class Snake
{
private:
    Vector2 HistorySeg;
    std::vector<Vector2> segments;

    Vector2 direction{settings::BlockSize, 0.0f};
    bool vertical{false};
    bool turn{true}; // true = +value  |  false = -value

    bool isAfterMove{true};
    bool checkIfIsOnBoard();

public:
    Snake();
    void Draw();
    void Move();

    void changeDirection(bool, bool);

    bool isSelfCollide();
    Rectangle getBound();
    std::vector<Vector2> getSnake();
    void AddSegment();
};