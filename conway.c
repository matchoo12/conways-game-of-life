#include "conway.h"

int count_alive(char field[HEIGHT][WIDTH], int row, int col)
{
    int count = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0)
                continue;
            int r = row + dr;
            int c = col + dc;
            if (r >= 0 && r < HEIGHT && c >= 0 && c < WIDTH && field[r][c] == '#')
                count++;
        }
    }
    return count;
}

void evolve(char field[HEIGHT][WIDTH], char next[HEIGHT][WIDTH])
{
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            int n = count_alive(field, r, c);
            if (field[r][c] == '#')
                next[r][c] = (n == 2 || n == 3) ? '#' : '.';
            else
                next[r][c] = (n == 3) ? '#' : '.';
        }
    }
}
