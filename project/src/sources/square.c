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
    return ERROR;
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
    return ERROR;
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
    return ERROR;
}

/**
 * TODO: Clears the square target position, setting its value to EMPTY_TARGET.
 * @param square The square to be modified.
 *
 * Pre:
 * Post:
 */
void clear_target_position(Square* square) {
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
    return ERROR;
}

/**
 * TODO: Returns TRUE if the square contains a snake (targets a lower square), FALSE otherwise.
 * @param square The square to be queried.
 * @return TRUE if the square contains a snake, FALSE otherwise.
 *
 * Pre:
 * Post:
 */
int is_snake(Square* square) {
    return ERROR;
}
