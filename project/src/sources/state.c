#include <stdio.h>

#include "../headers/state.h"

/**
 * Initializes the state, setting the playing board, the current position to 0 and finished flag to FALSE.
 *
 * @param state The state to be initialized.
 * @param board The playing board.
 *
 * Pre: El tablero debeb estar inicializado previamente.
 * Post: La función inicializa el tablero de la partida y la posición del jugador.
 */
void init_state(State* state, Board* board) {
    state->board=board;
    state->position=0;
    state->finished=FALSE;
}

/**
 *  Sets the current position.
 *
 * @param state The state to be updated.
 * @param position The current position.
 *
 * Pre: ----------------
 * Post: La función asigna la posicion del jugador a la posición dada.
 */
void set_current_position(State* state, int position) {
    state->position=position;
}

/**
 *  Retrieves the current position.
 *
 * @param state The state that stores the current position.
 * @return The current position.
 *
 * Pre: El state debe estar inicializado.
 * Post: La función te devuelve la posición actual del jugador.
 */
int get_current_position(State* state) {
    return state->position;
}

/**
 *  Sets the finished flag to finished value (TRUE or FALSE)
 *
 * @param state The state to be updated.
 * @param is_finished The value marking the game as finished or not.
 *
 * Pre: -----------------
 * Post: La función asigna la casilla final del tablero con el valor dado.
 */
void set_finished(State* state, int finished) {
    state->finished = finished;
}

/**
 * Returns the value of is_finished flag (TRUE or FALSE), marking a game as finished.
 *
 * @param state The state to be updated.
 *
 * Pre:-------
 * Post: La función te devuelve TRUE o FLASE en función de si se da el juego por finalizado o no.
 */
int is_finished(State* state) {
    return state->finished;
}

/**
 *  Moves the player a number of steps in the board, updating the state's current position. If the player ends up in a
 * square containing a ladder or a snake, prints a message (You found a ladder/snake!) and updates the state's current
 * position accordingly. Also, sets the state as finished if it moves to or past the last square.
 *
 * @param board The playing board.
 * @param state The current state.
 * @param steps The number of steps to move.
 *
 * Pre: El juego debe estar inicializado.
 * Post: La función actualiza la posición del jugador en función de la tirada del dado y si existe una escalera o una snake.
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
