#ifndef STRUCT_H
#define STRUCT_H

#include "header.h"

struct bricksStruct
{
	int x,y,dx=100,dy=35,power=0;
	bool powerup=false,show=false,r,g,b1=false,b2=false,b3=false,b4=false,b21=false,b25=false,b26=false,b27=false,b21_1,b31=false,b32=false,b33=false,b34=false,b35=false,b36=false,b37=false,b37_1=false;
};
struct texarray
{
	SDL_Texture* tex=NULL;
};
struct hscoresturct
{
	int score=0;
	char name[12]=" ";	
} ;
struct firesrect
{
	int show=0;
	SDL_Rect rec;
} ;

struct frontball
{
    int x;
    int y;
   
} ;
struct pwrupvar
{
	int hoise=0,type=0;

};
struct pwrupgplay
{
	bool type=0;
};  
extern pwrupvar power_up;
extern firesrect fire_rectarray1[100],fire_rectarray2[100];
extern frontball front[2];
extern pwrupgplay power_up_map[9];
extern texarray gbartex[4],fbartex[4],mbartex[4],mfbartex[4],poweruptex[9],powerup_blurtex[9];
extern hscoresturct highscore_array[20];
extern bricksStruct bricks[150];

#endif