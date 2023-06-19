#include "Engine/headers/Game.h"
#include "Game/headers/Constants.h"
#include "Game/headers/Paddle.h"

int main() {
    Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    auto physics = game.GetPhysics();

    Paddle paddle(physics->GetWorld());
    game.AddObject(&paddle);

    game.Run();
}
