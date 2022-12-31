#ifndef GAMEPHYSICS_H
#define GAMEPHYSICS_H

#include "header.h"

//gameplay
extern double dx,dy,BALL_SPEED,theta; //ball speed direction
extern float pspeed,x_vel, y_vel;
extern int life,level,fspeed,sspeed,epaddle,spaddle,totalbricks,ball_move,bricks_showed;
extern int scr_in;
//gameplay 
//ball speed change utilities.cpp and data load.cpp
void game_physics(); //game_physics
void collision(); //game_physics
void ball_fall_paddle_collision(); //game_physics
#endif