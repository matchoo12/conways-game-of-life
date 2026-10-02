#include <stdio.h>
#include <string.h>
#include "conway.h"

static void dump_field(char field[HEIGHT][WIDTH])
{
    for (int r = 0; r < HEIGHT; r++) {
        fwrite(field[r], 1, WIDTH, stdout);
        putchar('\n');
    }
}

int main(void)
{
    char a[HEIGHT][WIDTH];
    char b[HEIGHT][WIDTH];

    memset(a, '.', sizeof a);
    /* a glider */
    a[1][2] = '#';
    a[2][3] = '#';
    a[3][1] = '#';
    a[3][2] = '#';
    a[3][3] = '#';

    for (int g = 0; g < GENERATIONS; g++) {
        printf("Generation %d\n", g);
        dump_field(a);
        printf("\n");
        evolve(a, b);
        memcpy(a, b, sizeof a);
    }
    return 0;
}
