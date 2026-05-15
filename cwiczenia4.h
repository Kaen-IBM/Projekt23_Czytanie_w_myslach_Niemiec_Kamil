#pragma once
int** allocate_matrix(int n, int m);
void free_matrix(int** a, int n);
void fill_matrix(int** a, int n, int m, int start, int end);
void print_matrix(int** a, int n, int m);

void draw_chess_board();
void test_sums();
int min_max_row(int* a, int n, int* p_min, int* p_max);
void min_max_tab_2D(int** a, int n, int m);
void test_min_max_tab_2D();
void max_nwd(int** a, int n, int m);
void test_max_nwd();
int compare(const void* a, const void* b);
void sort_quick(int* arr, int low, int high);
void sort_rows(int** arr, int n, int m);
void test_sort_row();
void rotate90degree(int** a, int n, int m);
void test_rotate90degree();

void open_cw4();