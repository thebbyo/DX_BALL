#ifndef POWERUP_H
#define POWERUP_H

#include "header.h"

extern float pupx_vel ;
extern float pupy_vel ;

extern SDL_Rect powerup_gameplay_rect;


void powerup_achieve(); //game_physics
void powerup_renderer(int p, int type); //game_physics

#endif
