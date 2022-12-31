#ifndef PRE_H
#define PRE_H

#include "header.h"

#define WINDOW_WIDTH (1800)
#define WINDOW_HEIGHT (980)
#define SCROLL_SPEED (900)
#define POWERUP_SPEED (0)
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
#define abs(a) (a>=0)?a:-a
// float min(float x, float y);
// float max(float x, float y);


extern Uint32 render_flags;
extern SDL_Renderer* rend;
extern SDL_Window* win;
extern SDL_Surface* surface;
extern SDL_Texture* gameover_tex;


extern SDL_Texture *tex,*tex2,*liferend;
extern SDL_Rect background,level_background,ball,powerup_rec,bar;

extern SDL_Texture* background1,*background2,*background3,*level1_back,*level2_back,*level3_back;

//game var
extern int close,score,pause,gameover ,mainmenu,first_move,firehoise,first_bounce, bar_anim,fire_left; //gameoverflag;
extern int mbar,gbar,fbar,mfbar; //bar anim
extern float rect_x,pup_x, rect_y,pup_y, x_pos;





#endif
