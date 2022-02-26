#include "game.hpp"

int main()
{

    Game *game = new Game();

    while (!game->GameShouldClose())
    {
        game->Tick();
    }
    return 0;
}