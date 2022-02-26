#include "snake.hpp"

Snake::Snake()
{
    segments.push_back({settings::BoardPos.x + settings::BlockSize, settings::BoardPos.y});
    segments.push_back({settings::BoardPos});
}
void Snake::Draw()
{
    for (Vector2 &s : segments)
        DrawRectangleV(s, settings::BlockSizeV, settings::SnakeColor);
}
void Snake::Move()
{
    HistorySeg = segments.back();

    for (int i = segments.size() - 1; i >= 1; i--)
    {
        segments[i] = segments[i - 1];
    }
    segments.front().x += direction.x * (turn * 2 - 1);
    segments.front().y += direction.y * (turn * 2 - 1);

    if (checkIfIsOnBoard())
    {
        segments.front().x += (settings::BoardWidth * (!turn * 2 - 1)) * (direction.x != 0.0f);
        segments.front().y += (settings::BoardHeight * (!turn * 2 - 1)) * (direction.y != 0.0f);
    }
    isAfterMove = true;
}
void Snake::changeDirection(bool vertical, bool turn)
{
    if (this->vertical == vertical || !isAfterMove)
        return;

    direction = {settings::BlockSize * !vertical, settings::BlockSize * vertical};
    this->vertical = vertical;
    this->turn = turn;
    isAfterMove = false;
}
Rectangle Snake::getBound()
{
    return {segments.front().x, segments.front().y, settings::BlockSize, settings::BlockSize};
}

std::vector<Vector2> Snake::getSnake()
{
    return segments;
}

void Snake::AddSegment()
{
    segments.push_back(HistorySeg);
}
bool Snake::isSelfCollide()
{
    for (int i = segments.size() - 1; i >= 1; i--)
    {
        if (segments[i] == segments.front())
        {
            return true;
        }
    }
    return false;
}
bool Snake::checkIfIsOnBoard()
{
    return ((segments.front().x + settings::BlockSize) > (settings::BoardPos.x + settings::BoardWidth)) ||
           ((segments.front().x) < (settings::BoardPos.x)) ||
           ((segments.front().y + settings::BlockSize) > (settings::BoardPos.y + settings::BoardHeight)) ||
           ((segments.front().y) < (settings::BoardPos.y));
}