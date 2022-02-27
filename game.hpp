#include "Resources/settings.hpp"
#include "Resources/board.hpp"
#include "Resources/snake.hpp"
#include "Resources/apple.hpp"
#include "Resources/engine.hpp"

#include <string>

class Game : protected Engine<Game>
{
private:
    Board *board;
    Snake *snake;
    Apple *apple;

    bool is_Paused{false};
    float counter{0.f};
    int Points{0};

    void ReInitializeEntities();

    ///     GameState: Game     ///
    void DrawGame();
    void UpdateGame();

    ///   GameState: GameOver   ///
    void DrawGameOver();
    void UpdateGameOver();

    ///    GameState: Pause    ///
    void UpdatePause();
    void DrawPause();

public:
    Game();
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
    ~Game() noexcept;

    bool GameShouldClose() const;
    void Tick();
};