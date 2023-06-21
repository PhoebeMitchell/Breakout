#include "Engine/headers/Game.h"
#include "Game/headers/Constants.h"
#include "Game/headers/Paddle.h"
#include "Game/headers/Ball.h"
#include "Game/headers/Block.h"

int main() {
    Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    auto physics = game.GetPhysics();

    Paddle paddle(physics->GetWorld());
    game.AddObject(&paddle);

    Ball ball(physics->GetWorld());
    game.AddObject(&ball);

    std::unique_ptr<Block> blocks[COLUMNS][ROWS];

    for (int x = 0; x < COLUMNS; x++) {
        for (int y = 0; y < ROWS; y++) {
            blocks[x][y] = std::make_unique<Block>(physics->GetWorld(), sf::Color::White);
            blocks[x][y]->SetPosition({x * Block::WIDTH, ROW_START_POSITION + y * Block::HEIGHT});
            game.AddObject(blocks[x][y].get());
        }
    }

    game.Run();
}
