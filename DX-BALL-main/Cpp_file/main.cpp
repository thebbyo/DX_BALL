#include "header.h"
int main(int agr, char *args[])
{
	if (INITIALIZE())
		printf("Initialization Complete.\n");
	else
	{
		printf("Initialize Error\n");
		quit();
		return 0;
	}
	mainmenu_load();
	ball_and_powerup_load();
	bricks_and_bar_load();
	music_load();
	SDL_FreeSurface(surface);
	int mousex = bar.x, mousey = bar.y, prevx = bar.x, prevy = bar.y;
	int tym = 0;
	score = 0;
	while (close==0)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			int buttons = SDL_GetGlobalMouseState(&mousex, &mousey);
			if (prevx > mousex)
				x_pos = max(0, x_pos - (SCROLL_SPEED / 25));
			else if (prevx < mousex)
				x_pos = min(WINDOW_WIDTH - bar.w, x_pos + (SCROLL_SPEED / 25));
			prevx = mousex;
			prevy = mousey;
			switch (event.type)
			{
			case SDL_QUIT:
				close = 1;
				break;
			case SDL_MOUSEBUTTONDOWN:
				lbutton();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_LEFT:
					x_pos = max(0, x_pos - (SCROLL_SPEED) / 5);
					break;
				case SDL_SCANCODE_RIGHT:
					x_pos = min(WINDOW_WIDTH - bar.w, x_pos + (SCROLL_SPEED) / 5);
					break;
				case SDL_SCANCODE_ESCAPE:
					pause = 1 - pause;
					break;
				case SDL_SCANCODE_SPACE:
					lbutton();
					break;
				}
			}
		}
		mainmenu_level_renderer();
	}
	quit();
	return 0;
}
