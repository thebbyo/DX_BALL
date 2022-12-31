#include "header.h"
SDL_Texture *gameover_tex = NULL;
SDL_Texture *mainback_tex = NULL;
SDL_Texture *New_game_tex = NULL;
SDL_Texture *help_tex = NULL;
SDL_Texture *high_score_tex = NULL;
SDL_Texture *exit_tex = NULL;
SDL_Texture *r_u_sure_tex = NULL;
SDL_Texture *yes_tex = NULL;
SDL_Texture *no_tex = NULL;
SDL_Texture *exit_back_tex = NULL;
SDL_Texture *yes_tex2 = NULL;
SDL_Texture *no_tex2 = NULL;
SDL_Texture *options_tex = NULL;
SDL_Texture *options_back_tex = NULL;
SDL_Texture *sound_on_tex = NULL;
SDL_Texture *sound_off_tex = NULL;
SDL_Texture *sound_on2_tex = NULL;
SDL_Texture *sound_off2_tex = NULL;
SDL_Texture *back_tex = NULL;
SDL_Texture *back2_tex = NULL;
SDL_Texture *sound_font_tex = NULL;
SDL_Texture *gamesound_on_tex = NULL;
SDL_Texture *gamesound_off_tex = NULL;
SDL_Texture *gamesound_on2_tex = NULL;
SDL_Texture *gamesound_off2_tex = NULL;
SDL_Texture *game_sound_tex = NULL;
SDL_Texture *instruction_tex = NULL;
SDL_Texture *controls_tex = NULL;
SDL_Texture *powerup_info_tex = NULL;
SDL_Texture *instruction2_tex = NULL;
SDL_Texture *controls2_tex = NULL;
SDL_Texture *powerup_info2_tex = NULL;
SDL_Texture *high_up_tex = NULL;
SDL_Texture *high_body_tex = NULL;
SDL_Texture *next_tex = NULL;
SDL_Texture *next2_tex = NULL;
SDL_Texture *help_back_tex = NULL;
SDL_Texture *control_body_tex = NULL;
SDL_Texture *powerup_info_body_tex = NULL;
SDL_Texture *instruction_body_tex = NULL;
SDL_Texture *instruction2_body_tex = NULL;
SDL_Texture *pause_back_tex = NULL;
SDL_Texture *instruction_back_tex = NULL;
SDL_Texture *continue_tex = NULL;
int mainmenu_render()
{
	if (sound == 1 && music_run && (mainmenu))
	{
		Mix_PlayMusic(main_menu_music, -1);
		music_run = 0;
	}
	while (mainmenu)
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
			{
				close = 1;
				mainmenu = 0;
			}

			else if (ev.type == SDL_KEYDOWN)
			{

				if (mainmenu == 1 && game_sesh == 0)
				{
					if (ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						if (!game_sesh)
							game_sesh = 1;
						break;
					}
				}

				if (game_sesh == 1)
				{
					if (ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						if (game_sesh)
							game_sesh = 0;
						break;
					}

					if (ev.key.keysym.scancode == SDL_SCANCODE_LEFT)
					{
						if (evar == 2)
							evar = 1;
						else if (evar == 0)
							evar = 1;
						break;
					}

					if (ev.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					{
						if (evar == 1)
							evar = 2;
						else if (evar == 0)
							evar = 1;
						break;
					}
					if (ev.key.keysym.scancode == SDL_SCANCODE_DOWN)
					{
						if (evar == 0)
							evar = 1;
						break;
					}
				}
				else if (uivar == 0)
				{
					if (ev.key.keysym.scancode == SDL_SCANCODE_LEFT||ev.key.keysym.scancode == SDL_SCANCODE_UP)
						uivar = 1;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_RIGHT||ev.key.keysym.scancode == SDL_SCANCODE_DOWN)
						uivar = 1;
					break;
				}
				else if (uivar == 1)
				{
					if (ev.key.keysym.scancode == SDL_SCANCODE_LEFT||ev.key.keysym.scancode == SDL_SCANCODE_UP)
						;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						uivar = 2;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_DOWN)
						uivar = 3;
					break;
				}
				else if (uivar == 2)
				{
					if (ev.key.keysym.scancode == SDL_SCANCODE_RIGHT||ev.key.keysym.scancode == SDL_SCANCODE_UP)
						;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_LEFT)
						uivar = 1;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_DOWN)
						uivar = 4;
					break;
				}
				else if (uivar == 3)
				{
					if (ev.key.keysym.scancode == SDL_SCANCODE_LEFT)
						;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						uivar = 4;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_DOWN)
						uivar = 5;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_UP)
						uivar = 1;
					break;
				}
				else if (uivar == 4)
				{
					if (ev.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_UP)
						uivar = 2;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_DOWN)
						uivar = 5;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_LEFT)
						uivar = 3;
					break;
				}
				else if (uivar == 5)
				{
					if (ev.key.keysym.scancode == SDL_SCANCODE_RIGHT||ev.key.keysym.scancode == SDL_SCANCODE_DOWN)
						;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_LEFT)
						;
					else if (ev.key.keysym.scancode == SDL_SCANCODE_UP)
						uivar = 3;
					break;
				}
			}
		}
		int mmmousex, mmmousey;
		int mmbuttons = SDL_GetMouseState(&mmmousex, &mmmousey);
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, mainback_tex, NULL, &background_main_menu);

		if (uivar == 1 || mmmousex >= New_game.x && mmmousex <= (New_game.x + New_game.w) && mmmousey >= New_game.y && mmmousey <= (New_game.y + New_game.h))
		{
			uivar = 1;
			SDL_RenderCopy(rend, New_game_tex, NULL, &New_game);
			if (ev.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				uivar = 0;
				reset_game(3);
			}
		}
		if (uivar == 4 || mmmousex >= help.x && mmmousex <= (help.x + help.w) && mmmousey >= help.y && mmmousey <= (help.y + help.h))
		{
			uivar = 4;
			SDL_RenderCopy(rend, help_tex, NULL, &help);
			if (ev.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				Help = 1;
				uivar = 0;
				if (Help == 1)
					help_render();
			}
		}
		if (uivar == 2 || mmmousex >= high_score.x && mmmousex <= (high_score.x + high_score.w) && mmmousey >= high_score.y && mmmousey <= (high_score.y + high_score.h))
		{
			uivar = 2;
			SDL_RenderCopy(rend, high_score_tex, NULL, &high_score);
			if (ev.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				uivar = 0;
				Hscore = 1;
				if (Hscore == 1)
					highscore_render();
			}
		}
		if (uivar == 3 || mmmousex >= options.x && mmmousex <= (options.x + options.w) && mmmousey >= options.y && mmmousey <= (options.y + options.h))
		{
			uivar = 3;
			SDL_RenderCopy(rend, options_tex, NULL, &options);
			if (ev.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				uivar = 0;
				option = 1;
				if (option == 1)
					option_render();
			}
		}
		if (uivar == 5 || mmmousex >= exi.x && mmmousex <= (exi.x + exi.w) && mmmousey >= exi.y && mmmousey <= (exi.y + exi.h))
		{
			uivar = 5;
			SDL_RenderCopy(rend, exit_tex, NULL, &exi);
			if (ev.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				uivar = 0;
				game_sesh = 1;
			}
		}
		if (game_sesh)
		{

			SDL_RenderCopy(rend, exit_back_tex, NULL, &exit_back);
			SDL_RenderCopy(rend, r_u_sure_tex, NULL, &r_u_sure);
			if (evar == 1 || mmmousex >= yes.x && mmmousex <= (yes.x + yes.w) && mmmousey >= yes.y && mmmousey <= (yes.y + yes.h))
			{
				evar = 1;
				SDL_RenderCopy(rend, yes_tex2, NULL, &yes);
				int mousex, mousey;
				int buttons = SDL_GetMouseState(&mousex, &mousey);
				if (ev.key.keysym.scancode == SDL_SCANCODE_RETURN || buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					close = 1;
					evar = 0;
					return 0;
				}
			}
			else
				SDL_RenderCopy(rend, yes_tex, NULL, &yes);
			if (evar == 2 || mmmousex >= no.x && mmmousex <= (no.x + no.w) && mmmousey >= no.y && mmmousey <= (no.y + no.h))
			{
				evar = 2;
				SDL_RenderCopy(rend, no_tex2, NULL, &no);
				int mousex, mousey;
				int buttons = SDL_GetMouseState(&mousex, &mousey);

				if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					evar = 0;
					game_sesh = 0;
				}
				if (ev.type == SDL_KEYDOWN)
				{
					if (ev.key.keysym.scancode == SDL_SCANCODE_RETURN && evar == 2 && game_sesh == 1)
					{
						evar = 0;
						game_sesh = 0;
						break;
					}
				}
			}
			else
				SDL_RenderCopy(rend, no_tex, NULL, &no);
		}

		SDL_RenderPresent(rend);
		SDL_Delay(1000 / 60);
	}
	return 1;
}


