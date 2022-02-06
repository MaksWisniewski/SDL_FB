#include "pipe.h"
#include <stdlib.h>

void newPipe(Pipe *p) {
    p->self_x = SCREEN_WIDTH;
    int d = rand()%(SCREEN_HEIGHT-200)+100;

    p->botHeight = SCREEN_HEIGHT - (d + p->free / 2);
    p->topHeight = d - p->free / 2;

    p->botBounds.x = p->self_x;
    p->botBounds.y = d + p->free / 2;
    p->botBounds.w = p->self_width;
    p->botBounds.h = p->self_height;

    p->topBounds.x = p->self_x;
    p->topBounds.y = d - p->free / 2 - p->self_height;
    p->topBounds.w = p->self_width;
    p->topBounds.h = p->self_height;
}

void pipeConstructor(Pipe *p) {
    p->self_width = 70;
    p->self_height = 300;
    p->velocity = 50;
    p->isActive = false;
    p->free = 200;

    newPipe(p);
}

void pipeUpdate(Pipe *p, double dt) {
    if(p->isActive == false)    return;

    p->self_x -= p->velocity * dt;
    
    p->topBounds.x = p->self_x;
    p->botBounds.x = p->self_x;

    if(p->self_x + p->self_width < 0) {
        p->isActive = false;
        newPipe(p);
    }
}
