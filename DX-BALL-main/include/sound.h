#ifndef SOUNDS_H
#define SOUNDS_H

#include "header.h"

extern int sound,gamesound,music_run;

extern Mix_Music *main_menu_music ; //music
extern Mix_Chunk *bar_paddle_collision;
extern Mix_Chunk *ball_bricks_collision;
extern Mix_Chunk *hardbricks;
extern Mix_Chunk *fire_init;
extern Mix_Chunk *game_over_music;
extern Mix_Chunk *powerup_init_music;
extern Mix_Chunk *expand_paddle_music;
extern Mix_Chunk *shrink_paddle_music;
extern Mix_Chunk *slow_ball_music;
extern Mix_Chunk *fast_ball_music;
extern Mix_Chunk *life_laser_grab_music;
extern Mix_Chunk *score_double;
extern Mix_Chunk *level_up;


void music_load(); //data_load


#endif