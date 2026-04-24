#include <stdio.h>
int pan[21][21];

int ch(int p, int q) {
    int dir[4][2]={{0, 1}, {1, 0}, {1, 1}, {-1, 1}};

    int color=pan[p][q];
    for (int k=0; k<4; k++) {
        int cnt=1;
        int nx=p;
        int ny=q;
        if(pan[nx-dir[k][0]][ny-dir[k][1]]==color) continue;

        while (1) {
            nx+=dir[k][0];
            ny+=dir[k][1];
            if(pan[nx][ny]!=color) break;
            cnt++;
        }

        if (cnt==5) {

            return 1;
        }
    }
    return 0;
}

int main() {
    for (int i=1; i<=19; i++) {
        for (int j=1; j<=19; j++) {
            scanf("%d", &pan[i][j]);
        }
    }
    for (int i=1; i<=19; i++) {
        for (int j=1; j<=19; j++) {
            if(pan[i][j]==0) continue;
            if(ch(i,j)==1) {
                printf("%d\n%d %d", pan[i][j], i, j);
                return 0;
            }
        }
    }
    printf("0\n");
    return 0;
}
