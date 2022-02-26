#include "snake.hpp"

Snake::Snake()
{
    segments.push_back({});
}
void Snake::Draw()
{
    for (segment &s : segments)
        DrawRectangleV(s.Pos, settings::SnakeBlockSize, settings::SnakeColor);
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
}
void Snake::ChangeDirection(bool vertical, bool turn)
{
    direction = {settings::SnakeBlockSize.x * !vertical, settings::SnakeBlockSize.x * vertical};
    this->turn = turn;
}
void Snake::AddSegment()
{
    segments.push_back(HistorySeg);
}