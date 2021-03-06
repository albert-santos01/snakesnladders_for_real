#include "../headers/square.h"

/**
 * TODO: Initializes a square, setting the position and initilizing the target to EMPTY_TARGET.
 * @param square The square to be initialized.
 * @param position The position of the square.
 *
 * Pre:
 * Post:
 */
void init_square(Square* square, int position) {
    square->position=position;
    square->target=EMPTY_TARGET;



}

/**
 * TODO: Returns the position of the square.
 * @param square The square to be queried.
 * @return The position of the square.
 *
 * Pre:
 * Post:
 */
int get_position(Square* square) {
    return square->position;
}

/**
 * TODO: Returns the position the square targets to, if any.
 * @param square The square to be queried.
 * @return The position the square targets or EMPTY_TARGET, if does not target another square.
 *
 * Pre:
 * Post:
 */
int get_target_position(Square* square) {
    return square->target;
}

/**
 * TODO: Sets the position the square targets to.
 * @param square The square to be modified.
 * @return INVALID_POSITION if the target_position is less than 0, SUCCESS otherwise.
 *
 * Pre:
 * Post:
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
 * TODO: Clears the square target position, setting its value to EMPTY_TARGET.
 * @param square The square to be modified.
 *
 * Pre:
 * Post:
 */
void clear_target_position(Square* square) {
    square->target=EMPTY_TARGET;
}

/**
 * TODO: Returns TRUE if the square contains a ladder (targets a higher square).
 * @param square The square to be queried.
 * @return TRUE if the square contains a ladder.
 *
 * Pre:
 * Post:
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
 * TODO: Returns TRUE if the square contains a snake (targets a lower square), FALSE otherwise.
 * @param square The square to be queried.
 * @return TRUE if the square contains a snake, FALSE otherwise.
 *
 * Pre:
 * Post:
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