void pause_menu_renderer()
{
	if (sound == 1 && music_run && pause)
	{
		Mix_PlayMusic(main_menu_music, -1);
		music_run = 0;
	}
	while (pause)
	{
		SDL_Event evp;
		while (SDL_PollEvent(&evp))
		{
			if (evp.type == SDL_QUIT)
			{
				close = 1;
				pause = 1 - pause;
			}
			else if (evp.type == SDL_KEYDOWN)
			{
				if (evp.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					pause = 1 - pause;
					break;
				}
				if (game_sesh)
				{
					if (evp.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						if (game_sesh)
							game_sesh = 0;
					}

					if (evp.key.keysym.scancode == SDL_SCANCODE_LEFT)
					{
						if (evar == 2)
							evar = 1;
						else if (evar == 0)
							evar = 1;
					}

					if (evp.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					{
						if (evar == 1)
							evar = 2;
						else if (evar == 0)
							evar = 1;
					}
					if (evp.key.keysym.scancode == SDL_SCANCODE_DOWN)
					{
						if (evar == 0)
							evar = 1;
						break;
					}
				}
				else if (pvar == 0)
				{
					if (evp.key.keysym.scancode == SDL_SCANCODE_LEFT||evp.key.keysym.scancode == SDL_SCANCODE_UP)
						pvar = 1;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_RIGHT||evp.key.keysym.scancode == SDL_SCANCODE_DOWN)
						pvar = 1;
					break;
				}
				else if (pvar == 1)
				{
					if (evp.key.keysym.scancode == SDL_SCANCODE_LEFT||evp.key.keysym.scancode == SDL_SCANCODE_UP)
						;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						pvar = 2;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_DOWN)
						pvar = 3;
					break;
				}
				else if (pvar == 2)
				{
					if (evp.key.keysym.scancode == SDL_SCANCODE_RIGHT||evp.key.keysym.scancode == SDL_SCANCODE_UP)
						;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_LEFT)
						pvar = 1;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_DOWN)
						pvar = 4;
					break;
				}
				if (pvar == 3)
				{
					if (evp.key.keysym.scancode == SDL_SCANCODE_LEFT)
						;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						pvar = 4;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_DOWN)
						pvar = 5;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_UP)
						pvar = 1;
					break;
				}
				if (pvar == 4)
				{
					if (evp.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_UP)
						pvar = 2;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_DOWN)
						pvar = 5;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_LEFT)
						pvar = 3;
					break;
				}
				if (pvar == 5)
				{
					if (evp.key.keysym.scancode == SDL_SCANCODE_RIGHT||evp.key.keysym.scancode == SDL_SCANCODE_DOWN)
						;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_LEFT)
						;
					else if (evp.key.keysym.scancode == SDL_SCANCODE_UP)
						pvar = 3;
					break;
				}
			}
		}
		int mmmousex, mmmousey;
		int mmbuttons = SDL_GetMouseState(&mmmousex, &mmmousey);
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, pause_back_tex, NULL, &background_main_menu);
		if (pvar == 1 || mmmousex >= New_game.x && mmmousex <= (New_game.x + New_game.w) && mmmousey >= New_game.y && mmmousey <= (New_game.y + New_game.h))
		{
			pvar = 1;
			SDL_RenderCopy(rend, continue_tex, NULL, &New_game); //here continue is on previous newgame's location
			if (evp.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar = 0;
				pause = 1 - pause;
				Mix_HaltMusic();
				music_run = 1;
			}
		}
		if (pvar == 2 || mmmousex >= high_score.x && mmmousex <= (high_score.x + high_score.w) && mmmousey >= high_score.y && mmmousey <= (high_score.y + high_score.h))
		{
			pvar = 2;
			SDL_RenderCopy(rend, New_game_tex, NULL, &high_score); //here new game's loaction is on previous highscore's location
			if (evp.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar = 0;
				pause = 1 - pause;
				level1=1;
				reset_game(3);
			}
		}
		if (pvar == 4 || mmmousex >= help.x && mmmousex <= (help.x + help.w) && mmmousey >= help.y && mmmousey <= (help.y + help.h))
		{
			pvar = 4;
			SDL_RenderCopy(rend, help_tex, NULL, &help);
			if (evp.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar = 0;
				Help = 1;
				if (Help == 1)
					help_render();
			}
		}
		if (pvar == 3 || mmmousex >= options.x && mmmousex <= (options.x + options.w) && mmmousey >= options.y && mmmousey <= (options.y + options.h))
		{
			pvar = 3;
			SDL_RenderCopy(rend, options_tex, NULL, &options);
			if (evp.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar = 0;
				option = 1;
				if (option == 1)
					option_render();
			}
		}
		if (pvar == 5 || mmmousex >= exi.x && mmmousex <= (exi.x + exi.w) && mmmousey >= exi.y && mmmousey <= (exi.y + exi.h))
		{
			pvar = 5;
			SDL_RenderCopy(rend, exit_tex, NULL, &exi);
			if (evp.key.keysym.scancode == SDL_SCANCODE_RETURN || mmbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				pvar = 0;
				game_sesh = 1;
			}
		}
		if (game_sesh)
		{
			SDL_RenderCopy(rend, exit_back_tex, NULL, &exit_back);
			SDL_RenderCopy(rend, r_u_sure_tex, NULL, &r_u_sure);
			SDL_RenderCopy(rend, no_tex, NULL, &no);
			if (evar == 1 || mmmousex >= yes.x && mmmousex <= (yes.x + yes.w) && mmmousey >= yes.y && mmmousey <= (yes.y + yes.h))
			{
				evar = 1;
				SDL_RenderCopy(rend, yes_tex2, NULL, &yes);
				int mousex, mousey;
				int buttons = SDL_GetMouseState(&mousex, &mousey);
				if (evp.key.keysym.scancode == SDL_SCANCODE_RETURN || buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					evar = 0;
					close = 1;
					return;
				}
			}
			else
				SDL_RenderCopy(rend, yes_tex, NULL, &yes);
			if (evar == 2 || mmmousex >= no.x && mmmousex <= (no.x + no.w) && mmmousey >= no.y && mmmousey <= (no.y + no.h))
			{
				evar = 2;
				SDL_RenderCopy(rend, no_tex2, NULL, &no);
				int mousex, mousey;
				int buttons = SDL_GetMouseState(&mousex, &mousey);
				if (evp.key.keysym.scancode == SDL_SCANCODE_RETURN || buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					evar = 0;
					game_sesh = 0;
				}
			}
			else
				SDL_RenderCopy(rend, no_tex, NULL, &no);
		}

		SDL_RenderPresent(rend);
	}
}


