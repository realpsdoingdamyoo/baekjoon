#include <stdio.h>
#include <math.h>

int ifin(float cx, float cy, float r, float x, float y){
    if(sqrt(pow(cx-x, 2)+pow(cy-y, 2))<=r) return 1;
    else return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int p=0;
        char pp[1000]="";
        float x1, y1, x2, y2;
        scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
        int m, cnt=0;
        float cx, cy, r;
        scanf("%d", &m);
        for(int j=0; j<m; j++){
            scanf("%f %f %f", &cx, &cy, &r);
            if(ifin(cx, cy, r, x1, y1)+ifin(cx, cy, r, x2, y2)==1) cnt++;
        }


        printf("%d\n", cnt);
    }
}
