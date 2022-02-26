#include "game.hpp"

Game::Game()
{
    SetTargetFPS(settings::FPS);
    InitWindow(settings::ScreenWidth, settings::ScreenHeight, "Snake");
    board = new Board();
    snake = new Snake();
    apple = new Apple(Points, snake->getSnake());
    counter = 0.f;
}

Game::~Game()
{
    CloseWindow();
}

bool Game::GameShouldClose() const
{
    return WindowShouldClose();
}

void Game::Tick()
{
    Update();
    Draw();
}
void Game::Update()
{
    counter += GetFrameTime();

    // Snake Tick //
    if (counter >= settings::MoveTimer)
    {
        snake->Move();
        counter = 0.0f;

        if (snake->isSelfCollide())
        {
            // std::cout << "GAME OVER\n";
        }
        else if (CheckCollisionRecs(snake->getBound(), apple->getBound()))
        {
            delete apple;
            snake->AddSegment();
            apple = new Apple(Points, snake->getSnake());
        }
    }

    if (IsKeyPressed(KEY_S))
        snake->changeDirection(true, true);
    else if (IsKeyPressed(KEY_W))
        snake->changeDirection(true, false);
    else if (IsKeyPressed(KEY_D))
        snake->changeDirection(false, true);
    else if (IsKeyPressed(KEY_A))
        snake->changeDirection(false, false);
    else if (IsKeyPressed(KEY_SPACE))
        snake->AddSegment();
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    // drawing things
    board->Draw();
    snake->Draw();
    apple->Draw();
    DrawText(("Points: " + std::to_string(Points)).c_str(), settings::TextPos.x, settings::TextPos.y, settings::TextSize, settings::TextColor);

    EndDrawing();
}