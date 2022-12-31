#include "header.h"
SDL_Texture *bricks1 = NULL;
SDL_Texture *bricks2 = NULL;
SDL_Texture *bricks3 = NULL;
SDL_Texture *bricks4 = NULL;
SDL_Texture *bricks5 = NULL;
SDL_Texture *bricks21 = NULL;
SDL_Texture *bricks21_1 = NULL;
SDL_Texture *bricks25 = NULL;
SDL_Texture *bricks26 = NULL;
SDL_Texture *bricks27 = NULL;
SDL_Texture *bricks31 = NULL;
SDL_Texture *bricks32 = NULL;
SDL_Texture *bricks33 = NULL;
SDL_Texture *bricks34 = NULL;
SDL_Texture *bricks35 = NULL;
SDL_Texture *bricks36 = NULL;
SDL_Texture* bricks37=NULL;
SDL_Texture* bricks37_1=NULL;
void score_and_life_print(int score, int life)
{
	SDL_Rect scr, lif;
	scr.w = 250;
	scr.h = 75;
	scr.x = scr.y = 0;
	int sc1 = score / 1000, sc2 = (score / 100) % 10, sc3 = (score / 10) % 10, sc4 = score % 10;
	char score_str[11] = {"Score:"};
	score_str[6] = sc1 + '0';
	score_str[7] = sc2 + '0';
	score_str[8] = sc3 + '0';
	score_str[9] = sc4 + '0';
	score_str[10] = '\0';
	score_ttf_tex = DISPLAYING_SCORE(score_str, 0, 1);
	SDL_RenderCopy(rend, score_ttf_tex, NULL, &scr);
	//life
	lif.h = 20, lif.w = 80;
	lif.x = 1700, lif.y = 2;
	for (int sho = 0; sho < life; sho++)
	{
		SDL_RenderCopy(rend, liferend, NULL, &lif);
		lif.x -= 90;
	}
	powerup_gameplay_rect.w = 60;
	powerup_gameplay_rect.h = 45;
	powerup_gameplay_rect.x = 680;
	powerup_gameplay_rect.y = 0;
	for (int i=0;i<9;i++)
	{
		if (i == 5 || i == 6) continue;
		if (power_up_map[i].type) SDL_RenderCopy(rend, poweruptex[i].tex, NULL, &powerup_gameplay_rect);
		else SDL_RenderCopy(rend, powerup_blurtex[i].tex, NULL, &powerup_gameplay_rect);
		powerup_gameplay_rect.x += 63;
	}
}
void firerender(int fbar)
{
	if (fbar == 1&& fire_left>0)
	{
		for (int i = 0; i < 50 ; i++)
		{
			if (fire_rectarray1[i].show || fire_rectarray2[i].show)
			{
				if (fire_rectarray1[i].show)
					SDL_RenderCopy(rend, firetex, NULL, &fire_rectarray1[i].rec);
				if (fire_rectarray2[i].show)
					SDL_RenderCopy(rend, firetex, NULL, &fire_rectarray2[i].rec);
				fire_rectarray1[i].rec.y -= 25;
				fire_rectarray2[i].rec.y -= 25;
				if (fire_rectarray1[i].rec.y <= 0)
					fire_rectarray1[i].show = 0;
				if (fire_rectarray2[i].rec.y <= 0)
					fire_rectarray2[i].show = 0;
			}
		}
	}
}

void powerup_renderer(int p, int type)
{
	if (p) SDL_RenderCopy(rend, poweruptex[type].tex, NULL, &powerup_rec);
	
}

