#ifndef SQUARE_H
#define SQUARE_H

#include "common.h"

#define EMPTY_TARGET -1

typedef struct {
    int position;
    int target;
} Square;

void init_square(Square* square, int position);

int get_position(Square* square);

int get_target_position(Square* square);
int set_target_position(Square* square, int target_position);

int is_ladder(Square* square);
int is_snake(Square* square);

#endif //SQUARE_H
