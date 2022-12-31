#include "header.h"
float x_vel = BALL_SPEED;
float y_vel = BALL_SPEED;
int ball_move = 0, bricks_showed = 126;
int bar_anim = 0;
double dx = 0, dy = 0;
float pspeed = 1.0;
int life = 3, level = 1, fspeed = 0, sspeed = 0, epaddle = 0, spaddle = 0;
int mbar = 1, gbar = 0, fbar = 0, mfbar = 0;
int gameover = 0, mainmenu = 1, first_move = 0, firehoise = 0, first_bounce = 0; //gameoverflag
float rect_x, pup_x, rect_y, pup_y, x_pos;
SDL_Rect background, level_background, ball, powerup_rec, bar;
SDL_Texture *liferend = NULL;
int close = 0, sound = 1, music_run = 1, gamesound = 1, score = 0, pause = 0;
double BALL_SPEED = 15, theta = 30;
int totalbricks = 126;
pwrupvar power_up;
firesrect fire_rectarray1[100], fire_rectarray2[100];
frontball front[2];
pwrupgplay power_up_map[9];
texarray gbartex[4], fbartex[4], mbartex[4], mfbartex[4], poweruptex[9], powerup_blurtex[9];
hscoresturct highscore_array[20];
bricksStruct bricks[150];
Uint32 render_flags;
SDL_Renderer *rend = NULL;
SDL_Window *win = NULL;
SDL_Surface *surface = NULL;
SDL_Texture *tex = NULL;
SDL_Texture *tex2 = NULL;

Mix_Music *main_menu_music = NULL; //music
Mix_Chunk *bar_paddle_collision = NULL;
Mix_Chunk *ball_bricks_collision = NULL;
Mix_Chunk *hardbricks = NULL;
Mix_Chunk *fire_init = NULL;
Mix_Chunk *game_over_music = NULL;
Mix_Chunk *powerup_init_music = NULL;
Mix_Chunk *expand_paddle_music = NULL;
Mix_Chunk *shrink_paddle_music = NULL;
Mix_Chunk *slow_ball_music = NULL;
Mix_Chunk *fast_ball_music = NULL;
Mix_Chunk *life_laser_grab_music = NULL;
Mix_Chunk *score_double = NULL;
Mix_Chunk *level_up = NULL;

