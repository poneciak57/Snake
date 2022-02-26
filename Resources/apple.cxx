#include "apple.hpp"

Apple::Apple(int &p, std::vector<Vector2> snake) : points(p)
{
    do
    {
        int x{GetRandomValue(0, settings::BlockBoardWidth - 1)};
        int y{GetRandomValue(0, settings::BlockBoardHeight - 1)};

        Pos = {
            settings::BoardPos.x + x * settings::BlockSize,
            settings::BoardPos.y + y * settings::BlockSize};
    } while (checkIfCollide(snake));
}
Apple::~Apple()
{
    points++;
}
void Apple::Draw()
{
    DrawRectangleV(Pos, settings::BlockSizeV, settings::AppleColor);
}

Rectangle Apple::getBound()
{
    return {Pos.x, Pos.y, settings::BlockSize, settings::BlockSize};
}
bool Apple::checkIfCollide(std::vector<Vector2> snake) const
{
    for (const Vector2 &v : snake)
        if (v == Pos)
            return true;
    return false;
}