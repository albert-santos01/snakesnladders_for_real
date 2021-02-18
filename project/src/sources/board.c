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
    int status=SUCCESS;

    if( rows>MAX_ROWS || columns>MAX_COLUMNS || rows<1|| columns<2){
        status= INVALID_BOARD_DIMENSIONS;
    }else{
        set_rows(board,rows);
        set_columns(board,columns);
        int size= get_size(board);
        for (int i = 0; i < size; ++i) {
            init_square(&board->squares[i],i);

        }
    }
    return status;




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

    return board->rows;
}

/**
 * TODO: Sets the number of rows of the board.
 * @param board The board to be queried.
 *
 * Pre:
 * Post:
 */
void set_rows(Board* board, int rows) {
    board->rows=rows;
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
    return board->columns;
}

/**
 * TODO: Sets the number of columns of the board.
 * @param board The board to be queried.
 *
 * Pre:
 * Post:
 */
void set_columns(Board* board, int columns) {
    board->columns=columns;
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
    return board->rows*board->columns;
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
    if (position>=0 && position<get_size(board)){
        return &board->squares[position];
    } else{
        return NULL;
    }


}
