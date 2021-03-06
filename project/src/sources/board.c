#include <stdlib.h>

#include "../headers/board.h"

/**
 *  Initializes the board, initializing also each square of it.
 * @param board The board to be initialized.
 * @param rows The number of rows of the board.
 * @param columns The number of columns of the board.
 * @return SUCCESS code if the initialization was successful, ERROR code if rows are less than 1 or more than MAX_ROWS
 * or if columns is less than 2 or more than MAX_COLUMNS.
 *
 * Pre: -----------
 * Post: Función que inicializa el tablero y te devuelve SUCCESS o ERROR en función de si se ha hecho correctamente o no.
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
 *  Returns the number of rows of the board.
 * @param board The board to be queried.
 * @return The number of rows of the board.
 *
 * Pre:---------------
 * Post: La función te devuelve las filas del tablero dado
 */
int get_rows(Board* board) {

    return board->rows;
}

/**
 * Sets the number of rows of the board.
 * @param board The board to be queried.
 *
 * Pre:-----------
 * Post: La funcion asigna las filas del tablero con el entero recibido.
 */
void set_rows(Board* board, int rows) {
    board->rows=rows;
}

/**
 *  Returns the number of columns of the board.
 * @param board The board to be queried.
 * @return The number of columns of the board.
 *
 * Pre: ---------------------
 * Post: La función te devuelve las columnas del tablero.
 */
int get_columns(Board* board) {
    return board->columns;
}

/**
 *  Sets the number of columns of the board.
 * @param board The board to be queried.
 *
 * Pre: -----------------
 * Post: La funcion asigna  las columnas del tablero con el entero recibido
 */
void set_columns(Board* board, int columns) {
    board->columns=columns;
}

/**
 *  Returns the size of the board, it is, the total number of squares.
 * @param board The board to be queried.
 * @return The size of the board.
 *
 * Pre: El board debe haber sido asignado con enteros en el columns y rows previamente.
 * Post: La función te devuelve el tamaño total del tablero en filas * columnas.
 */
int get_size(Board* board) {
    return board->rows*board->columns;
}

/**
 * Returns the board square at the specific position.
 *
 * @param board The board from which the square should be retrieved.
 * @param position The position of the square.
 * @return The (reference to the) square of the board corresponding to the position if valid, NULL otherwise.
 *
 * Pre: El board debe haber sido asignada con enteros en el columns y rows previamente.
 * Post: La función retornará la referéncia del square con su dicha posición, de lo contrario, retornará NULL.
 */
Square* get_square_at(Board *board, int position) {
    if (position>=0 && position<get_size(board)){
        return &board->squares[position];
    } else{
        return NULL;
    }


}
