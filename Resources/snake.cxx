#include "snake.hpp"

Snake::Snake()
{
    segments.push_back({settings::BoardPos.x + settings::SnakeBlockSize, settings::BoardPos.y});
    segments.push_back({settings::BoardPos});
}
void Snake::Draw()
{
    for (segment &s : segments)
        DrawRectangleV(s.Pos, {settings::SnakeBlockSize, settings::SnakeBlockSize}, settings::SnakeColor);
}
void Snake::Move()
{
    HistorySeg = segments[segments.size() - 1];

    for (int i = segments.size() - 1; i >= 1; i--)
    {
        segments[i] = segments[i - 1];
    }
    segments[0].Pos.x += direction.x * (turn * 2 - 1);
    segments[0].Pos.y += direction.y * (turn * 2 - 1);

    if (CheckIfIsOnBoard())
    {
        segments[0].Pos.x += (settings::BoardWidth * (!turn * 2 - 1)) * (direction.x != 0.0f);
        segments[0].Pos.y += (settings::BoardHeight * (!turn * 2 - 1)) * (direction.y != 0.0f);
    }
}
void Snake::ChangeDirection(bool vertical, bool turn)
{
    if (this->vertical == vertical)
        return;

    direction = {settings::SnakeBlockSize * !vertical, settings::SnakeBlockSize * vertical};
    this->vertical = vertical;
    this->turn = turn;
}
void Snake::AddSegment()
{
    segments.push_back(HistorySeg);
}
bool Snake::CheckIfIsOnBoard()
{
    return ((segments[0].Pos.x + settings::SnakeBlockSize) > (settings::BoardPos.x + settings::BoardWidth)) ||
           ((segments[0].Pos.x) < (settings::BoardPos.x)) ||
           ((segments[0].Pos.y + settings::SnakeBlockSize) > (settings::BoardPos.y + settings::BoardHeight)) ||
           ((segments[0].Pos.y) < (settings::BoardPos.y));
}