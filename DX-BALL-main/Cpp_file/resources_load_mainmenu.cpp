#include "header.h"

void mainmenu_load()
{
	surface = IMG_Load("res/frontpage_data/gv.jpg");//done
	if (!surface)
	{
		printf("gameover Error\n");
		quit();
		return;
	}
	gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;
	background_main_menu.w = 1800;
	background_main_menu.h = 980;
	background_main_menu.x = 0;
	background_main_menu.y = 0;
	surface = IMG_Load("res/frontpage_data/mainmenu_background.jpg");//done
	if (!surface)
	{
		printf("Mainmenu Background Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	mainback_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	surface = IMG_Load("res/frontpage_data/pause_back.jpg");//done
	if (!surface)
	{
		printf("pause_back Background Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	pause_back_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	New_game.w = 500;
	New_game.h = 80;
	New_game.x = 650;//520
	New_game.y = 300;//80
	surface = IMG_Load("res/frontpage_data/new game_2.png");//done
	if (!surface)
	{
		printf("Mainmenu newgame icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	New_game_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	surface = IMG_Load("res/frontpage_data/continue2.jpg");//done
	if (!surface)
	{
		printf("Mainmenu continue icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	continue_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	help.w = 500;
	help.h = 80;
	help.x = 650;
	help.y = 585;
	surface = IMG_Load("res/frontpage_data/help2.jpg");
	if (!surface)
	{
		printf("Mainmenu help icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	help_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	high_score.w = 500;
	high_score.h = 80;
	high_score.x = 650;
	high_score.y = 400;
	surface = IMG_Load("res/frontpage_data/high_score2.png");
	if (!surface)
	{
		printf("Mainmenu highscore icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	high_score_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	exi.w = 500;
	exi.h = 80;
	exi.x = 650;
	exi.y = 703;
	surface = IMG_Load("res/frontpage_data/exit_2.jpg");
	if (!surface)
	{
		printf("Mainmenu exit icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	exit_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	options.w = 500;
	options.h = 80;
	options.x = 650;
	options.y = 500;
	surface = IMG_Load("res/frontpage_data/options2.jpg");
	if (!surface)
	{
		printf("Mainmenu options icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	options_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	exit_back.w = 1800;
	exit_back.h = 980;
	exit_back.x = 0;
	exit_back.y = 0;
	surface = IMG_Load("res/frontpage_data/exit_back3.jpg");
	if (!surface)
	{
		printf("Mainmenu exit_back icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	exit_back_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	r_u_sure.w = 600;
	r_u_sure.h = 150;
	r_u_sure.x = 520;
	r_u_sure.y = 420;
	surface = IMG_Load("res/frontpage_data/r_usure.png");
	if (!surface)
	{
		printf("Mainmenu r_u_sure icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	r_u_sure_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	yes.w = 230;
	yes.h = 100;
	yes.x = 470;
	yes.y = 620;
	surface = IMG_Load("res/frontpage_data/yes.png");
	if (!surface)
	{
		printf("Mainmenu yes icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	yes_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	no.w = 230;
	no.h = 100;
	no.x = 970;
	no.y = 620;
	surface = IMG_Load("res/frontpage_data/no.png");
	if (!surface)
	{
		printf("Mainmenu no icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	no_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	surface = IMG_Load("res/frontpage_data/no2.jpg");
	if (!surface)
	{
		printf("Mainmenu no2 icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	no_tex2 = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	surface = IMG_Load("res/frontpage_data/yes2.jpg");
	if (!surface)
	{
		printf("Mainmenu yes2 icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	yes_tex2 = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	options_back.w = 1800;
	options_back.h = 980;
	options_back.x = 0;
	options_back.y = 0;
	surface = IMG_Load("res/frontpage_data/front_back5.jpg");
	if (!surface)
	{
		printf("Options Background Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	options_back_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	surface = IMG_Load("res/frontpage_data/front_back2.jpg");
	if (!surface)
	{
		printf("Options Background Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	help_back_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	// sound_font.w = 500;
	// sound_font.h = 80;
	// sound_font.x = 0;
	// sound_font.y = 100;
	// surface = IMG_Load("res/frontpage_data/sound_font.jpg");
	// if (!surface)
	// {
	// 	printf("sound font icon Surface Error: %s\n", IMG_GetError());
	// 	SDL_DestroyRenderer(rend);
	// 	SDL_DestroyWindow(win);
	// 	SDL_Quit();
	// 	return;
	// }
	// sound_font_tex = SDL_CreateTextureFromSurface(rend, surface);
	// SDL_FreeSurface(surface);
	// surface = NULL;

	sound_on.w = 200;
	sound_on.h = 80;
	sound_on.x = 900;
	sound_on.y = 360;
	surface = IMG_Load("res/frontpage_data/sound_on.png");
	if (!surface)
	{
		printf("sound on icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	sound_on_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	sound_off.w = 200;
	sound_off.h = 80;
	sound_off.x = 1120;
	sound_off.y = 360;
	surface = IMG_Load("res/frontpage_data/sound_off.png");
	if (!surface)
	{
		printf("sound off icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	sound_off_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	sound_on2.w = 170;
	sound_on2.h = 60;
	sound_on2.x = 900;
	sound_on2.y = 360;
	surface = IMG_Load("res/frontpage_data/sound_on2.png");
	if (!surface)
	{
		printf("sound on2 icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	sound_on2_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	sound_off2.w = 170;
	sound_off2.h = 60;
	sound_off2.x = 1120;
	sound_off2.y = 360;
	surface = IMG_Load("res/frontpage_data/sound_off2.png");
	if (!surface)
	{
		printf("sound off2 icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	sound_off2_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	back.w = 500;
	back.h = 80;
	back.x = 1300;
	back.y = 900;
	surface = IMG_Load("res/frontpage_data/back.png");
	if (!surface)
	{
		printf("sound font icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	back_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	surface = IMG_Load("res/frontpage_data/back_2.jpg");
	if (!surface)
	{
		printf("back icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	back2_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	// game_sound.w = 500;
	// game_sound.h = 80;
	// game_sound.x = 0;
	// game_sound.y = 200;
	// surface = IMG_Load("res/frontpage_data/music_font.jpg");
	// if (!surface)
	// {
	// 	printf("game sound font icon Surface Error: %s\n", IMG_GetError());
	// 	SDL_DestroyRenderer(rend);
	// 	SDL_DestroyWindow(win);
	// 	SDL_Quit();
	// 	return;
	// }
	// game_sound_tex = SDL_CreateTextureFromSurface(rend, surface);
	// SDL_FreeSurface(surface);
	// surface = NULL;

	gamesound_on.w = 200;
	gamesound_on.h = 80;
	gamesound_on.x = 900;
	gamesound_on.y = 505;
	surface = IMG_Load("res/frontpage_data/music_on.png");
	if (!surface)
	{
		printf("gamesound on icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	gamesound_on_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	gamesound_off.w = 200;
	gamesound_off.h = 80;
	gamesound_off.x = 1120;
	gamesound_off.y = 505;
	surface = IMG_Load("res/frontpage_data/music_off.png");
	if (!surface)
	{
		printf("gamesound off icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	gamesound_off_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	gamesound_on2.w = 170;
	gamesound_on2.h = 60;
	gamesound_on2.x = 900;
	gamesound_on2.y = 505;
	surface = IMG_Load("res/frontpage_data/music_on2.png");
	if (!surface)
	{
		printf("gamesound on2 icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	gamesound_on2_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	gamesound_off2.w = 170;
	gamesound_off2.h = 60;
	gamesound_off2.x = 1120;
	gamesound_off2.y = 505;
	surface = IMG_Load("res/frontpage_data/music_off2.png");
	if (!surface)
	{
		printf("gamesound off2 icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	gamesound_off2_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;
	high_up.w = 1000;
	high_up.h = 230;
	high_up.x = 400;
	high_up.y = 5;
	surface = IMG_Load("res/frontpage_data/highscore_font2.png");
	if (!surface)
	{
		printf("Mainmenu high up icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	high_up_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	high_body.w = 1000;
	high_body.h = 850;
	high_body.x = 500;
	high_body.y = 150;
	surface = IMG_Load("res/frontpage_data/high_body.png");
	if (!surface)
	{
		printf("Mainmenu high_body icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	high_body_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	next.w = 500;
	next.h = 80;
	next.x = 1300;
	next.y = 880;
	surface = IMG_Load("res/frontpage_data/next.png");
	if (!surface)
	{
		printf("Mainmenu highscore next icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	next2_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	surface = IMG_Load("res/frontpage_data/next2.jpg");
	if (!surface)
	{
		printf("Mainmenu highscore next2 icon Surface Error: %s\n", IMG_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return;
	}
	next_tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	surface = NULL;

	// instruction.w = 700;
	// instruction.h = 130;
	// instruction.x = 600;
	// instruction.y = 300;
	// surface = IMG_Load("res/frontpage_data/instruction.jpg");
	// if (!surface)
	// {
	// 	printf("Mainmenu instruction icon Surface Error: %s\n", IMG_GetError());
	// 	SDL_DestroyRenderer(rend);
	// 	SDL_DestroyWindow(win);
	// 	SDL_Quit();
	// 	return;
	// }
	// instruction_tex = SDL_CreateTextureFromSurface(rend, surface);
	// SDL_FreeSurface(surface);
	// surface = NULL;

	// surface = IMG_Load("res/frontpage_data/instruction2.jpg");
	// if (!surface)
	// {
	// 	printf("Mainmenu instruction2 icon Surface Error: %s\n", IMG_GetError());
	// 	SDL_DestroyRenderer(rend);
	// 	SDL_DestroyWindow(win);
	// 	SDL_Quit();
	// 	return;
	// }
	// instruction2_tex = SDL_CreateTextureFromSurface(rend, surface);
	// SDL_FreeSurface(surface);
	// surface = NULL;
	
	FILE *fptr = fopen("res/Files/highscore.txt","r");
	for (int i = 0; i < 20; i++)
	{
		fscanf(fptr, "%d %s", &highscore_array[i].score, highscore_array[i].name);
	}
	fclose(fptr);
}