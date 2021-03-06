#include "../headers/square.h"

/**
 *  Initializes a square, setting the position and initilizing the target to EMPTY_TARGET.
 * @param square The square to be initialized.
 * @param position The position of the square.
 *
 * Pre: --------------------
 * Post: La función inicializa el square asignando una posición y tambien inicializa el target.
 */
void init_square(Square* square, int position) {
    square->position=position;
    square->target=EMPTY_TARGET;



}

/**
 *  Returns the position of the square.
 * @param square The square to be queried.
 * @return The position of the square.
 *
 * Pre: La estructura debe estar inicializada correctamente.
 * Post: La función te retorna la posición de la casilla.
 */
int get_position(Square* square) {
    return square->position;
}

/**
 *  Returns the position the square targets to, if any.
 * @param square The square to be queried.
 * @return The position the square targets or EMPTY_TARGET, if does not target another square.
 *
 * Pre:Pre: La estructura debe estar inicializada correcatemnte.
 * Post: La función te devuelve EMPTY_TARGET si no hay a donde ir o en otro caso las posición de la casilla.
 */
int get_target_position(Square* square) {
    return square->target;
}

/**
 *  Sets the position the square targets to.
 * @param square The square to be modified.
 * @return INVALID_POSITION if the target_position is less than 0, SUCCESS otherwise.
 *
 * Pre: ---------------
 * Post: La funcion asigna el target de la estructura square al valor recibido target_position. Si el valor es <0 te devuelve INVALID_POSITION.
 */
int set_target_position(Square* square, int target_position) {
    int status=SUCCESS;
    if (target_position<0){
        status=INVALID_POSITION;
    } else{
        square->target=target_position;
    }
    return status;
}

/**
 *  Clears the square target position, setting its value to EMPTY_TARGET.
 * @param square The square to be modified.
 *
 * Pre: -----------------
 * Post: La función asigna target del square a EMPTY_TARGET (limpia el target)
 */
void clear_target_position(Square* square) {
    square->target=EMPTY_TARGET;
}

/**
 *  Returns TRUE if the square contains a ladder (targets a higher square).
 * @param square The square to be queried.
 * @return TRUE if the square contains a ladder.
 *
 * Pre: El target tiene que apuntar a una casilla superior.
 * Post: La función te retorna TRUE o FALSE si encuentra una escalera o no.
 */
int is_ladder(Square* square) {
    int is_ladder;
    if (square->target==EMPTY_TARGET){
        is_ladder=FALSE;

    } else{
        if (square->position < square->target){
            is_ladder=TRUE;

        } else{
            is_ladder=FALSE;
        }
    }
    return is_ladder;
}

/**
 *  Returns TRUE if the square contains a snake (targets a lower square), FALSE otherwise.
 * @param square The square to be queried.
 * @return TRUE if the square contains a snake, FALSE otherwise.
 *
 * Pre: El target tiene que apuntar a una casilla inferior.
 * Post: La función te retorna TRUE o FALSE si encuentra una snake o no.
 */
int is_snake(Square *square) {
    int is_snake;
    if (square->target==EMPTY_TARGET){
        is_snake=FALSE;

    } else{
        if (square->position > square->target){
            is_snake=TRUE;

        } else{
            is_snake=FALSE;
        }
    }
    return is_snake;
}
