#include <stdio.h>
#include <string.h>

#include "../headers/utils.h"
#include "../headers/common.h"

void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int read_int_option(const char* msg) {
    int option = INVALID_OPTION;
    printf("%s", msg);
    scanf("%d", &option);

    flush_input();

    return option;
}

char read_char_option(const char* msg) {
    char option = '\0';
    printf("%s", msg);
    scanf("%c", &option);

    flush_input();

    return option;
}


void log_info(FILE* fd, char* msg) {
    if (LOG_LEVEL >= INFO_LEVEL) {
        fprintf(fd, "INFO: %s\n", msg);
        fflush(fd);
    }
}

void log_warn(FILE* fd, char* msg) {
    if (LOG_LEVEL >= WARN_LEVEL) {
        fprintf(fd,"WARNING: %s\n", msg);
        fflush(fd);
    }
}

void log_error(FILE* fd, char* msg) {
    if (LOG_LEVEL >= ERROR_LEVEL) {
        fprintf(fd,"ERROR: %s\n", msg);
        fflush(fd);
    }
}



