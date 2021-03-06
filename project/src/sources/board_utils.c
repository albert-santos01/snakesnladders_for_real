#include <stdio.h>
#include <string.h>

#include "../headers/board_utils.h"

#define INITIAL_SQUARE 0
#define MIDDLE_SQUARE 1
#define LEFT_BOTTOM_SQUARE 2
#define LEFT_TOP_SQUARE 3
#define RIGHT_BOTTOM_SQUARE 4
#define RIGHT_TOP_SQUARE 5
#define LEFT_FINAL_SQUARE 6
#define RIGHT_FINAL_SQUARE 7

typedef struct {
    Square* square;
    int type;
    int current;
} BoardSquare;

void init_bsquare(BoardSquare* bSquare, Square* square, int type, int current) {
    bSquare->square = square;
    bSquare->type = type;
    bSquare->current = current;
}

Square* get_square(BoardSquare* bSquare) {
    return bSquare->square;
}

int get_type(BoardSquare* bSquare) {
    return bSquare->type;
}

int is_current(BoardSquare* bSquare) {
    return bSquare->current;
}

void draw_top(FILE* fd, BoardSquare* bSquare) {
    fprintf(fd, "%s", UPPER_LEFT_CORNER);

    int type = get_type(bSquare);
    if (type == LEFT_BOTTOM_SQUARE || type == RIGHT_BOTTOM_SQUARE) {
        fprintf(fd, HORIZONTAL_OPEN_BAR);
    } else {
        fprintf(fd, "%s", HORIZONTAL_BAR);
    }
    fprintf(fd, "%s", UPPER_RIGHT_CORNER);
}

void draw_middle_top(FILE* fd, BoardSquare* bSquare) {

    int type = get_type(bSquare);
    if (type == INITIAL_SQUARE || type == LEFT_FINAL_SQUARE ||
            type == LEFT_BOTTOM_SQUARE || type == LEFT_TOP_SQUARE) {
        fprintf(fd, "%s", VERTICAL_BAR);
    } else {
        fprintf(fd, "%s", VERTICAL_OPEN_BAR);
    }

    if (type == INITIAL_SQUARE) {
        fprintf(fd, "%s%s%s", BOLD, INITIAL_PLACEHOLDER, RESET);
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, EMPTY_SPACE);

    } else if (type == LEFT_FINAL_SQUARE) {
        fprintf(fd, "%s%s%s", BOLD, FINAL_PLACEHOLDER, RESET);
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, EMPTY_SPACE);

    } else if (type == RIGHT_FINAL_SQUARE) {
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, "%s%s%s", BOLD, FINAL_PLACEHOLDER, RESET);

    } else {
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, "%2d", get_position(bSquare->square));
    }

    if (type == RIGHT_FINAL_SQUARE || type == RIGHT_BOTTOM_SQUARE || type == RIGHT_TOP_SQUARE) {
        fprintf(fd, "%s", VERTICAL_BAR);
    } else {
        fprintf(fd, "%s", VERTICAL_OPEN_BAR);
    }
}
void draw_middle_bottom(FILE* fd, BoardSquare* bSquare) {

    int type = get_type(bSquare);
    if (type == INITIAL_SQUARE || type == LEFT_FINAL_SQUARE ||
        type == LEFT_BOTTOM_SQUARE || type == LEFT_TOP_SQUARE) {
        fprintf(fd, "%s", VERTICAL_BAR);
    } else {
        fprintf(fd, "%s", VERTICAL_OPEN_BAR);
    }

    fprintf(fd, EMPTY_SPACE);

    if (is_current(bSquare) == TRUE) {
        fprintf(fd, "%s%s%s", BOLD_MAGENTA, CURRENT_PLACEHOLDER, RESET);
    } else {
        fprintf(fd, EMPTY_SPACE);
    }

    Square* square = get_square(bSquare);
    if (is_snake(square)) {
        fprintf(fd, "%s%2d%s", FONT_RED, get_target_position(square), RESET);
    } else if (is_ladder(square)) {
        fprintf(fd, "%s%2d%s", FONT_BLUE, get_target_position(square), RESET);
    } else {
        fprintf(fd, EMPTY_SPACE);
        fprintf(fd, EMPTY_SPACE);
    }

    if (type == RIGHT_FINAL_SQUARE || type == RIGHT_BOTTOM_SQUARE || type == RIGHT_TOP_SQUARE) {
        fprintf(fd, "%s", VERTICAL_BAR);
    } else {
        fprintf(fd, "%s", VERTICAL_OPEN_BAR);
    }
}

