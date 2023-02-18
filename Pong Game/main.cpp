#include "graphics.h"
#include "PongGame.h"
#include "config.h"

void update(float ms)
{
    PongGame* game = reinterpret_cast<PongGame*> (graphics::getUserData());
    game->update();
}

void draw()
{
    PongGame* game = reinterpret_cast<PongGame*> (graphics::getUserData());
    game->draw();
}

int main()
{
    PongGame obj;

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong Game");

    graphics::setUserData(&obj);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);
    
    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    obj.init();
    graphics::startMessageLoop();
    graphics::destroyWindow();
    
    return 0;
}