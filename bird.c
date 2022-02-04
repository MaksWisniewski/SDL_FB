#include "bird.h"
#include <stdbool.h>

void birdConstructor(Bird *x) {
    x->bounds.w = 50;
    x->bounds.h = 50;
    x->bounds.x = 50;
    x->bounds.y = 50;
    x->position.x = 50;
    x->position.y = 50;
    x->gravity = 0.8;
    x->velocity = 0;
    x->lift = - 1000;
    x->isJump = false;
}

bool birdUpdate(Bird *x, double dt) {
    // grawitacja ciagnie w dool
    x->velocity += x->gravity;
    x->time_afterJump += dt;

    // skok
    if(x->isJump && (x->time_afterJump >= 0.2137)) {
        x->velocity += x->lift;
        x->time_afterJump = 0;
        x->isJump = false;
    }

    // ogramocznie predkosi spadamoa 
    x->velocity = limit(x->velocity, 300);
    x->velocity = limit(x->velocity, -300);

    x->position.y += x->velocity * dt;

    // kolizja okiennicowa
    if(x->position.y + x->bounds.h / 2 > HEIGHT) {
        x->position.y = HEIGHT - x->bounds.h / 2;
        x->velocity = 0;
        return true;
    }
    if(x->position.y + x->bounds.h / 2 < 0) {
        x->position.y = -x->bounds.h / 2;
        x->velocity = 0;
        return true;
    }

    x->bounds.x = (int) x->position.x;
    x->bounds.y = (int) x->position.y;
    return false;
}

void birdJump(Bird *x) {
    x->isJump = true;
}