#include <stdio.h>
int main () {
    int n, c=0;
    int a[25][2]={}, cr[25]={}, crmx=0;
    int b, w;
    int x[5]={0, 0, 2, 3, 1};
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &b, &w);
        a[i/2][i%2]=x[b]*50+((b==1 || b==4)?(w-1):(50-w));
    }
    for(int i=1; i<n/2; i++){
        for(int j=0; j<i; j++){
            if(((a[i][0]-a[j][0])*(a[i][1]-a[j][0])>0 && (a[i][0]-a[j][1])*(a[i][1]-a[j][1])<0) || ((a[i][0]-a[j][0])*(a[i][1]-a[j][0])<0 && (a[i][0]-a[j][1])*(a[i][1]-a[j][1])>0)) {c++; cr[i]++; cr[j]++;}
        }
    }
    for(int i=0; i<n/2; i++) crmx=crmx>cr[i]?crmx:cr[i];
    printf("%d\n%d", c, crmx);
    return 0;
}
