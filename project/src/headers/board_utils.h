#ifndef BOARD_UTILS_H
#define BOARD_UTILS_H

#include "board.h"

#define MAX_LOADING_BUFFER 50
#define MAX_ROOM_DATA 10

#define FILE_NOT_FOUND -2
#define INVALID_SQUARE_LINE -3
#define INVALID_SQUARE_DATA -4
#define INVALID_SQUARE_POSITION -6
#define INVALID_SQUARE_ROLE -7
#define INVALID_SQUARE_TARGET -8

#define BOLD_BLACK "\e[1;90m"
#define BOLD_YELLOW "\x1B[1;93m"
#define BOLD_MAGENTA "\x1B[1;95m"
#define BOLD_CYAN "\x1B[1;96m"
#define BOLD_WHITE "\e[1;97m"

#define BOLD BOLD_WHITE

#define FONT_RED "\x1B[31m"
#define FONT_BLUE "\x1B[34m"
#define RESET "\x1B[0m"

#define UPPER_LEFT_CORNER "┏"
#define UPPER_RIGHT_CORNER "┓"
#define BOTTOM_LEFT_CORNER "┗"
#define BOTTOM_RIGHT_CORNER "┛"
#define HORIZONTAL_BAR "━━━━"
#define HORIZONTAL_OPEN_BAR "╸  ╺"
#define VERTICAL_BAR "┃"
#define VERTICAL_OPEN_BAR " "

#define INITIAL_PLACEHOLDER "I"
#define CURRENT_PLACEHOLDER "X"
#define FINAL_PLACEHOLDER "F"
#define EMPTY_SPACE " "

void draw_zigzag_board(FILE* fd, Board* board, int current_position);

int init_basic_board(Board* board);

int load_board(Board* board, char* path);

#endif //BOARD_UTILS_H
