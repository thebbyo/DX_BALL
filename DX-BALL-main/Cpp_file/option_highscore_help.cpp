#include "header.h"

int level2, level1, level3, enter = 0, uivar = 0, pvar = 0, ovar = 0, hvar = 0, povar = 0, covar = 0, ivar = 0, nvar = 0, evar = 0,scr_in=5;
int Hscore = 0, Help = 0, Instruction = 0, Controls = 0, Powerup_info = 0, Instruction2 = 0, option = 0, game_sesh = 0, next_button = 0;
SDL_Rect instruction, controls, powerup_info, high_up, high_body, next, control_body, powerup_info_body, instruction_body;
SDL_Rect background_main_menu, dxball, laser, slowball, extralife, doublepoint, killpaddle, fastball_1, New_game;
SDL_Rect fastball_2, shrinkpaddle, expandpaddle, New_game2, help, help2, high_score, high_score2, exit2;
SDL_Rect exi, front_ball, grabpaddle, r_u_sure, yes, no, exit_back, options, options_back, sound_on, sound_off, back, sound_font, sound_on2, sound_off2, game_sound, gamesound_on, gamesound_off, gamesound_on2, gamesound_off2;
void option_render()
{
	while (option)
	{
		SDL_RenderClear(rend);
		SDL_Event oevent;
		while (SDL_PollEvent(&oevent))
		{
			if (oevent.type == SDL_QUIT)
			{
				option = 0;
				close = 1;
			}
			else if (oevent.type == SDL_KEYDOWN)
			{

				if (oevent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					if (option)
						option = 0;
					break;
				}

				else if (ovar == 0)
				{
					if (oevent.key.keysym.scancode == SDL_SCANCODE_LEFT ||oevent.key.keysym.scancode == SDL_SCANCODE_UP)
						ovar = 1;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_RIGHT ||oevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						ovar = 1;
					break;
				}
				else if (ovar == 1)
				{
					if (oevent.key.keysym.scancode == SDL_SCANCODE_LEFT ||oevent.key.keysym.scancode == SDL_SCANCODE_UP)
						;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						ovar = 2;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						ovar = 3;
					break;
				}
				else if (ovar == 2)
				{
					if (oevent.key.keysym.scancode == SDL_SCANCODE_RIGHT ||oevent.key.keysym.scancode == SDL_SCANCODE_UP)
						;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_LEFT)
						ovar = 1;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						ovar = 4;
					break;
				}
				if (ovar == 3)
				{
					if (oevent.key.keysym.scancode == SDL_SCANCODE_LEFT)
						;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						ovar = 4;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						ovar = 5;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_UP)
						ovar = 1;
					break;
				}
				if (ovar == 4)
				{
					if (oevent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_UP)
						ovar = 2;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						ovar = 5;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_LEFT)
						ovar = 3;
					break;
				}
				if (ovar == 5)
				{
					if (oevent.key.keysym.scancode == SDL_SCANCODE_RIGHT ||oevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_LEFT)
						;
					else if (oevent.key.keysym.scancode == SDL_SCANCODE_UP)
						ovar = 3;
					break;
				}
			}
		}

		back.x = 1300;
		back.y = 900;
		back.w = 500;
		back.h = 80;
		SDL_RenderCopy(rend, options_back_tex, NULL, &options_back);
		SDL_RenderCopy(rend, sound_font_tex, NULL, &sound_font);
		SDL_RenderCopy(rend, game_sound_tex, NULL, &game_sound);
		if (sound == 1)
		{
			SDL_RenderCopy(rend, sound_on_tex, NULL, &sound_on);
			SDL_RenderCopy(rend, sound_off2_tex, NULL, &sound_off2);
		}
		else if (sound == 0)
		{
			SDL_RenderCopy(rend, sound_off_tex, NULL, &sound_off);
			SDL_RenderCopy(rend, sound_on2_tex, NULL, &sound_on2);
		}

		if (gamesound == 1)
		{
			SDL_RenderCopy(rend, gamesound_on_tex, NULL, &gamesound_on);
			SDL_RenderCopy(rend, gamesound_off2_tex, NULL, &gamesound_off2);
		}
		else if (gamesound == 0)
		{
			SDL_RenderCopy(rend, gamesound_off_tex, NULL, &gamesound_off);
			SDL_RenderCopy(rend, gamesound_on2_tex, NULL, &gamesound_on2);
		}
		int mousesx, mousesy;
		int buttonss = SDL_GetMouseState(&mousesx, &mousesy);
		if (ovar == 5 || mousesx >= back.x && mousesx <= (back.x + back.w) && mousesy >= back.y && mousesy <= (back.y + back.h))
		{
			ovar == 5;
			SDL_RenderCopy(rend, back2_tex, NULL, &back);
			int mousex, mousey;
			int buttons = SDL_GetMouseState(&mousex, &mousey);
			if (oevent.key.keysym.scancode == SDL_SCANCODE_RETURN || buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				ovar = 0;
				option = 0;
			}
		}
		else
			SDL_RenderCopy(rend, back_tex, NULL, &back);

		if (ovar == 1 || mousesx >= sound_on2.x && mousesx <= (sound_on2.x + sound_on2.w) && mousesy >= sound_on2.y && mousesy <= (sound_on2.y + sound_on2.h))
		{
			ovar == 1;
			if (sound == 0)
			{
				sound_on2.w = 200;
				sound_on2.h = 80;
				sound_on2.y = 360;

				SDL_RenderCopy(rend, sound_on2_tex, NULL, &sound_on2);
			}
			else if (sound == 1)
			{
				SDL_RenderCopy(rend, sound_on_tex, NULL, &sound_on);
			}
			if (oevent.key.keysym.scancode == SDL_SCANCODE_RETURN || buttonss & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				sound = 1;
				music_run = 0;
				Mix_PlayMusic(main_menu_music, -1);
			}
			sound_on2.w = 170;
			sound_on2.h = 60;
			sound_on2.y = 370;
		}

		else if (ovar == 2 || mousesx >= sound_off2.x && mousesx <= (sound_off2.x + sound_off2.w) && mousesy >= sound_off2.y && mousesy <= (sound_off2.y + sound_off2.h))
		{
			ovar == 2;
			if (sound == 1)
			{
				sound_off2.w = 200;
				sound_off2.h = 80;
				sound_off2.y = 360;
				SDL_RenderCopy(rend, sound_off2_tex, NULL, &sound_off2);
			}
			else if (sound == 0)
			{
				SDL_RenderCopy(rend, sound_off_tex, NULL, &sound_off);
			}
			if (oevent.key.keysym.scancode == SDL_SCANCODE_RETURN || buttonss & SDL_BUTTON(SDL_BUTTON_LEFT))
			{

				sound = 0;
				music_run = 1;
				Mix_HaltMusic();
			}
			sound_off2.w = 170;
			sound_off2.h = 60;
			sound_off2.y = 370;
		}

		if (ovar == 3 || mousesx >= gamesound_on2.x && mousesx <= (gamesound_on2.x + gamesound_on2.w) && mousesy >= gamesound_on2.y && mousesy <= (gamesound_on2.y + gamesound_on2.h))
		{
			ovar == 3;
			if (gamesound == 0)
			{
				gamesound_on2.w = 200;
				gamesound_on2.h = 80;
				gamesound_on2.y = 505;

				SDL_RenderCopy(rend, gamesound_on2_tex, NULL, &gamesound_on2);
			}
			else if (gamesound == 1)
			{
				SDL_RenderCopy(rend, gamesound_on_tex, NULL, &gamesound_on);
			}
			if (oevent.key.keysym.scancode == SDL_SCANCODE_RETURN || buttonss & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				gamesound = 1;
			}
			gamesound_on2.w = 170;
			gamesound_on2.h = 60;
			gamesound_on2.y = 515;
		}

		else if (ovar == 4 || mousesx >= gamesound_off2.x && mousesx <= (gamesound_off2.x + gamesound_off2.w) && mousesy >= gamesound_off2.y && mousesy <= (gamesound_off2.y + gamesound_off2.h))
		{
			ovar == 4;
			if (gamesound == 1)
			{
				gamesound_off2.w = 200;
				gamesound_off2.h = 80;
				gamesound_off2.y = 505;
				SDL_RenderCopy(rend, gamesound_off2_tex, NULL, &gamesound_off2);
			}
			else if (gamesound == 0)
			{
				SDL_RenderCopy(rend, gamesound_off_tex, NULL, &gamesound_off);
			}
			if (oevent.key.keysym.scancode == SDL_SCANCODE_RETURN || buttonss & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				gamesound = 0;
			}
			gamesound_off2.w = 170;
			gamesound_off2.h = 60;
			gamesound_off2.y = 515;
		}
		SDL_RenderPresent(rend);
	}
}

