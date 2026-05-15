#pragma once

void look_for_char_of_arrow();
void look_for_char();
void ask_name(char* buffer, int size);
int get_choice_with_timer(float time_limit, float* time_left_out, char info[]);
int comp_guess(int count);
void game(char user_name[], int liczba_rund, int poziom);
int start_game();
void enable_ansi();