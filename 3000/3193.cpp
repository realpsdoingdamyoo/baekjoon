#include <stdio.h>
int pan[1000][1000]={};
int gazzapan[1000][1000]={};
int n, k, dir=1, Lc=0;
int dirs[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void D(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            gazzapan[i][j]=pan[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            pan[i][j]=gazzapan[j][n-i-1];
        }
    }
}

int gc(char d, int p){
    if(d=='L') dir++;
    else dir--;
    dir=(dir+4)%4;
    int x=p/n;
    int y=p%n;
    for(int i=0;; i++){
        if(0>x+dirs[dir][0] || x+dirs[dir][0]>=n) break;
        if(0>y+dirs[dir][1] || y+dirs[dir][1]>=n) break;
        if(pan[x+dirs[dir][0]][y+dirs[dir][1]]==1) break;
        pan[x][y]=0;
        x+=dirs[dir][0];
        y+=dirs[dir][1];
        pan[x][y]=2;
    }
    return x*n+y;
}

int main() {
    int pp, qq;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char x;
            scanf(" %c", &x);
            if(x=='.') pan[i][j]=0;
            else if(x=='X') pan[i][j]=1;
            else if(x=='L') {
                pan[i][j]=2;
                pp=i;
                qq=j;
            }
        }
    }
    char dd;
    for(int p=0; p<k; p++){
        scanf(" %c", &dd);
        int a=gc(dd, pp*n+qq);
        pp=a/n;
        qq=a%n;

    }
    for(int i=0; i<(dir+3)%4; i++) D();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(pan[i][j]==0) printf(".");
            else if(pan[i][j]==1) printf("X");
            else printf("L");
            //printf("%d ", pan[i][j]);
        }
        printf("\n");
    }
}
