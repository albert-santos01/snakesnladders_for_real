#ifndef COMMON_H
#define COMMON_H

#define MAX_FILENAME 100
#define MAX_STRING 100

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define ERROR -1
#define CANCELLED -2
#define INVALID_OPTION -3
#define INVALID_ROW -4
#define INVALID_COLUMN -5
#define INVALID_POSITION -6

typedef struct {
    int row;
    int column;
} Position;

#endif //COMMON_H
