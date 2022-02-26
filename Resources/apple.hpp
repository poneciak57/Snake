#include "settings.hpp"
class Apple
{
private:
    Vector2 Pos;
    int &points;
    bool checkIfCollide(std::vector<Vector2>) const;

public:
    Apple(int &, std::vector<Vector2>);
    ~Apple();
    void Draw();
    Rectangle getBound();
};