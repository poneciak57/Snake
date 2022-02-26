#pragma once
#include <raylib.h>
#include <vector>
namespace settings
{
    inline constexpr int ScreenWidth{480};
    inline constexpr int ScreenHeight{480};
    inline constexpr int FPS{160};

    inline constexpr int BoardWidth{400};
    inline constexpr int BoardHeight{400};
    inline constexpr Vector2 BoardPos{40.0f, 40.0f};
    inline constexpr Color BoardColor{GRAY};

    inline constexpr float SnakeBlockSize{20.0f};
    inline constexpr Color SnakeColor{RED};
    inline constexpr float MoveTimer{0.5f}; //<0.25 , 0.65> - kinda playable

}