int bar_and_bricks_render(int cnt, int l)
{
	if (cnt % 1 == 0)
	{
		if (gbar == 1)
		{
			bar.h = 25;
			bar.y = (int)WINDOW_HEIGHT - (WINDOW_HEIGHT * 0.05) + 17;
			if (cnt <= 5)
			{
				SDL_RenderCopy(rend, gbartex[0].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 10)
			{
				SDL_RenderCopy(rend, gbartex[1].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 15)
			{
				SDL_RenderCopy(rend, gbartex[2].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 20)
			{
				SDL_RenderCopy(rend, gbartex[3].tex, NULL, &bar);
				if (cnt == 20)
					cnt = 0;
				else
					cnt++;
			}
		}
		else if (mbar == 1)
		{
			bar.h = 20;
			bar.y = (int)WINDOW_HEIGHT - (WINDOW_HEIGHT * 0.05);
			if (cnt <= 5)
			{
				SDL_RenderCopy(rend, mbartex[0].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 10)
			{
				SDL_RenderCopy(rend, mbartex[1].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 15)
			{
				SDL_RenderCopy(rend, mbartex[2].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt<= 20)
			{
				SDL_RenderCopy(rend, mbartex[3].tex, NULL, &bar);
				if (cnt == 20) cnt = 0;
				else cnt++;
			}
		}
		else if (fbar == 1)
		{
			bar.h = 40;
			bar.y = (int)WINDOW_HEIGHT - (WINDOW_HEIGHT * 0.05);
			if (cnt <= 5)
			{
				SDL_RenderCopy(rend, fbartex[0].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 10)
			{
				SDL_RenderCopy(rend, fbartex[1].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 15)
			{
				SDL_RenderCopy(rend, fbartex[2].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 20)
			{
				SDL_RenderCopy(rend, fbartex[3].tex, NULL, &bar);
				;
				if (cnt == 20)
					cnt = 0;
				else
					cnt++;
			}
		}
		else if (mfbar == 1)
		{
			bar.h = 40;
			bar.y = (int)WINDOW_HEIGHT - (WINDOW_HEIGHT * 0.05);
			if (cnt <= 5)
			{
				SDL_RenderCopy(rend, mfbartex[0].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 10)
			{
				SDL_RenderCopy(rend, mfbartex[1].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 15)
			{
				SDL_RenderCopy(rend, mfbartex[2].tex, NULL, &bar);
				cnt++;
			}
			else if (cnt <= 20)
			{
				SDL_RenderCopy(rend, mfbartex[3].tex, NULL, &bar);
				if (cnt == 20)
					cnt = 0;
				else
					cnt++;
			}
		}
	}
	else cnt++;
	if (l == 1)
	{
		for (int i = 0; i < 126; i++)
		{
			SDL_Rect br;
			if (bricks[i].show)
			{
				br.w = bricks[i].dx;
				br.h = bricks[i].dy;
				br.x = bricks[i].x;
				br.y = bricks[i].y;
				if (bricks[i].b1) SDL_RenderCopy(rend, bricks1, NULL, &br);
				else if (bricks[i].b2) SDL_RenderCopy(rend, bricks2, NULL, &br);
				else if (bricks[i].b3) SDL_RenderCopy(rend, bricks3, NULL, &br);
				else if (bricks[i].b4) SDL_RenderCopy(rend, bricks4, NULL, &br);
			}
		}
	}
	else if (l == 2)
	{
		for (int i = 0; i< totalbricks; i++)
		{
			SDL_Rect br;
			if (bricks[i].show)
			{
				br.w = bricks[i].dx;
				br.h = bricks[i].dy;
				br.x = bricks[i].x;
				br.y = bricks[i].y;
				if (bricks[i].b21) SDL_RenderCopy(rend, bricks21, NULL, &br);
				else if (bricks[i].b25) SDL_RenderCopy(rend, bricks25, NULL, &br);
				else if (bricks[i].b26) SDL_RenderCopy(rend, bricks26, NULL, &br);
				else if (bricks[i].b27) SDL_RenderCopy(rend, bricks27, NULL, &br);
				else if (bricks[i].b21_1) 	SDL_RenderCopy(rend, bricks21_1, NULL, &br);
				
			}
		}
	}
	else if (l == 3)
	{
		for (int i = 0; i < totalbricks; i++)
		{
			SDL_Rect br;
			if (bricks[i].show)
			{
				br.w = bricks[i].dx;
				br.h = bricks[i].dy;
				br.x = bricks[i].x;
				br.y = bricks[i].y;
				if (bricks[i].b31) SDL_RenderCopy(rend, bricks31, NULL, &br);
				else if (bricks[i].b32)SDL_RenderCopy(rend, bricks32, NULL, &br);
				else  if (bricks[i].b33) SDL_RenderCopy(rend, bricks33, NULL, &br);
				else if (bricks[i].b34)
				{
					SDL_RenderCopy(rend, bricks34, NULL, &br);
				}
				else if (bricks[i].b35)
				{
					SDL_RenderCopy(rend, bricks35, NULL, &br);
				}
				else if (bricks[i].b36)
				{
					SDL_RenderCopy(rend, bricks36, NULL, &br);
				}
				else if(bricks[i].b37)
				{
					SDL_RenderCopy(rend, NULL, NULL, &br);
				}	
				else if(bricks[i].b37_1)
				{
					SDL_RenderCopy(rend, bricks37_1, NULL, &br);
				}	
				else if (bricks[i].b21)
				{
					SDL_RenderCopy(rend, bricks21, NULL, &br);
				}
				else if (bricks[i].b21_1)
				{
					SDL_RenderCopy(rend, bricks21_1, NULL, &br);
				}
				else if (bricks[i].b1)
				{
					SDL_RenderCopy(rend, bricks1, NULL, &br);
				}
				else if (bricks[i].b2)
				{
					SDL_RenderCopy(rend, bricks2, NULL, &br);
				}
				else if (bricks[i].b3)
				{
					SDL_RenderCopy(rend, bricks3, NULL, &br);
				}
				else if (bricks[i].b4)
				{
					SDL_RenderCopy(rend, bricks4, NULL, &br);
				}
			}
		}
	}

	return cnt;
}
void powerup_achieve()
{
	power_up.hoise = 0;
	if (power_up.type == 0)
	{
		if (gamesound == 1)
			Mix_PlayChannel(-1, life_laser_grab_music, 0);
		score += scr_in;
		fire_left+=40;
		power_up_map[power_up.type].type = 1;
		if (mbar == 1||mfbar == 1) //fire
		{
			mfbar = 1;
			gbar = mbar = fbar = 0;
		}
		else
		{
			fbar = 1;
			gbar = mfbar = mbar = 0;
		}
	}
	else if (power_up.type == 1)
	{
		if (gamesound == 1)
			Mix_PlayChannel(-1, life_laser_grab_music, 0);
		score += scr_in;
		power_up_map[power_up.type].type = 1;
		if (fbar == 1||mfbar == 1) //magnet
		{
			mfbar = 1;
			gbar = mbar = fbar = 0;
		}
		else
		{
			mbar = 1;
			gbar = mfbar = fbar = 0;
		}
	}
	else if (power_up.type == 2)
	{
		if (gamesound == 1) Mix_PlayChannel(-1, score_double, 0);
		score += scr_in;
		scr_in=10;
		power_up_map[power_up.type].type = 1;
	}
	else if (power_up.type == 3)
	{
		if (gamesound == 1)
			Mix_PlayChannel(-1, shrink_paddle_music, 0);
		score += scr_in;
		spaddle = 1;
		power_up_map[power_up.type].type = 1;
		if (epaddle)
		{
			epaddle = spaddle = 0;
			power_up_map[4].type = 0;
			power_up_map[power_up.type].type = 0;
		}
		bar.w = max(100, bar.w / 2); 
	}
	else if (power_up.type == 4)
	{
		if (gamesound == 1)
			Mix_PlayChannel(-1, expand_paddle_music, 0);
		score += scr_in;
		epaddle = 1;
		power_up_map[power_up.type].type = 1;
		if (spaddle)
		{
			epaddle = spaddle = 0;
			power_up_map[3].type = 0;
			power_up_map[power_up.type].type = 0;
		}
		bar.w = min(400, bar.w * 2);
	}
	else if (power_up.type == 5)
	{
		if (gamesound == 1)
			Mix_PlayChannel(-1, game_over_music, 0);
		score += scr_in;
		power_up_map[power_up.type].type = 1;
		life=0;
	}
	else if (power_up.type == 6)
	{
		if (gamesound == 1)
			Mix_PlayChannel(-1, life_laser_grab_music, 0);
		score += scr_in;
		power_up_map[power_up.type].type = 1;
		life++; 
	}
	else if (power_up.type == 7)
	{
		if (gamesound == 1)
			Mix_PlayChannel(-1, fast_ball_music, 0);
		score += scr_in;
		power_up_map[power_up.type].type = 1;
		if (pspeed < 1.0)
			pspeed = 1.0;
		else if (pspeed == 1.0)
			pspeed = 2.0;
		else
			pspeed = 2.0;
		if (!fspeed)
			dx *= pspeed, dy *= pspeed;
		printf("%f\n", pspeed);
		// dx/=2;
		fspeed = 1;
		sspeed = 0;
	}
	else if (power_up.type == 8)
	{
		score += scr_in;
		if (gamesound == 1)
			Mix_PlayChannel(-1, slow_ball_music, 0);
		power_up_map[power_up.type].type = 1;
		if (pspeed <= 0.500000)
			pspeed = 0.5;
		else if (pspeed <= 1.000000)
			pspeed = 0.5;
		else if (pspeed > 1.000000)
			pspeed = 1.0;
		printf("%f\n", pspeed);
		if (!sspeed)
			dx *= pspeed, dy *= pspeed;
		sspeed = 1;
		fspeed = 0;
	}
}

