#include "Engine/headers/Game.h"
#include "Game/headers/Constants.h"
#include "Game/headers/Paddle.h"

int main() {
    Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    Paddle paddle;
    game.AddObject(&paddle);

    game.Run();
}
