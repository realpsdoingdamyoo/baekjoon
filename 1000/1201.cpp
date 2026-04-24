#include<stdio.h>

int main()
{
    int n, m, k, c=1, mm=0;
    scanf("%d %d %d", &n, &m, &k);
    if(n<m+k-1 || n>m*k) printf("-1");
    else if(n!=m*k){
        for(int i=0; i<(n-m)/(k-1); i++){
            for(int j=0; j<k; j++){
                printf("%d ", i*k+k-j);
                c++;
            }
            mm++;
        }
        for(int i=n-m+mm+1; i>=c; i--) printf("%d ", i);
        for(int i=mm+1; i<m; i++){
            printf("%d ", n-m+i+1);
        }
    }
    else{
        for(int j=0; j<m; j++){
            for(int i=k; i>=1; i--) printf("%d ", j*k+i);
        }
    }
    return 0;
}
