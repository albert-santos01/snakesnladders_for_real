#include <stdlib.h>

#include "../headers/board.h"

/**
 * TODO: Initializes the board, initializing also each square of it.
 * @param board The board to be initialized.
 * @param rows The number of rows of the board.
 * @param columns The number of columns of the board.
 * @return SUCCESS code if the initialization was successful, ERROR code if rows are less than 1 or more than MAX_ROWS
 * or if columns is less than 2 or more than MAX_COLUMNS.
 *
 * Pre:
 * Post:
 */
int init_board(Board* board, int rows, int columns) {
    return INVALID_BOARD_DIMENSIONS;
}

/**
 * TODO: Returns the number of rows of the board.
 * @param board The board to be queried.
 * @return The number of rows of the board.
 *
 * Pre:
 * Post:
 */
int get_rows(Board* board) {
    return ERROR;
}

/**
 * TODO: Sets the number of rows of the board.
 * @param board The board to be queried.
 *
 * Pre:
 * Post:
 */
void set_rows(Board* board, int rows) {
}

/**
 * TODO: Returns the number of columns of the board.
 * @param board The board to be queried.
 * @return The number of columns of the board.
 *
 * Pre:
 * Post:
 */
int get_columns(Board* board) {
    return ERROR;
}

/**
 * TODO: Sets the number of columns of the board.
 * @param board The board to be queried.
 *
 * Pre:
 * Post:
 */
void set_columns(Board* board, int columns) {
}

/**
 * TODO: Returns the size of the board, it is, the total number of squares.
 * @param board The board to be queried.
 * @return The size of the board.
 *
 * Pre:
 * Post:
 */
int get_size(Board* board) {
    return ERROR;
}

/**
 * TODO: Returns the board square at the specific position.
 *
 * @param board The board from which the square should be retrieved.
 * @param position The position of the square.
 * @return The (reference to the) square of the board corresponding to the position if valid, NULL otherwise.
 *
 * Pre:
 * Post:
 */
Square* get_square_at(Board *board, int position) {
    return NULL;
}
