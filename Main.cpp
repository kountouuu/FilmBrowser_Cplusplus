#include "graphics.h"
#include "scancodes.h"
#include "Platform.h"
#include "config.h"
#include "Movie.h"
#include <iostream>


void update(float ms)
{
    Platform* pltfrm = reinterpret_cast<Platform*>(graphics::getUserData());
    pltfrm->update();

}


void draw()
{
    Platform* pltfrm = reinterpret_cast<Platform*>(graphics::getUserData());
    pltfrm->draw();
}

int main()
{
    Platform myplatform;
    
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "StreamLand");

    graphics::setUserData(&myplatform);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    myplatform.init();
    graphics::startMessageLoop();

    return 0;
}