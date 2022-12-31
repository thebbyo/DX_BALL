#ifndef RESOURCES_H
#define RESOURCES_H

#include "header.h"


//main menu
extern SDL_Rect instruction, controls, powerup_info, high_up, high_body, next, control_body, powerup_info_body, instruction_body;
extern SDL_Rect background_main_menu, dxball, laser, slowball, extralife, doublepoint, killpaddle, fastball_1, New_game;
extern SDL_Rect fastball_2, shrinkpaddle, expandpaddle, New_game2, help, help2, high_score, high_score2, exit2;
extern SDL_Rect exi, front_ball, grabpaddle, r_u_sure, yes, no, exit_back, options, options_back, sound_on, sound_off, back, sound_font, sound_on2, sound_off2, game_sound, gamesound_on, gamesound_off, gamesound_on2, gamesound_off2;
//main menu
//main menu texture
extern SDL_Texture *gameover_tex;
extern SDL_Texture *mainback_tex;
extern SDL_Texture *New_game_tex;
extern SDL_Texture *help_tex;
extern SDL_Texture *high_score_tex;
extern SDL_Texture *exit_tex;
extern SDL_Texture *r_u_sure_tex;
extern SDL_Texture *yes_tex;
extern SDL_Texture *no_tex;
extern SDL_Texture *exit_back_tex;
extern SDL_Texture *yes_tex2;
extern SDL_Texture *no_tex2;
extern SDL_Texture *options_tex;
extern SDL_Texture *options_back_tex;
extern SDL_Texture *sound_on_tex;
extern SDL_Texture *sound_off_tex;
extern SDL_Texture *sound_on2_tex;
extern SDL_Texture *sound_off2_tex;
extern SDL_Texture *back_tex;
extern SDL_Texture *back2_tex;
extern SDL_Texture *sound_font_tex;
extern SDL_Texture *gamesound_on_tex;
extern SDL_Texture *gamesound_off_tex;
extern SDL_Texture *gamesound_on2_tex;
extern SDL_Texture *gamesound_off2_tex;
extern SDL_Texture *game_sound_tex;
extern SDL_Texture *instruction_tex;
extern SDL_Texture *controls_tex;
extern SDL_Texture *powerup_info_tex;
extern SDL_Texture *instruction2_tex;
extern SDL_Texture *controls2_tex;
extern SDL_Texture *powerup_info2_tex;
extern SDL_Texture *high_up_tex;
extern SDL_Texture *high_body_tex;
extern SDL_Texture *next_tex;
extern SDL_Texture *next2_tex;
extern SDL_Texture *help_back_tex;
extern SDL_Texture *control_body_tex;
extern SDL_Texture *powerup_info_body_tex;
extern SDL_Texture *instruction_body_tex;
extern SDL_Texture *instruction2_body_tex;
extern SDL_Texture *pause_back_tex;
extern SDL_Texture *instruction_back_tex;
extern SDL_Texture *continue_tex;

void mainmenu_load(); //mainmenu
int mainmenu_render(); //mainmenu
void pause_menu_renderer(); //mainmenu
void option_render(); //mainmenu
void highscore_render(); //mainmenu
void help_render(); //mainmenu

#endif