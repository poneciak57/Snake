#include <raylib.h>
#include "Resources/settings.hpp"
#include "Resources/board.hpp"
#include "Resources/snake.hpp"
#include "Resources/apple.hpp"

#include <string>

class Game
{
private:
    Board *board;
    Snake *snake;
    Apple *apple;

    float counter;
    int Points;

public:
    Game();
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
    ~Game() noexcept;

    bool GameShouldClose() const;
    void Tick();

private:
    void Draw();
    void Update();
};