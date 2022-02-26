#pragma once
#include <raylib.h>
#include <vector>
namespace settings
{
    inline constexpr int ScreenWidth{400};
    inline constexpr int ScreenHeight{400};
    inline constexpr int FPS{60};

    inline constexpr int BoardWidth{360};
    inline constexpr int BoardHeight{360};
    inline constexpr Vector2 BoardPos{20.0f, 20.0f};
    inline constexpr Color BoardColor{GRAY};

    inline constexpr Vector2 SnakeBlockSize{15.0f, 15.0f};
    inline constexpr Color SnakeColor{RED};
    inline constexpr float MoveTimer{0.5f}; //<0.25 , 0.65> - kinda playable

}