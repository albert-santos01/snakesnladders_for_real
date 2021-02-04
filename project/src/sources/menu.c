#include <stdio.h>
#include <string.h>

#include "../headers/menu.h"
#include "../headers/game.h"
#include "../headers/utils.h"
#include "../headers/board.h"
#include "../headers/board_utils.h"

int load_from_file(Board* board) {

    char name[MAX_FILENAME];

    printf("\n");
    printf("Which board do you want to load? (Loaded from resources/ dir)\n");

    scanf("%s", name);
    flush_input();

    char path[MAX_FILENAME];
    strncpy(path, "resources/", MAX_FILENAME);
    strcat(path, name);
    strcat(path, ".txt");

    int status = load_board(board, path);

    return status;
}

int init_custom_empty_board(Board* board) {
    int rows = INVALID_OPTION;
    while (rows == INVALID_OPTION) {
        rows = read_int_option("Number of rows: ");
    }
    int columns = INVALID_OPTION;
    while (columns == INVALID_OPTION) {
        columns = read_int_option("Number of columns: ");
    }
    int status = init_board(board, rows, columns);

    return status;
}

int show_load_menu(Board *board) {

    int status = INVALID_OPTION;
    while (status != SUCCESS && status != CANCELLED) {

        if (status != INVALID_OPTION) {
            printf("There was an error (error code: %d). Try again or cancel.\n", status);
        }

        printf("\n");
        printf("Choose a board:\n");
        printf("%d. Minimal board\n", OPTION_LOAD_DEFAULT_MINIMAL);
        printf("%d. Nine-square empty board\n", OPTION_LOAD_DEFAULT_NINE_EMPTY);
        printf("%d. Custom empty board\n", OPTION_LOAD_CUSTOM_EMPTY);
        printf("%d. Nine-square basic board\n", OPTION_LOAD_DEFAULT_NINE_BASIC);
        printf("%d. Load from file\n", OPTION_LOAD_FROM_FILE);
        printf("%d. Cancel\n", OPTION_CANCEL);

        status = SUCCESS;
        int option = read_int_option("");
        switch (option) {
            case OPTION_LOAD_DEFAULT_MINIMAL:
                status = init_board(board, 1, 7);
                break;
            case OPTION_LOAD_DEFAULT_NINE_EMPTY:
                status = init_board(board, 3, 3);
                break;
            case OPTION_LOAD_CUSTOM_EMPTY:
                status = init_custom_empty_board(board);
                break;
            case OPTION_LOAD_DEFAULT_NINE_BASIC:
                status = init_basic_board(board);
                break;
            case OPTION_LOAD_FROM_FILE:
                status = load_from_file(board);
                if (status == SUCCESS) {
                    printf("File loaded successfully!\n");
                } else {
                    printf("Unexpected status after loading!\n");
                }
                break;
            case OPTION_CANCEL:
                status = CANCELLED;
                break;
            default:
                status = INVALID_OPTION;
                printf("Invalid option, try again...\n");
                break;
        }
    }
    // draw_board(stdout, board, NULL);

    return status;
}


void show_game_menu(Board *board) {

    int option = INVALID_OPTION;
    while (option != OPTION_CANCEL) {

        printf("\n");
        printf( "%d. Start game\n", OPTION_START_GAME);
        printf( "%d. Show solution\n", OPTION_SHOW_SOLUTION);
        printf( "%d. Cancel\n", OPTION_CANCEL);
        option = read_int_option("Choose an option: \n");

        switch (option) {
            case OPTION_START_GAME:
                start_game(board);
                break;

            case OPTION_SHOW_SOLUTION:
                solve(board);
                break;

            case OPTION_CANCEL:
                break;

            default:
                printf("Invalid option!\n");
                break;
        }
    }
}

void show_menu() {

    printf("Welcome to the snakes and ladders game!\n");
    printf("What do you want to do?\n");

    int option = INVALID_OPTION;
    while (option != OPTION_QUIT) {

        printf("\n");
        printf( "%d. Load board configuration\n",  OPTION_LOAD);
        printf( "%d. Show empty board\n",  OPTION_EMPTY);
        printf( "%d. Quit\n", OPTION_QUIT);
        option = read_int_option("Choose an option: \n");

        if (option == OPTION_QUIT) {
            // Do nothing, it will exit the loop

        } else if (option == OPTION_LOAD) {

            Board board;
            int load_result = show_load_menu(&board);
            if (load_result == SUCCESS) {
                show_game_menu(&board);
            }

        } else if (option == OPTION_EMPTY) {

            Board board;
            int status = init_board(&board, MAX_ROWS, MAX_COLUMNS);
            if (status == SUCCESS) {
                draw_zigzag_board(stdout, &board, 0);

            } else {
                printf("The initialization was unsuccessful...\n");
            }

        } else {
            printf("Invalid option!\n");
        }
    }
}