void draw_bottom(FILE* fd, BoardSquare* bSquare) {
    fprintf(fd, "%s", BOTTOM_LEFT_CORNER);

    int type = get_type(bSquare);
    if (type == LEFT_TOP_SQUARE || type == RIGHT_TOP_SQUARE) {
        fprintf(fd, HORIZONTAL_OPEN_BAR);
    } else {
        fprintf(fd, "%s", HORIZONTAL_BAR);
    }

    fprintf(fd, "%s", BOTTOM_RIGHT_CORNER);
}

void draw_square(FILE* fd, BoardSquare* square, int line) {

    if (line == 0) {
        draw_top(fd, square);

    } else if (line == 1) {
        draw_middle_top(fd, square);

    } else if (line == 2) {
        draw_middle_bottom(fd, square);

    } else if (line == 3) {
        draw_bottom(fd, square);

    } else {
        // error
    }
}

void draw_board(FILE* fd, BoardSquare* matrix, int rows, int columns) {

    for (int idx=0; idx<rows; idx++) {
        for (int line=0; line<4; line++) {
            for (int jdx = 0; jdx < columns; jdx++) {
                BoardSquare* square = &(matrix[idx*columns + jdx]);

                draw_square(fd, square, line);
                fprintf(fd, " ");
            }
            fprintf(fd, "\n");
        }
    }
    fprintf(fd, "\n");
}

void draw_zigzag_board(FILE* fd, Board* board, int current_position) {

    int rows = get_rows(board);
    int columns = get_columns(board);
    BoardSquare matrix[rows][columns];

    int row = rows-1;
    int column = 0;
    int size = get_size(board);
    for (int idx=0; idx < size; idx++) {
        Square* square = get_square_at(board, idx);
        BoardSquare* bSquare = &matrix[row][column];

        int type = MIDDLE_SQUARE;
        if (idx == 0) {
            type = INITIAL_SQUARE;
            column++;

        } else if (row % 2 == rows % 2) {
            if (idx == size-1) {
                type = LEFT_FINAL_SQUARE;

            } else if (column == 0) {
                row--;
                type = LEFT_BOTTOM_SQUARE;

            } else {
                if (column == columns-1) {
                    type = RIGHT_TOP_SQUARE;
                }
                column--;
            }
        } else {
            if (idx == size-1) {
                type = RIGHT_FINAL_SQUARE;

            } else if (column == columns-1) {
                row--;
                type = RIGHT_BOTTOM_SQUARE;
            } else {
                if (column == 0) {
                    type = LEFT_TOP_SQUARE;
                }
                column++;
            }
        }

        int current;
        if (idx == current_position) {
            current = TRUE;
        } else {
            current = FALSE;
        }

        init_bsquare(bSquare, square, type, current);
    }
    draw_board(fd, (BoardSquare *) matrix, rows, columns);
}

/**
 * Creates a plain board of 9 squares (including initial and final) with a ladder in the 2nd square to the 5th square
 * and a snake in the 7th square to the 3rd square.
 *
 * @param board Board structure to be initialized.
 * @return SUCCESS if the board was initialized properly, ERROR if the size is incorrect.
 */
int init_basic_board(Board* board) {

    int status = init_board(board, 3, 3);
    if (status == SUCCESS) {

        int size = get_size(board);
        for (int idx = 0; idx < size; idx++) {
            Square* square = get_square_at(board, idx);
            if (idx == 2) {
                set_target_position(square, 5);
            } else if (idx == 7) {
                set_target_position(square, 3);
            }
        }
    }
    return status;
}

