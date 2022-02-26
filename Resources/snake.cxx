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
void Snake::UpdateSegments()
{
    for (int i = segments.size() - 1; i >= 1; i--)
    {
        segments[i].direction = segments[i - 1].direction;
        segments[i].turn = segments[i - 1].turn;
    }
}
void Snake::Move()
{
    HistorySeg = segments[segments.size() - 1];
    for (segment &s : segments)
    {
        s.Pos.x += s.direction.x * (s.turn * 2 - 1);
        s.Pos.y += s.direction.y * (s.turn * 2 - 1);
    }
    UpdateSegments();
}
void Snake::ChangeDirection(bool vertical, bool turn)
{
    segments[0].direction = {settings::SnakeBlockSize.x * !vertical, settings::SnakeBlockSize.x * vertical};
    segments[0].turn = turn;
}
void Snake::AddSegment()
{
    segments.push_back(HistorySeg);
}