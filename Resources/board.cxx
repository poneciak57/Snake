#include "board.hpp"

Board::Board()
{
}
void Board::Draw()
{
    DrawRectangle(
        settings::BoardPos.x - settings::BoardBorderThickness,
        settings::BoardPos.y - settings::BoardBorderThickness,
        settings::BoardWidth + 2 * settings::BoardBorderThickness,
        settings::BoardHeight + 2 * settings::BoardBorderThickness,
        settings::BoardBorderColor);
    DrawRectangleV(
        settings::BoardPos,
        {settings::BoardWidth, settings::BoardHeight},
        settings::BoardColor);
}