/**
 *  Checks if the input values are valid square values.
 * @param position The square position.
 * @param type The square type (snake or ladder).
 * @param target The target position.
 * @param board_size The size of the board.
 * @return SUCCESS if all the input values are valid, INVALID_SQUARE_DATA otherwise.
 *
 * Pre: -------
 * Post: el status de la acción ha sido devuelto
 */
int check_square_data(int position, char type, int target, int board_size) {
    int status=SUCCESS;
    if (position>board_size-2 || position<1){
        status=INVALID_SQUARE_POSITION;
    } else if (type!='L' && type!='S'){
        status=INVALID_SQUARE_ROLE;
    } else if (target>board_size-2 || target<1){
        status=INVALID_SQUARE_TARGET;
    } else{
        if (type=='L'&& position>target){
            status=INVALID_SQUARE_ROLE;
        } else if (type=='S'&& position<target){
            status=INVALID_SQUARE_ROLE;
        }
    }
    return status;
}

/**
 * Reads a square line from an opened board file, checking its values and configuring the board accordingly.
 * @param board The board to be configured.
 * @param fd The opened board file.
 * @return The status of the action:
 *      - SUCCESS if the file was loaded succesfully.
 *      - INVALID_SQUARE_LINE if an invalid square line is found.
 *      - INVALID_SQUARE_DATA if an invalid square data is found (wrong format, invalid values, etc.)
 *
 * Pre: El fichero fd ha de estar abierto correctamente
 * Post: el status de la acción ha sido devuelto
 */
int read_square_line(Board* board, FILE* fd) {
    int status=SUCCESS;
    char buffer[MAX_LOADING_BUFFER];
    fgets(buffer,MAX_LOADING_BUFFER,fd);
    char type;
    int position;
    int target;
    int match= sscanf(buffer,"%d%c%d",&position,&type,&target);
    if (match==3){
        int b_size =get_size(board);
        status  = check_square_data(position,type,target,b_size);
        if (status==SUCCESS){
            Square* square=get_square_at(board,position);
            set_target_position(square,target);



        } else{
            status=INVALID_SQUARE_TARGET;
        }
    }

    return status;
}

/**
 *  Reads an opened board file, reading the dimensions line and each of the square lines, configuring the
 * board accordingly.
 * @param board The board to be configured.
 * @param fd The opened board file.
 * @return The status of the action:
 *      - SUCCESS if the file was loaded succesfully.
 *      - INVALID_BOARD_DIMENSIONS if the board dimensions are invalid (wrong format, invalid values, etc.)
 *      - INVALID_SQUARE_LINE if an invalid square line is found.
 *      - INVALID_SQUARE_DATA if an invalid square data is found (wrong format, invalid values, etc.)
 *
 * Pre: El fichero fd ha de estar abierto correctamente
 * Post: el status de la acción ha sido devuelto
 *
 */
int read_board_file(Board* board, FILE* fd) {
    int status=SUCCESS;
    char buffer[MAX_LOADING_BUFFER];
    fgets(buffer,MAX_LOADING_BUFFER,fd);
    int rows;
    int columns; //To get the shape

    int match=sscanf(buffer,"%dx%d",&rows,&columns);
    int counter=2;
    if (match==2){
        status=init_board(board,rows,columns);
        while (feof(fd)==0 && status==SUCCESS){
            status=read_square_line(board,fd);
            if (status!=SUCCESS){
                printf("Invalid square line format at line %d, error type: %d\n",counter,status);
            }
            counter++;

        }
    } else{
        status=INVALID_BOARD_DIMENSIONS;
    }
    return status;
}

/**
 *  Opens the file in path and tries to read a board configuration from it.
 *
 * @param board The board to be initialized with the contents of the file in path.
 * @param path The path to the file containing a board configuration encoded as a text file.
 * @return
 *
 * Pre: --------------
 * Post: La función devuelve SUCCES o FILE_NOT_FOUND en función de si se ha abierto el archivo correctamente.
 */
int load_board(Board* board, char* path) {
    FILE* fa=fopen(path,"r");
    int status= SUCCESS;
    if (fa==NULL){
        printf("File not found with path: %s\n",path);
        status=FILE_NOT_FOUND;
    } else{
        read_board_file(board,fa);
        fclose(fa);

    }
    return status;
}