#ifndef STATE_H
#define STATE_H

#include "board.h"
#include "common.h"

typedef struct {
    Board* board;
    int position;
    int finished;
} State;

void init_state(State* state, Board* board);

int get_current_position(State* state);
void set_current_position(State* state, int position);

int is_finished(State* state);
void set_finished(State* state, int finished);

void reset(State* state);

void move(State* state, int dice_value);

#endif //DUNGEON_STATE_H
