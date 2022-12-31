#include "header.h"
void level_destroy()
{
	SDL_DestroyTexture(bricks1);
	SDL_DestroyTexture(bricks2);
	SDL_DestroyTexture(bricks3);
	SDL_DestroyTexture(bricks4);
	SDL_DestroyTexture(bricks5);
	SDL_DestroyTexture(bricks21);
	SDL_DestroyTexture(bricks21_1);
	SDL_DestroyTexture(bricks25);
	SDL_DestroyTexture(bricks26);
	SDL_DestroyTexture(bricks27);
	SDL_DestroyTexture(bricks31);
	SDL_DestroyTexture(bricks32);
	SDL_DestroyTexture(bricks33);
	SDL_DestroyTexture(bricks34);
	SDL_DestroyTexture(bricks35);
	SDL_DestroyTexture(bricks36);
	SDL_DestroyTexture(bricks37_1);
	SDL_DestroyTexture(firetex);
	SDL_DestroyTexture(score_ttf_tex);
	bricks1 = NULL;
	bricks2 = NULL;
	bricks3 = NULL;
	bricks4 = NULL;
	bricks5 = NULL;
	firetex = NULL;
	score_ttf_tex = NULL;
}

void quit()
{
	SDL_Delay(1000 / 60);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_DestroyTexture(back_tex);
	SDL_DestroyTexture(New_game_tex);
	SDL_DestroyTexture(help_tex);
	SDL_DestroyTexture(high_score_tex);
	SDL_DestroyTexture(exit_tex);
	SDL_DestroyTexture(r_u_sure_tex);
	SDL_DestroyTexture(yes_tex);
	SDL_DestroyTexture(no_tex);
	SDL_DestroyTexture(exit_back_tex);
	SDL_DestroyTexture(yes_tex2);
	SDL_DestroyTexture(no_tex2);
	SDL_DestroyTexture(options_tex);
	SDL_DestroyTexture(tex);
	SDL_DestroyTexture(tex2);
	SDL_DestroyTexture(liferend);
	SDL_DestroyTexture(background1);
	SDL_DestroyTexture(gameover_tex);
	gameover_tex = NULL;
	back_tex = NULL;
	New_game_tex = NULL;
	help_tex = NULL;
	high_score_tex = NULL;
	exit_tex = NULL;
	r_u_sure_tex = NULL;
	yes_tex = NULL;
	no_tex = NULL;
	exit_back_tex = NULL;
	yes_tex2 = NULL;
	no_tex2 = NULL;
	options_tex = NULL;
	tex = NULL;
	tex2 = NULL;
	liferend = NULL;
	background1 = NULL;
	Mix_FreeMusic(main_menu_music);
	for (int i = 0; i < 4; i++) SDL_DestroyTexture(gbartex[i].tex);
	for (int i = 0; i < 4; i++) SDL_DestroyTexture(mbartex[i].tex);
	for (int i = 0; i < 4; i++) SDL_DestroyTexture(fbartex[i].tex);
	for (int i = 0; i < 4; i++)SDL_DestroyTexture(mfbartex[i].tex);
	font_closing();
	level_destroy();
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}
