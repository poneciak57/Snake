#include <raylib.h>
#include <map>
template <class T>
class Engine
{
private:
    struct TickAction
    {
        void (T::*Update)();
        void (T::*Draw)();
        T *obj;
        void Tick();
    };

protected:
    enum GameState
    {
        Game,
        GameOver,
        Pause
    };
    GameState state{GameState::Game};
    std::map<GameState, TickAction> Action;
};

template <class T>
void Engine<T>::TickAction::Tick()
{
    (obj->*Update)();

    BeginDrawing();
    (obj->*Draw)();
    EndDrawing();
}