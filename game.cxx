#include "game.hpp"

Game::Game() : board(new Board()), snake(new Snake()), apple(new Apple(Points, snake->getSnake()))
{
    SetTargetFPS(settings::FPS);
    InitWindow(settings::ScreenWidth, settings::ScreenHeight, "Snake");

    Action[GameState::Game] = {&UpdateGame, &DrawGame, this};
    Action[GameState::GameOver] = {&UpdateGameOver, &DrawGameOver, this};
    Action[GameState::Pause] = {&UpdatePause, &DrawGame, this};
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
    Action[state].Tick();
}

void Game::ReInitializeEntities()
{
    delete board, snake, apple;
    counter = 0.0f;
    Points = 0;

    board = new Board();
    snake = new Snake();
    apple = new Apple(Points, snake->getSnake());
}

void Game::UpdateGame()
{
    counter += GetFrameTime();

    // Snake Tick //
    if (counter >= settings::MoveTimer)
    {
        snake->Move();
        counter = 0.0f;

        if (snake->isSelfCollide())
        {
            state = GameState::GameOver;
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
    {
        state = GameState::Pause;
        is_Paused = true;
    }
}
void Game::DrawGame()
{
    ClearBackground(BLACK);
    // drawing things
    board->Draw();
    snake->Draw();
    apple->Draw();
    DrawText(("Points: " + std::to_string(Points)).c_str(),
             settings::PointsTextPos.x,
             settings::PointsTextPos.y,
             settings::PointsTextSize,
             settings::PointsTextColor);
    if (is_Paused)
        DrawPause();
}

void Game::DrawGameOver()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("           Game Over\nPress \"Space\" to continue.",
             settings::GOTextPos.x,
             settings::GOTextPos.y,
             settings::GOTextSize,
             settings::GOTextColor);
    EndDrawing();
}
void Game::UpdateGameOver()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        state = GameState::Game;
        ReInitializeEntities();
    }
}

void Game::UpdatePause()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        state = GameState::Game;
        is_Paused = false;
    }
}
void Game::DrawPause()
{
    DrawRectangleV(
        {0, 0},
        {settings::ScreenWidth, settings::ScreenHeight},
        {0, 0, 0, 150});
    DrawText("             Pause\nPress \"Space\" to continue.",
             settings::GOTextPos.x,
             settings::GOTextPos.y,
             settings::GOTextSize,
             settings::GOTextColor);
}
