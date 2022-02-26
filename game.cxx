#include "game.hpp"

Game::Game()
{
    SetTargetFPS(settings::FPS);
    InitWindow(settings::ScreenWidth, settings::ScreenHeight, "Snake");
    board = new Board();
    snake = new Snake();
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
    if (counter >= settings::MoveTimer)
    {
        snake->Move();
        counter = 0.0f;
    }
    if (IsKeyPressed(KEY_S))
        snake->ChangeDirection(true, true);
    else if (IsKeyPressed(KEY_W))
        snake->ChangeDirection(true, false);
    else if (IsKeyPressed(KEY_D))
        snake->ChangeDirection(false, true);
    else if (IsKeyPressed(KEY_A))
        snake->ChangeDirection(false, false);
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

    EndDrawing();
}