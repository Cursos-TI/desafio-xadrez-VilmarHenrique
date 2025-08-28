#include <stdio.h>

#define TAB 8

void mover_bispo_rec(int x, int y, int dx, int dy) {
    if (x < 0 || x >= TAB || y < 0 || y >= TAB) return;
    printf("Bispo em (%d,%d)\n", x, y);
    mover_bispo_rec(x + dx, y + dy, dx, dy);
}

int main() {
    int bispoX = 3, bispoY = 3;
    for (int i = 1; i < TAB; i++) {
        if (bispoX + i < TAB && bispoY + i < TAB)
            printf("Bispo diagonal (%d,%d)\n", bispoX + i, bispoY + i);
    }

    int torreX = 4, torreY = 4;
    for (int j = torreY + 1; j < TAB; j++) {
        printf("Torre direita (%d,%d)\n", torreX, j);
    }

    int rainhaX = 5, rainhaY = 5;
    for (int j = rainhaY - 1; j >= 0; j--) {
        printf("Rainha esquerda (%d,%d)\n", rainhaX, j);
    }

    int cavaloX = 3, cavaloY = 3;
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if ((dx * dx + dy * dy) == 5) {
                int nx = cavaloX + dx, ny = cavaloY + dy;
                if (nx >= 0 && nx < TAB && ny >= 0 && ny < TAB)
                    printf("Cavalo (%d,%d)\n", nx, ny);
            }
        }
    }

    printf("\nMovimentação recursiva do Bispo:\n");
    mover_bispo_rec(2, 2, 1, 1);

    printf("\nCavalo avançado:\n");
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if ((dx * dx + dy * dy) != 5) continue;
            int nx = 4 + dx, ny = 4 + dy;
            if (nx < 0 || nx >= TAB || ny < 0 || ny >= TAB) break;
            printf("Cavalo (%d,%d)\n", nx, ny);
        }
    }

    return 0;
}
