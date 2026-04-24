#include <stdio.h>

int main() {
    int table[30][30] = {0};

    for (int i = 0; i < 15; ++i) {
        table[15][14 - i] = 1;
        table[14 - i][15] = 1 * 16;
        table[15][15 + i] = 1 * 16 * 16;
        table[15 + i][15] = 1 * 16 * 16 * 15;
        table[15][15] = 0;
    }

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}
