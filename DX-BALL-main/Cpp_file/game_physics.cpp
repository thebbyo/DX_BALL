#include "header.h"
float pupx_vel = 0;
float pupy_vel = 0;
int var = 0;
int fire_left=0;
SDL_Rect powerup_gameplay_rect;
SDL_Texture *score_ttf_tex = NULL;
SDL_Texture *firetex = NULL;
SDL_Surface *bricks_surface = NULL;
void ball_fall_paddle_collision()
{
	if (rect_y + ball.h >= (WINDOW_HEIGHT))
	{
		if (gamesound == 1)
		Mix_PlayChannel(-1, game_over_music, 0);
		rect_y = WINDOW_HEIGHT;
		first_bounce = 0;
		y_vel = 0;
		x_vel = 0;
		fspeed = 0;
		sspeed = 0;
		theta = 30;
		pspeed = 1.0;
		scr_in=5;
		dx = BALL_SPEED * sin(theta * acos(-1) / 180);
		dy = BALL_SPEED * cos(theta * acos(-1) / 180);
		first_move = 1;
		gameover = 0;
		ball_move = 0;
		bar.x = (int)(WINDOW_WIDTH - bar.w) / 2;
		bar.y = (int)WINDOW_HEIGHT - (WINDOW_HEIGHT * 0.05);
		ball.x = (int)bar.x + 50;
		ball.y = (int)WINDOW_HEIGHT - (WINDOW_HEIGHT * 0.05) + ball.h;
		rect_x = ball.x;
		rect_y = ball.y;
		x_pos = bar.x;
		x_vel = BALL_SPEED;
		y_vel = BALL_SPEED * -1;
		life -= 1;
		if (life == 0) gameover = 1;
		gbar = mfbar = fbar = 0;
		mbar = 1;
		for (int i = 0; i < 50; i++)
		{
			fire_rectarray1[i].show = fire_rectarray2[i].show = 0;
			if (i < 9)
				power_up_map[i].type = 0;
		}
		bar.w = 200;
	}
	int rball = ball.w / 2;
	collision();
	if (gbar == 1)
	{
		if (rect_y + ball.h >= (bar.y) && rect_x >= (bar.x - ball.w) && rect_x <= (bar.x + bar.w))
		{
			if (first_bounce && gamesound == 1)
				Mix_PlayChannel(-1, bar_paddle_collision, 0);
			first_bounce = 1;
			rect_y = bar.y - ball.h;
			y_vel = -y_vel;
			dy = -dy;
			theta = (bar.w - (rect_x - bar.x)) / (bar.w / 2) * 90;
			dx = BALL_SPEED *cos(theta * acos(-1) / 180), dy =BALL_SPEED * sin(theta * acos(-1) / 180) * (-1);
			dx *= pspeed;
		}
	}
	else
	{
		if (rect_y >= (bar.y) && rect_x >= (bar.x - ball.w) && rect_x <= (bar.x + bar.w))
		{
			if (ball_move && !first_move && gamesound == 1)
			Mix_PlayChannel(-1, bar_paddle_collision, 0);
			theta = (bar.w - (rect_x - bar.x)) / (bar.w / 2) * 90;
			dx = BALL_SPEED * cos(theta * acos(-1) / 180), dy = BALL_SPEED * sin(theta * acos(-1) / 180) * (-1);
			dx *= pspeed;
			rect_y = bar.y;
			if ((mbar == 1||mfbar == 1) && ball_move)
			{
				ball_move = 0;
				var = ball.x - bar.x;
				x_vel = 0;
				y_vel = 0;
			}
		}
	}
}
void collision()
{
	int colided = false;
	for (int i=0;i<150;i++)
	{
		int col= 0;
		if (bricks_showed <= 0)
		{
			if (bricks_showed <= 2 && colided)
			{
				int ccc = 0;
				colided = 0;
				for (int i=0;i<150;i++) if (bricks[i].show) ccc++;
				if (ccc > 0) bricks_showed = ccc;
			}
			if (bricks_showed >=1) break;
			level++;
			if (level==4)
			{
				gameover = 1;
				break;
			}
			bricks_showed = levelup_bricks_initialization(level);
			totalbricks = bricks_showed;
			reset_game(2);
			break;
		}
		if (bricks[i].show == true)
		{
			if ((rect_x >= bricks[i].x && rect_x <= bricks[i].x + bricks[i].dx) && rect_y >= bricks[i].y - ball.h && rect_y <= bricks[i].y - ball.h + bricks[i].dy) //from top (rect_y>=bricks[i].y&&rect_y<=bricks[i].y+bricks[i].dy)
			{
				colided = 1;
				if (score % 120==0 && score &&!power_up.hoise)
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, powerup_init_music, 0);
					srand(time(0));
					power_up.type = rand()%9;
					if (power_up.type == 8 && fspeed)
						power_up.type = 6;
					else if (power_up.type == 7 && sspeed)
						power_up.type = 5;
					powerup_rec.x = rect_x;
					powerup_rec.y = rect_y;
					pup_x = rect_x;
					pup_y = rect_y;
					pupx_vel = BALL_SPEED - 10;
					pupy_vel = -BALL_SPEED - 10;
					power_up.hoise = 1;
				}
				dy *= (-1);
				bricks[i].show = false;
				rect_y += ball.h;
				score += scr_in;
				bricks_showed--;
				if (bricks[i].power)
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, hardbricks, 0);
					bricks[i].power--;
					bricks[i].show = true;
					if(level==2)
					{
						bricks[i].b21_1 = true;
						bricks[i].b21 = false;
					}
					else if(level==3)
					{
						if(bricks[i].b21) bricks[i].b21_1 = true,bricks[i].b21 = false;
						if(bricks[i].b37) bricks[i].b37=false,bricks[i].b37_1=true;
					}
					bricks_showed++;
				}
				else
				{
					if (gamesound == 1) Mix_PlayChannel(-1, ball_bricks_collision, 0);
				}
				break;
			}
			else if ((rect_x >= bricks[i].x && rect_x <= bricks[i].x + bricks[i].dx) && rect_y >= bricks[i].y && rect_y <= bricks[i].y + bricks[i].dy) //from below (rect_y>=bricks[i].y&&rect_y<=bricks[i].y+bricks[i].dy)
			{
				colided = true;
				if (score % 120 == 0 && score && !power_up.hoise)
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, powerup_init_music, 0);
					srand(time(0));
					power_up.type = rand()%9;
					if (power_up.type == 8 && fspeed)
						power_up.type = 6;
					else if (power_up.type == 7 && sspeed)
						power_up.type = 5;
					powerup_rec.x = rect_x;
					powerup_rec.y = rect_y;
					pup_x = rect_x;
					pup_y = rect_y;
					pupx_vel = BALL_SPEED - 10;
					pupy_vel = -BALL_SPEED - 10;
					power_up.hoise = 1;
				}
				dy *= (-1);
				bricks[i].show = 0;
				bricks_showed--;
				score += scr_in;
				if (bricks[i].power)
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, hardbricks, 0);
					bricks[i].power--;
					bricks[i].show = true;
					if(level==2)
					{
						bricks[i].b21_1 = true;
						bricks[i].b21 = false;
					}
					else if(level==3)
					{
						if(bricks[i].b21) bricks[i].b21_1 = true,bricks[i].b21 = false;
						if(bricks[i].b37) bricks[i].b37=false,bricks[i].b37_1=true;
						
					}
					bricks_showed++;
				}
				else
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, ball_bricks_collision, 0);
				}
				break;
			}
			else if ((rect_x >= bricks[i].x && rect_x <= bricks[i].x + bricks[i].dx) && (rect_y + ball.h >= bricks[i].y && rect_y <= bricks[i].y + bricks[i].dy)) //from right
			{
				colided = true;
				if (score % 120 == 0 && score && !power_up.hoise)
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, powerup_init_music, 0);
					srand(time(0));
					power_up.type = rand()%9;
					if (power_up.type == 8 && fspeed)
						power_up.type = 6;
					else if (power_up.type == 7 && sspeed)
						power_up.type = 5;
					powerup_rec.x = rect_x;
					powerup_rec.y = rect_y;
					pup_x = rect_x;
					pup_y = rect_y;
					pupx_vel = BALL_SPEED - 10;
					pupy_vel = -BALL_SPEED - 10;
					power_up.hoise = 1;
				}
				dx *= (-1);
				bricks[i].show = false;
				score += scr_in;
				bricks_showed--;
				if (bricks[i].power)
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, hardbricks, 0);
					bricks[i].power--;
					bricks[i].show = true;
					if(level==2)
					{
						bricks[i].b21_1 = true;
						bricks[i].b21 = false;
					}
					else if(level==3)
					{
						if(bricks[i].b21) bricks[i].b21_1 = true,bricks[i].b21 = false;
						if(bricks[i].b37) bricks[i].b37=false,bricks[i].b37_1=true;
						
					}
					bricks_showed++;
				}
				else
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, ball_bricks_collision, 0);
				}
				break;
			}
			else if ((rect_x + ball.w >= bricks[i].x && rect_x <= bricks[i].x + bricks[i].dx) && (rect_y + ball.h >= bricks[i].y && rect_y <= bricks[i].y + bricks[i].dy)) //from left
			{

				colided = true;
				if (score % 120 == 0 && score && !power_up.hoise)
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, powerup_init_music, 0);
					srand(time(0));
					power_up.type = rand()%9;
					if (power_up.type == 8 && fspeed)
						power_up.type = 6;
					else if (power_up.type == 7 && sspeed)
						power_up.type = 5;
					powerup_rec.x = rect_x;
					powerup_rec.y = rect_y;
					pup_x = rect_x;
					pup_y = rect_y;

					pupx_vel = BALL_SPEED - 10;
					pupy_vel = -BALL_SPEED - 10;
					power_up.hoise = 1;
				}
				dx *= (-1);
				bricks[i].show = false;
				score += scr_in;
				bricks_showed--;
				if (bricks[i].power)
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, hardbricks, 0);
					bricks[i].power--;
					bricks[i].show = true;
					if(level==2)
					{
						bricks[i].b21_1 = true;
						bricks[i].b21 = false;
					}
					else if(level==3)
					{
						if(bricks[i].b21) bricks[i].b21_1 = true,bricks[i].b21 = false;
						if(bricks[i].b37) bricks[i].b37=false,bricks[i].b37_1=true;
						
					}
					bricks_showed++;
				}
				else
				{
					if (gamesound == 1)
						Mix_PlayChannel(-1, ball_bricks_collision, 0);
				}
				break;
			}
			if ((fbar == 1 || mfbar == 1))
			{

				for (int j = 0; j < 50; j++)
				{
					if (fire_rectarray1[j].show||fire_rectarray2[j].show)
					{
						if (fire_rectarray1[j].rec.x >= bricks[i].x && fire_rectarray1[j].rec.x <= bricks[i].x + bricks[i].dx && fire_rectarray1[j].rec.y <= bricks[i].y + bricks[i].dy)
						{
							colided = true;
							if (score % 120 == 0 && score && !power_up.hoise)
							{
								if (gamesound == 1)
									Mix_PlayChannel(-1, powerup_init_music, 0);
								srand(time(0));
								power_up.type = rand()%9;
								if (power_up.type == 8 && fspeed)
									power_up.type = 6;
								else if (power_up.type == 7 && sspeed)
									power_up.type = 5;
								powerup_rec.x = bricks[i].x;
								powerup_rec.y = bricks[i].y;
								pup_x = bricks[i].x;
								pup_y = bricks[i].y;
								pupx_vel = BALL_SPEED - 10;
								pupy_vel = -BALL_SPEED - 10;
								power_up.hoise = 1;
							}
							bricks[i].show = false;
							score += scr_in;
							fire_rectarray1[j].show = 0;
							fire_rectarray1[j].rec.h = 0;
							fire_rectarray1[j].rec.y = 1900;
							fire_rectarray1[j].rec.x = 1900;
							fire_rectarray1[j].rec.w = 0;
							bricks_showed--;
							if (bricks[i].power)
							{
								if (gamesound == 1)
									Mix_PlayChannel(-1, hardbricks, 0);
								bricks[i].power--;
								bricks[i].show = true;
								if(level==2)
								{
									bricks[i].b21_1 = true;
									bricks[i].b21 = false;
								}
								else if(level==3)
								{
									if(bricks[i].b21) bricks[i].b21_1 = true,bricks[i].b21 = false;
									if(bricks[i].b37) bricks[i].b37=false,bricks[i].b37_1=true;
									
								}
								bricks_showed++;
							}
							else
							{
								if (gamesound == 1)
									Mix_PlayChannel(-1, ball_bricks_collision, 0);
							}
							col = true;
						}
						if (fire_rectarray2[j].rec.x >= bricks[i].x && fire_rectarray2[j].rec.x <= bricks[i].x + bricks[i].dx && fire_rectarray2[j].rec.y <= bricks[i].y + bricks[i].dy)
						{
							colided = true;
							if (score % 120 == 0 && score && !power_up.hoise)
							{
								if (gamesound == 1)
									Mix_PlayChannel(-1, powerup_init_music, 0);
								srand(time(0));
								power_up.type = rand()%9;
								if (power_up.type == 8 && fspeed)
									power_up.type = 6;
								else if (power_up.type == 7 && sspeed)
									power_up.type = 5;
								powerup_rec.x = bricks[i].x;
								powerup_rec.y = bricks[i].y;
								pup_x = bricks[i].x;
								pup_y = bricks[i].y;
								pupx_vel = BALL_SPEED - 10;
								pupy_vel = -BALL_SPEED - 10;
								power_up.hoise = 1;
							}
							bricks[i].show = false;
							score += scr_in;
							fire_rectarray2[j].show = 0;
							bricks_showed--;
							fire_rectarray2[j].rec.h = 0;
							fire_rectarray2[j].rec.y = 1900;
							fire_rectarray2[j].rec.x = 1900;
							fire_rectarray2[j].rec.w = 0;
							if (bricks[i].power)
							{
								if (gamesound == 1)
									Mix_PlayChannel(-1, hardbricks, 0);
								bricks[i].power--;
								bricks[i].show = true;
								if(level==2)
								{
									bricks[i].b21_1 = true;
									bricks[i].b21 = false;
								}
								else if(level==3)
								{
									if(bricks[i].b21) bricks[i].b21_1 = true,bricks[i].b21 = false;
									if(bricks[i].b37) bricks[i].b37=false,bricks[i].b37_1=true;
									
								}
								bricks_showed++;
							}
							else
							{
								if (gamesound == 1)
									Mix_PlayChannel(-1, ball_bricks_collision, 0);
							}
							col = true;
						}
					}
					if (col)
						true;
				}
			}
			if (col)
				true;
		}
	}
}

