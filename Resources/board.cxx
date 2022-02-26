#include "board.hpp"

Board::Board()
{
}
void Board::Draw()
{
    DrawRectangleV(settings::BoardPos, {settings::BoardWidth, settings::BoardHeight}, settings::BoardColor);
}