void highscore_render()
{
	SDL_RenderClear(rend);

	while (Hscore)
	{
		back.x = 0;
		// if(!next_button)
		next.y = 900, next.x = 1300;
		back.y = 900;
		back.w = 500;
		back.h = 80;
		next.w = 500;
		next.h = 80;
		int hmousex, hmousey;
		int hbuttons = SDL_GetMouseState(&hmousex, &hmousey);
		SDL_Event hevent;
		while (SDL_PollEvent(&hevent))
		{
			if (hevent.type == SDL_QUIT)
			{
				Hscore = 0;
				close = 1;
				break;
			}
			else if (hevent.type == SDL_MOUSEBUTTONDOWN)
			{

				if (hmousex >= back.x && hmousex <= (back.x + back.w) && hmousey >= back.y && hmousey <= (back.y + back.h))
				{
					printf("%d\n", next_button);
					if (next_button == 0)
					{
						Hscore = 0;
					}
					else
						next_button = 0;
					break;
				}
			}
			else if (hevent.type == SDL_KEYDOWN)
			{
				if (hevent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					if (next_button == 0)
					{
						Hscore = 0;
					}
					else
						next_button = 0;
					break;
				}
			}
		}
		SDL_RenderClear(rend);

		SDL_RenderCopy(rend, exit_back_tex, NULL, &exit_back);
		SDL_RenderCopy(rend, high_up_tex, NULL, &high_up);
		SDL_RenderCopy(rend, high_body_tex, NULL, &high_body);
		if (hmousex >= back.x && hmousex <= (back.x + back.w) && hmousey >= back.y && hmousey <= (back.y + back.h))
		{
			SDL_RenderCopy(rend, back2_tex, NULL, &back);
		}
		else
			SDL_RenderCopy(rend, back_tex, NULL, &back);

		if (!next_button)
		{
			nvar = 0;
			if (hevent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
				nvar = 1;
			SDL_Rect nameh, scoreh, indx_rec;
			SDL_Texture *name_tex = NULL;
			SDL_Texture *score_tex = NULL;
			SDL_Texture *indx_tex = NULL;
			nameh.h = scoreh.h = indx_rec.h = 30;
			indx_rec.x = high_body.x + 140 - 48;
			nameh.x = high_body.x + 140;
			scoreh.x = high_body.x + 500;
			nameh.y = scoreh.y = indx_rec.y = high_body.y + 220;
			for (int i = 0; i < 10; i++)
			{
				int len = strlen(highscore_array[i].name);
				nameh.w = (len)*24;
				scoreh.w = 4 * 28;
				indx_rec.w = 2 * 24;
				name_tex = DISPLAYING_SCORE(highscore_array[i].name, 1, 1);
				char scorearray[5], indx[4];
				indx[0] = (i + 1) / 10 + '0';
				indx[1] = (i + 1) % 10 + '0';
				indx[2] = '.';
				indx[3] = '\0';
				scorearray[0] = highscore_array[i].score / 1000 + '0';
				scorearray[1] = (highscore_array[i].score / 100) % 10 + '0';
				scorearray[2] = (highscore_array[i].score / 10) % 10 + '0';
				scorearray[3] = highscore_array[i].score % 10 + '0';
				scorearray[4] = '\0';
				score_tex = DISPLAYING_SCORE(scorearray, 1, 0);
				indx_tex = DISPLAYING_SCORE(indx, 1, 0);
				SDL_RenderCopy(rend, indx_tex, NULL, &indx_rec);
				SDL_RenderCopy(rend, name_tex, NULL, &nameh);
				SDL_RenderCopy(rend, score_tex, NULL, &scoreh);
				nameh.y += 50;
				scoreh.y += 50;
				indx_rec.y += 50;
				if (nameh.y >= high_body.y + high_body.h)
				{
					nameh.y = scoreh.y = high_body.y + 180;
				}
				SDL_DestroyTexture(name_tex);
				SDL_DestroyTexture(score_tex);
				SDL_DestroyTexture(indx_tex);
			}
			if (nvar == 1 || hmousex >= next.x && hmousex <= (next.x + next.w) && hmousey >= next.y && hmousey <= (next.y + next.h) && next_button == 0)
			{
				nvar = 1;
				SDL_RenderCopy(rend, next2_tex, NULL, &next);
				if (hevent.key.keysym.scancode == SDL_SCANCODE_RIGHT || (hbuttons && SDL_BUTTON(SDL_BUTTON_LEFT)))
				{
					next_button = 1;
					nvar = 0;
				}
			}
			else
				SDL_RenderCopy(rend, next_tex, NULL, &next);
			SDL_RenderPresent(rend);
			//SDL_Delay(1000/60);
		}
		else if (next_button)
		{

			SDL_Rect nameh, scoreh, indx_rec;
			SDL_Texture *name_tex = NULL;
			SDL_Texture *score_tex = NULL;
			SDL_Texture *indx_tex = NULL;
			nameh.h = scoreh.h = indx_rec.h = 30;
			indx_rec.x = high_body.x + 140 - 48;
			nameh.x = high_body.x + 140;
			scoreh.x = high_body.x + 500;
			nameh.y = scoreh.y = indx_rec.y = high_body.y + 220;
			for (int i = 10; i < 20; i++)
			{
				int len = strlen(highscore_array[i].name);
				nameh.w = (len)*24;
				scoreh.w = 4 * 28;
				indx_rec.w = 2 * 24;
				name_tex = DISPLAYING_SCORE(highscore_array[i].name, 1, 1);
				char scorearray[5], indx[4];
				indx[0] = (i + 1) / 10 + '0';
				indx[1] = (i + 1) % 10 + '0';
				indx[2] = '.';
				indx[3] = '\0';
				scorearray[0] = highscore_array[i].score / 1000 + '0';
				scorearray[1] = (highscore_array[i].score / 100) % 10 + '0';
				scorearray[2] = (highscore_array[i].score / 10) % 10 + '0';
				scorearray[3] = highscore_array[i].score % 10 + '0';
				scorearray[4] = '\0';
				score_tex = DISPLAYING_SCORE(scorearray, 1, 0);
				indx_tex = DISPLAYING_SCORE(indx, 1, 0);
				SDL_RenderCopy(rend, indx_tex, NULL, &indx_rec);
				SDL_RenderCopy(rend, name_tex, NULL, &nameh);
				SDL_RenderCopy(rend, score_tex, NULL, &scoreh);
				nameh.y += 50;
				scoreh.y += 50;
				indx_rec.y += 50;
				if (nameh.y >= high_body.y + high_body.h)
				{
					nameh.y = scoreh.y = high_body.y + 180;
				}
				SDL_DestroyTexture(name_tex);
				SDL_DestroyTexture(score_tex);
				SDL_DestroyTexture(indx_tex);
			}
			SDL_RenderPresent(rend);
		}
	}
}

void help_render()
{
	while (Help)
	{
		back.x = 1300;
		back.y = 900;
		back.w = 500;
		back.h = 80;
		if (Instruction)
		{
			back.x = 0;
		}
		int hmousex, hmousey;
		int hbuttons = SDL_GetMouseState(&hmousex, &hmousey);
		SDL_RenderClear(rend);
		SDL_Event heevent;
		while (SDL_PollEvent(&heevent))
		{
			if (heevent.type == SDL_QUIT)
			{
				Help = 0;
				close = 1;
				break;
			}
			else if (heevent.type == SDL_KEYDOWN)
			{

				if (Help == 1 && !Instruction && !Controls && !Powerup_info)
				{
					if (heevent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						if (Help)
							Help = 0;
						break;
					}
				}
				if (hvar == 0)
				{
					if (heevent.key.keysym.scancode == SDL_SCANCODE_LEFT ||heevent.key.keysym.scancode == SDL_SCANCODE_UP)
						hvar = 1;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_RIGHT ||heevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						hvar = 1;
					break;
				}
				else if (hvar == 1)
				{
					if (heevent.key.keysym.scancode == SDL_SCANCODE_LEFT ||heevent.key.keysym.scancode == SDL_SCANCODE_UP)
						;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						hvar = 2;
					break;
				}
				else if (hvar == 2)
				{
					if (heevent.key.keysym.scancode == SDL_SCANCODE_LEFT)
						;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_UP)
						hvar = 1;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						hvar = 3;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						hvar = 4;
					break;
				}
				if (hvar == 3)
				{
					if (heevent.key.keysym.scancode == SDL_SCANCODE_LEFT)
						hvar = 2;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						hvar = 4;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_UP)
						hvar = 1;
					break;
				}
				if (hvar == 4)
				{
					if (heevent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_UP)
						hvar = 3;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_DOWN)
						;
					else if (heevent.key.keysym.scancode == SDL_SCANCODE_LEFT)
						;
					break;
				}
			}

			if (heevent.type == SDL_MOUSEBUTTONDOWN)
			{
				if (hmousex >= back.x && hmousex <= (back.x + back.w) && hmousey >= back.y && hmousey <= (back.y + back.h))
				{
					if (!Controls && !Powerup_info && !Instruction)
					{
						Help = 0;
						break;
					}
					if (Instruction2)
					{
						Instruction2 = 0;
						Powerup_info = 0;
						break;
					}
					else if (Instruction)
					{
						Instruction = 0;
						break;
					}
				}
			}
			if (heevent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				if (Controls)
					Controls = 0, covar = 0;
				else if (Powerup_info)
					Powerup_info = 0;
				else if (Instruction2)
				{
					Instruction2 = 0;
				}
				else if (Instruction)
				{
					Instruction = 0;
				}
				break;
			}
			if (heevent.key.keysym.scancode == SDL_SCANCODE_RETURN)
			{
				if (!Controls && !Powerup_info && !Instruction && hvar == 4)
				{
					Help = hvar = 0;
					break;
				}
			}
		}

		SDL_RenderCopy(rend, help_back_tex, NULL, &options_back);

		if (hvar == 4 ||hmousex >= back.x && hmousex <= (back.x + back.w) && hmousey >= back.y && hmousey <= (back.y + back.h))
		{
			hvar = 4;
			SDL_RenderCopy(rend, back2_tex, NULL, &back);
		}
		else
			SDL_RenderCopy(rend, back_tex, NULL, &back);
		if (hvar == 1 ||hmousex >= instruction.x && hmousex <= (instruction.x + instruction.w) && hmousey >= instruction.y && hmousey <= (instruction.y + instruction.h))
		{
			hvar = 1;
			SDL_RenderCopy(rend, instruction2_tex, NULL, &instruction);
			if (hbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) ||heevent.key.keysym.scancode == SDL_SCANCODE_RETURN)
			Instruction = 1;
		}
		else
			SDL_RenderCopy(rend, instruction_tex, NULL, &instruction);

		if (hvar == 2 ||hmousex >= controls.x && hmousex <= (controls.x + controls.w) && hmousey >= controls.y && hmousey <= (controls.y + controls.h))
		{
			hvar = 2;
			SDL_RenderCopy(rend, controls2_tex, NULL, &controls);
			if (hbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) ||heevent.key.keysym.scancode == SDL_SCANCODE_RETURN)
				Controls = 1;
		}
		else
			SDL_RenderCopy(rend, controls_tex, NULL, &controls);

		if (hvar == 3 ||hmousex >= powerup_info.x && hmousex <= (powerup_info.x + powerup_info.w) && hmousey >= powerup_info.y && hmousey <= (powerup_info.y + powerup_info.h))
		{
			hvar = 3;
			SDL_RenderCopy(rend, powerup_info2_tex, NULL, &powerup_info);
			if (hbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) ||heevent.key.keysym.scancode == SDL_SCANCODE_RETURN) Powerup_info = 1;
			
		}
		else
			SDL_RenderCopy(rend, powerup_info_tex, NULL, &powerup_info);
		if (Controls)
		{
			covar = 1;
			int hcmousex, hcmousey;
			int hcbuttons = SDL_GetMouseState(&hcmousex, &hcmousey);
			SDL_RenderCopy(rend, control_body_tex, NULL, &control_body);
			back.x = 1300;
			back.y = 900;

			if (hcmousex >= back.x && hcmousex <= (back.x + back.w) && hcmousey >= back.y && hcmousey <= (back.y + back.h))
			{

				SDL_RenderCopy(rend, back2_tex, NULL, &back);
				if (hcbuttons & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					Controls = 0;
					covar = 0;
				}
			}
			else
				SDL_RenderCopy(rend, back_tex, NULL, &back);
		}

		if (Powerup_info)
		{
			int hcmousex, hcmousey;
			int hcbuttons = SDL_GetMouseState(&hcmousex, &hcmousey);
			SDL_RenderCopy(rend, powerup_info_body_tex, NULL, &powerup_info_body);
			back.x = 1300;
			back.y = 900;
			if (hcmousex >= back.x && hcmousex <= (back.x + back.w) && hcmousey >= back.y && hcmousey <= (back.y + back.h))
			{
				SDL_RenderCopy(rend, back2_tex, NULL, &back);
				if (hcbuttons & SDL_BUTTON(SDL_BUTTON_LEFT) ||heevent.key.keysym.scancode == SDL_SCANCODE_RETURN)
				{
					Powerup_info = 0;
				}
			}
			else
				SDL_RenderCopy(rend, back_tex, NULL, &back);
		}

		if (Instruction)
		{
			ivar = 0;
			if (heevent.key.keysym.scancode == SDL_SCANCODE_RIGHT)
				ivar = 1;
			int hcmousex, hcmousey;
			int hcbuttons = SDL_GetMouseState(&hcmousex, &hcmousey);
			SDL_RenderCopy(rend, instruction_back_tex, NULL, &exit_back);
			SDL_RenderCopy(rend, instruction_body_tex, NULL, &instruction_body);
			back.x = 0;
			back.y = 900;
			back.w = 500;
			back.h = 80;
			if (hcmousex >= back.x && hcmousex <= (back.x + back.w) && hcmousey >= back.y && hcmousey <= (back.y + back.h))
			SDL_RenderCopy(rend, back2_tex, NULL, &back);
			else SDL_RenderCopy(rend, back_tex, NULL, &back);
			next.x = 1300;
			next.y = 900;
			next.w = 500;
			next.h = 80;
			if (ivar == 1 || hcmousex >= next.x && hcmousex <= (next.x + next.w) && hcmousey >= next.y && hcmousey <= (next.y + next.h))
			{
				ivar = 1;
				SDL_RenderCopy(rend, next2_tex, NULL, &next);
				if (heevent.key.keysym.scancode == SDL_SCANCODE_RIGHT || (hcbuttons && SDL_BUTTON(SDL_BUTTON_LEFT)))
				{
					Instruction2 = 1;
					ivar = 0;
				}
			}
			else
				SDL_RenderCopy(rend, next_tex, NULL, &next);
		}
		if (Instruction2)
		{
			int hcmousex, hcmousey;
			int hcbuttons = SDL_GetMouseState(&hcmousex, &hcmousey);
			SDL_RenderCopy(rend, instruction_back_tex, NULL, &exit_back);
			SDL_RenderCopy(rend, instruction2_body_tex, NULL, &instruction_body);
			back.x = 0;
			back.y = 900;
			back.w = 500;
			back.h = 80;
			if (hcmousex >= back.x && hcmousex <= (back.x + back.w) && hcmousey >= back.y && hcmousey <= (back.y + back.h))
			{
				SDL_RenderCopy(rend, back2_tex, NULL, &back);
			}
			else
				SDL_RenderCopy(rend, back_tex, NULL, &back);
		}
		SDL_RenderPresent(rend);
		SDL_Delay(1000 /60);
	}
}

