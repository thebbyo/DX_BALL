#ifndef UTILS_H
#define UTILS_H

#include "header.h"


//bricks tex
extern SDL_Texture *bricks1 ;
extern SDL_Texture *bricks2 ;
extern SDL_Texture *bricks3 ;
extern SDL_Texture *bricks4 ;
extern SDL_Texture *bricks5 ;
extern SDL_Texture *bricks21 ;
extern SDL_Texture *bricks21_1 ;
extern SDL_Texture *bricks25 ;
extern SDL_Texture *bricks26 ;
extern SDL_Texture *bricks27 ;
extern SDL_Texture *bricks31 ;
extern SDL_Texture *bricks32 ;
extern SDL_Texture *bricks33 ;
extern SDL_Texture *bricks34 ;
extern SDL_Texture *bricks35 ;
extern SDL_Texture *bricks36 ;
extern SDL_Texture* bricks37;
extern SDL_Texture* bricks37_1;

bool INITIALIZE(); //utilities
SDL_Texture *DISPLAYING_SCORE(char ch[],int a,int make_null); //mainmenu
int levelup_bricks_initialization(int level); //data load
void name_write(); //utilities
void mainmenu_level_renderer(); //utilities
void ball_and_powerup_load(); //data load
void font_load(); // utilities
void lbutton(); //utilities


#endif