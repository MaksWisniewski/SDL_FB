#include "bird.h"
#include <stdbool.h>

void birdConstructor(Bird *x) {
    x->Bounds.w = x->Bounds.y = 50;
    x->self_x = x->Bounds.x = SCREEN_WIDTH / 3;
    x->self_y = x->Bounds.y = SCREEN_HEIGHT / 2;

    x->gravity = 0.2;
    x->velocity = 0;
    x->lift = -40;
    x->time_sinceJump = 0;
    x->isJump = false;
}

void birdJump(Bird *x) {
    x->isJump = true;
}

bool birdUpdate(Bird *x, double dt) {
    x->velocity += x->gravity;
    x->time_sinceJump += dt;

    if(x->isJump == true && x->time_sinceJump >= 0.25) {
        x->velocity += x->lift;
        x->time_sinceJump = 0;
        x->isJump = false;
    }

    x->self_y = x->velocity * dt;

    if(x->self_y + x->Bounds.h / 2 > SCREEN_HEIGHT) {
        x->self_y = SCREEN_HEIGHT - x->Bounds.h / 2;
        x->velocity = 0;
        return true;
    }

    if(x->self_y + x->Bounds.h / 2 < 0) {
        x->self_y = -x->Bounds.h / 2;
        x->velocity = 0;
        return true;
    }

    x->Bounds.x = (int) x->self_x;
    x->Bounds.y = (int) x->self_y;
    return false;
}
