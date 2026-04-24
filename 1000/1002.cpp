#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        float  x1, y1, r1, x2, y2, r2;
        scanf("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
        float a=sqrt(pow(x1 - x2, 2)+pow(y1 - y2, 2));
        if(r1==r2 && x1==x2 && y1==y2) printf("-1\n");
        else if(r1+r2>a && r1+a>r2 && r2+a>r1) printf("2\n");
        else if(r1+r2==a || r1+a==r2 || r2+a==r1) printf("1\n");
        else printf("0\n");
    }
}