void music_load()
{
  main_menu_music = Mix_LoadMUS("res/Music/inspire_main_bgm.mp3");
    if(main_menu_music == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  bar_paddle_collision= Mix_LoadWAV("res/Music/ball_bar_collison.wav");
  if(bar_paddle_collision == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  ball_bricks_collision=Mix_LoadWAV("res/Music/poing.wav");
  if(ball_bricks_collision == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  hardbricks=Mix_LoadWAV("res/Music/hardbricks.wav");
  if(hardbricks == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }

  fire_init=Mix_LoadWAV("res/Music/fire.wav");
  if(fire_init == NULL)
    {printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  powerup_init_music=Mix_LoadWAV("res/Music/powerup_music/powerup_starting.wav");
  if(powerup_init_music == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  game_over_music=Mix_LoadWAV("res/Music/powerup_music/kill_paddle.wav");
  if(game_over_music == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  expand_paddle_music=Mix_LoadWAV("res/Music/powerup_music/expand_paddle.wav");
  if(expand_paddle_music == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  shrink_paddle_music=Mix_LoadWAV("res/Music/powerup_music/shrink_paddle.wav");
  if(shrink_paddle_music == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  fast_ball_music=Mix_LoadWAV("res/Music/powerup_music/fast_ball.wav");
  if(fast_ball_music == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  slow_ball_music=Mix_LoadWAV("res/Music/powerup_music/slow_ball.wav");
  if(slow_ball_music == NULL)
    {
       printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  life_laser_grab_music=Mix_LoadWAV("res/Music/powerup_music/extra_life.wav");
  if(life_laser_grab_music == NULL)
    {printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  score_double=Mix_LoadWAV("res/Music/powerup_music/score_double.wav");
  if(score_double == NULL)
    {
       printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }

  level_up=Mix_LoadWAV("res/Music/levelup.wav");
  if(level_up == NULL)
    {
        printf("failed %s\n",Mix_GetError());
    quit();
        return ;
    }
  
}
int levelup_bricks_initialization(int level)
{	
	int cnt=0,bricks_type;
	FILE *fptr;
	for(int i=0; i<150; i++) 
	{
		bricks[i].show=false;
		bricks[i].b1=false;
		bricks[i].b2=false;
		bricks[i].b3=false;
		bricks[i].b4=false;
		bricks[i].b21=false;
		bricks[i].b25=false;
		bricks[i].b27=false;
		bricks[i].b26=false;
		bricks[cnt].b31=true;
		bricks[cnt].b32=true;
		bricks[cnt].b33=true;
		bricks[cnt].b34=true;
		bricks[cnt].b35=true;
		bricks[cnt].b36=true;
		bricks[cnt].b37=true;
		bricks[i].power=0;

	}
	if(level==1)
	{
		fptr=fopen("res/Level_layout/level1.txt","r");
		int sumx=0,sumy=90;
		for(int i=0; i<126; i++)
		{
			fscanf(fptr, "%d" ,&bricks_type);
			bricks[cnt].show=true;
			if(bricks_type==1) bricks[cnt].b1=true;
			else if(bricks_type==2) bricks[cnt].b2=true;
			else if(bricks_type==3) bricks[cnt].b3=true;
			else if(bricks_type==4) bricks[cnt].b4=true;
			bricks[cnt].x=sumx;
			bricks[cnt].y=sumy;
			cnt++;
			sumx+=100;
			if(sumx>=1800)
			{
				sumx=0;
				sumy+=35;
				
			}
		}
	}
	else if(level==2)
	{
		fptr=fopen("res/Level_layout/level2.txt","r");
		int sumx=0,sumy=90;
		for(int i=0; i<144; i++)
		{
			fscanf(fptr, "%d" ,&bricks_type);
			if(bricks_type!=0)
			{
				if(bricks_type==21) bricks[cnt].b21=true,bricks[cnt].power=1;
				else if(bricks_type==25) bricks[cnt].b25=true;
				else if(bricks_type==26) bricks[cnt].b26=true;
				else if(bricks_type==27) bricks[cnt].b27=true;
				bricks[cnt].x=sumx;
				bricks[cnt].y=sumy;
				bricks[cnt].show=true;
				cnt++;
			}
			sumx+=100;
			if(sumx>=1800)
			{
				sumx=0;
				sumy+=35;
				
			}
		}
	}
	else if(level==3)
	{
		fptr=fopen("res/Level_layout/level3.txt","r");
		int sumx=0,sumy=90;
		for(int i=0; i<198; i++)
		{
			fscanf(fptr, "%d" ,&bricks_type);
			if(bricks_type!=0)
			{
				bricks[cnt].show=true;
				if(bricks_type==31) bricks[cnt].b31=true;
				else if(bricks_type==32) bricks[cnt].b32=true;
				else if(bricks_type==33) bricks[cnt].b33=true;
				else if(bricks_type==34) bricks[cnt].b34=true;
				else if(bricks_type==35) bricks[cnt].b35=true;
				else if(bricks_type==36) bricks[cnt].b36=true;
				else if(bricks_type==37) bricks[cnt].b37=true,bricks[cnt].power=1;
				else if(bricks_type==21) bricks[cnt].b21=true,bricks[cnt].power=1;
				else if(bricks_type==1) bricks[cnt].b1=true;
				else if(bricks_type==2) bricks[cnt].b2=true;
				else if(bricks_type==3) bricks[cnt].b3=true;
				else if(bricks_type==4) bricks[cnt].b4=true;
				bricks[cnt].x=sumx;
				bricks[cnt].y=sumy;
				cnt++;
			}
			sumx+=100;
			if(sumx>=1800)
			{
				sumx=0;
				sumy+=35;
				
			}
			
		}
	}
	fclose(fptr);
	return cnt;

}

void ball_and_powerup_load()
{
	//load background
	surface = IMG_Load("res/Background/munni.jpg"); //done
 	if (!surface)
	{
 		printf("picture 11 load error %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    background1 = SDL_CreateTextureFromSurface(rend, surface);//done
 	SDL_FreeSurface(surface);
	surface=NULL;
 	if(!background1)
	 {
 		printf("error %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
	surface = IMG_Load("res/Background/munni2.jpg"); //done
 	if (!surface)
	{
 		printf("picture 12 error %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    background2 = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;

	surface = IMG_Load("res/Background/level2.jpg");
 	if (!surface)
	{
 		printf("Background2 Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    level2_back = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
	 
 	if(!level2_back)
	 {
 		printf("level2 background Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
	surface = IMG_Load("res/Background/picture10.webp");//done
 	if (!surface)
	{
 		printf("picture10 load error %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    background3 = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
	
 	if(!background3)
	 {
 		printf("background1 Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}

	 surface = IMG_Load("res/Background/level3.jpg");
 	if (!surface)
	{
 		printf("level3 Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    level3_back = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
	
 	if(!level3_back)
	 {
 		printf("level3 background Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}

	 surface = IMG_Load("res/Background/level1.jpg");
 	if (!surface)
	{
 		printf("level1 Background Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    level1_back = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
	
 	if(!level1_back)
	 {
 		printf("level1 background Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
	background.h=WINDOW_HEIGHT,background.w=WINDOW_WIDTH;
	background.x=background.y=0;
	level_background.h=WINDOW_HEIGHT,level_background.w=WINDOW_WIDTH;
	level_background.x=level_background.y=0;
    //load bar  
    //bad dibo
    surface = IMG_Load("res/gnrl_bar/disc1.png");//done
 	if (!surface)
	{
 		printf("disc1 load error %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
    tex = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
 	if(!tex)
	 {
 		printf("Gamebar Texture Error: %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return;
 	}
 	SDL_QueryTexture(tex, NULL, NULL, &bar.w, &bar.h);
 	bar.w = 180;
 	bar.h = 30;
 	bar.x = (int) (WINDOW_WIDTH-bar.w)/2;
 	bar.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
 	surface = IMG_Load("res/goldenball.png");
 	if (!surface)
    {
 		printf("golden ball load error %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
 	tex2 = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
	surface=NULL;
 	if(!tex2)
    {
 		printf("Ball Texture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return ;
 	}
 	ball.w=25;
 	ball.h =25;
 	ball.x = (int) bar.x+50;
 	ball.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
    rect_y = ball.y;
    x_pos = bar.x;	
 	font_load();
}
void bricks_and_bar_load(){
	char gnrlbar[4][100] = {"res/gnrl_bar/disc1.png", "res/gnrl_bar/disc2.png","res/gnrl_bar/disc3.png", "res/gnrl_bar/disc4.png"};
	char magfirebar[4][100] = {"res/magfire_bar/golapi_laser1.jpg", "res/magfire_bar/golapi_laser1.jpg","res/magfire_bar/golapi_laser1.jpg", "res/magfire_bar/golapi_laser1.jpg"};
	char firebar[4][100] = {"res/fire_bar/fbar1.jpg", "res/fire_bar/fbar2.jpg","res/fire_bar/fbar3.jpg", "res/fire_bar/fbar4.jpg"};
	char magneticbar[4][100] = {"res/magnet_bar/disc1.png", "res/magnet_bar/disc2.png","res/magnet_bar/disc3.png", "res/magnet_bar/disc4.png"};//dome
	SDL_Surface *tmp1 = NULL;
	SDL_Surface *tmp2 = NULL;
	SDL_Surface *tmp3 = NULL;
	SDL_Surface *tmp4 = NULL;
	for (int i = 0; i < 4; i++)
	{
		tmp1 = IMG_Load(gnrlbar[i]);
		tmp2 = IMG_Load(magneticbar[i]);
		tmp3 = IMG_Load(magfirebar[i]);
		tmp4 = IMG_Load(firebar[i]);
		if (!tmp1 || !tmp2 || !tmp3 || !tmp4)
		{
			printf("Bar load %d Surface Error: %s\n", i, IMG_GetError());
			SDL_DestroyRenderer(rend);
			SDL_DestroyWindow(win);
			SDL_Quit();
			return;
		}
		gbartex[i].tex = SDL_CreateTextureFromSurface(rend, tmp1);
		mbartex[i].tex = SDL_CreateTextureFromSurface(rend, tmp2);
		mfbartex[i].tex = SDL_CreateTextureFromSurface(rend, tmp3);
		fbartex[i].tex = SDL_CreateTextureFromSurface(rend, tmp4);
		SDL_FreeSurface(tmp1);
		SDL_FreeSurface(tmp2);
		SDL_FreeSurface(tmp3);
		SDL_FreeSurface(tmp4);
	}
	bricks_surface = IMG_Load("res/Bricks/tile1.jpg");
	if (!bricks_surface)
	{
		printf("bricks1 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks1 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface = IMG_Load("res/Bricks/tile2.jpg");
	if (!bricks_surface)
	{
		printf("bricks2 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks2 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface = IMG_Load("res/Bricks/tile3.jpg");
	if (!bricks_surface)
	{
		printf("bricks3 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks3 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface = IMG_Load("res/Bricks/tile4.jpg");
	if (!bricks_surface)
	{
		printf("bricks4 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks4 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface = IMG_Load("res/Bricks/tile21.jpg");
	if (!bricks_surface)
	{
		printf("bricks21 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks21 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface = IMG_Load("res/Bricks/tile21_1.jpg");
	if (!bricks_surface)
	{
		printf("bricks21_1 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks21_1 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface = IMG_Load("res/Bricks/tile25.jpg");
	if (!bricks_surface)
	{
		printf("bricks25 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks25 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface = IMG_Load("res/Bricks/tile26.jpg");
	if (!bricks_surface)
	{
		printf("bricks26 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks26 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface = IMG_Load("res/Bricks/tile27.jpg");
	if (!bricks_surface)
	{
		printf("bricks27 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks27 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface = IMG_Load("res/Bricks/tile31.jpg");
	if (!bricks_surface)
	{
		printf("bricks31 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks31 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface = IMG_Load("res/Bricks/tile32.jpg");
	if (!bricks_surface)
	{
		printf("bricks32 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks32 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface = IMG_Load("res/Bricks/tile33.jpg");
	if (!bricks_surface)
	{
		printf("bricks33 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks33 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);
	bricks_surface = IMG_Load("res/Bricks/tile34.jpg");
	if (!bricks_surface)
	{
		printf("bricks34 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks34 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface = IMG_Load("res/Bricks/tile35.jpg");
	if (!bricks_surface)
	{
		printf("bricks35 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks35 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface = IMG_Load("res/Bricks/tile36.jpg");
	if (!bricks_surface)
	{
		printf("bricks36 load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	bricks36 = SDL_CreateTextureFromSurface(rend, bricks_surface);
	SDL_FreeSurface(bricks_surface);

	bricks_surface=IMG_Load("res/Bricks/tile37.jpg");
	if (!bricks_surface)
	{
		printf("bricks37 load Surface Error: %s\n",IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return ;
	}
	bricks37_1=SDL_CreateTextureFromSurface(rend,bricks_surface);
	bricks37=NULL;
	SDL_FreeSurface(bricks_surface);
	tmp1 = IMG_Load("res/fire.jpg");
	if (!tmp1)
	{
		printf("Fire load Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	firetex = SDL_CreateTextureFromSurface(rend, tmp1);
	SDL_FreeSurface(tmp1);
}