void game_physics()
{
	if (ball_move == 0 && first_move)
	{
		bar.x = (int)x_pos;
		ball.x = (int)bar.x + 50;
		//bug chilo ball n bar e
		ball.y = (int)rect_y-ball.h;
		rect_x = ball.x;
		rect_y = bar.y;
		dx = 0;
		dy = 0;
	}
	else if (first_move == 0 && (mbar == 1||mfbar == 1) && !ball_move)
	{

		bar.x = (int)x_pos;
		ball.x = (int)bar.x + var;
		ball.y = (int)rect_y;
		rect_x = ball.x;
		rect_y = ball.y;
		dx = 0;
		dy = 0;
	}
	else
	{
		bar.x = (int)x_pos;
		ball.x = (int)rect_x;
		ball.y = (int)rect_y;
	}
	rect_x += dx;
	rect_y += dy;
	if (rect_x <= 0)
	{
		rect_x = 0;
		x_vel = -x_vel;
		dx = -dx;
	}
	if (rect_y <= 0)
	{
		rect_y = 0;
		y_vel = -y_vel;
		dy = -dy;
	}
	if (rect_x >= (WINDOW_WIDTH - ball.w))
	{
		rect_x = WINDOW_WIDTH - ball.w;
		x_vel = -x_vel;
		dx = -dx;
	}
	ball_fall_paddle_collision();
	if ((abs(dy))<=0.7999999)
	{
		double sign = dy / (abs(dy));
		dy = 0.8 * sign;
	}
}


