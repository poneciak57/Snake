#pragma once
#include <raylib.h>
#include <vector>

inline bool operator==(const Vector2 &v1, const Vector2 &v2)
{
    return (v1.x == v2.x) && (v1.y == v2.y);
}

namespace settings
{
    ///         Screen Specs         ///
    inline constexpr int ScreenWidth{480};
    inline constexpr int ScreenHeight{480};
    inline constexpr int FPS{160};

    ///         Blocks Specs         ///
    inline constexpr float BlockSize{20.0f};
    inline constexpr Vector2 BlockSizeV{BlockSize, BlockSize};
    inline constexpr int BlockBoardWidth{20};
    inline constexpr int BlockBoardHeight{20};

    ///      Board Boarder Specs     ///
    inline constexpr int BoardBorderThickness{10};
    inline constexpr Color BoardBorderColor{WHITE};

    ///         Board Specs         ///
    inline constexpr int BoardWidth{BlockBoardWidth * (int)BlockSize};
    inline constexpr int BoardHeight{BlockBoardHeight * (int)BlockSize};
    inline constexpr Vector2 BoardPos{40.0f, 40.0f};
    inline constexpr Color BoardColor{GRAY};

    ///         Snake Specs         ///
    inline constexpr Color SnakeColor{RED};
    inline constexpr float MoveTimer{0.5f}; //<0.25 , 0.65> - kinda playable

    ///         Apple Specs         ///
    inline constexpr Color AppleColor{GREEN};

    ///         Text Specs          ///
    inline constexpr Vector2 PointsTextPos{30.0f, 3.0f};
    inline constexpr Color PointsTextColor{WHITE};
    inline constexpr int PointsTextSize{20};

    ///         Text Specs          ///
    inline constexpr Vector2 GOTextPos{ScreenWidth / 2 - 135, ScreenHeight / 2 - 55};
    inline constexpr Color GOTextColor{WHITE};
    inline constexpr int GOTextSize{20};
}