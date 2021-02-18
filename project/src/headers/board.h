#ifndef BOARD_H
#define BOARD_H

#include "common.h"
#include "square.h"

#define MAX_ROWS 10
#define MAX_COLUMNS 10

#define INVALID_BOARD_DIMENSIONS -1

typedef struct {
    int rows;
    int columns;
    Square squares[MAX_COLUMNS*MAX_ROWS];

} Board;

int init_board(Board* board, int rows, int columns);

int get_rows(Board* board);
void set_rows(Board* board, int size);

int get_columns(Board* board);
void set_columns(Board* board, int size);

int get_size(Board* board);

Square* get_square_at(Board* board, int position);

void free_board(Board* board);

#endif //BOARD_H
