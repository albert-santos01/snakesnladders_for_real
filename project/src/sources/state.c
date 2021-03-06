#include <stdio.h>

#include "../headers/state.h"

/**
 * TODO: Initializes the state, setting the playing board, the current position to 0 and finished flag to FALSE.
 *
 * @param state The state to be initialized.
 * @param board The playing board.
 *
 * Pre:
 * Post:
 */
void init_state(State* state, Board* board) {
    state->board=board;
    state->position=0;
    state->finished=FALSE;
}

/**
 * TODO: Sets the current position.
 *
 * @param state The state to be updated.
 * @param position The current position.
 *
 * Pre:
 * Post:
 */
void set_current_position(State* state, int position) {
    state->position=position;
}

/**
 * TODO: Retrieves the current position.
 *
 * @param state The state that stores the current position.
 * @return The current position.
 *
 * Pre:
 * Post:
 */
int get_current_position(State* state) {
    return state->position;
}

/**
 * TODO: Sets the finished flag to finished value (TRUE or FALSE)
 *
 * @param state The state to be updated.
 * @param is_finished The value marking the game as finished or not.
 *
 * Pre:
 * Post:
 */
void set_finished(State* state, int finished) {
    state->finished = finished;
}

/**
 * TODO: Returns the value of is_finished flag (TRUE or FALSE), marking a game as finished.
 *
 * @param state The state to be updated.
 *
 * Pre:
 * Post:
 */
int is_finished(State* state) {
    return state->finished;
}

/**
 * TODO: Moves the player a number of steps in the board, updating the state's current position. If the player ends up in a
 * square containing a ladder or a snake, prints a message (You found a ladder/snake!) and updates the state's current
 * position accordingly. Also, sets the state as finished if it moves to or past the last square.
 *
 * @param board The playing board.
 * @param state The current state.
 * @param steps The number of steps to move.
 *
 * Pre:
 * Post:
 */
void move(State* state, int dice_value) {
    Board* board=state->board; // this is the addressj
    int board_size= get_size(board);
    int current_position= get_current_position(state);
    current_position+= dice_value;
    if (current_position<board_size){
        Square* current_square=get_square_at(board,current_position);
        if (is_ladder(current_square)==TRUE){
            printf("You found a ladder!\n");
            current_position=get_target_position(current_square);
        } else if (is_snake(current_square)==TRUE){
            printf("You found a snake!\n");
            current_position=get_target_position(current_square);
        }
    } else if(current_position>board_size-1){ //ESTO ES QUE HA GANADO SIN CONTAR EL REBOTE
        current_position= board_size -1;
        set_finished(state,TRUE);
    }
    set_current_position(state,current_position);
}
