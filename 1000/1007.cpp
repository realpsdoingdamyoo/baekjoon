#include <stdio.h>
#include <math.h>

int bisum(int a){
    int s=0;
    while(1){
        s+=a%2;
        a/=2;
        if(a==0) break;
    }
    return s;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int p=0; p<t; p++){
        long long int n, c=1;
        long long int mind=100000000000;
        long long int x[20]={}, y[20]={};
        scanf("%lld", &n);
        for(int i=0; i<n; i++) {scanf("%lld %lld", &x[i], &y[i]); c*=2;}
        for(int i=1; i<c/2; i++){
            if(bisum(i)!=n/2) continue;
            long long int xx=0, yy=0, cc=1;
            for(int j=0; j<n; j++){
                xx+=x[j]*(((i/cc)%2)*2-1);
                yy+=y[j]*(((i/cc)%2)*2-1);
                cc*=2;
            }
            long long int dx=xx;
            dx*=xx;
            long long int dy=yy;
            dy*=yy;
            long long int d=dx+dy;
            if(d<mind) mind=d;

        }
        printf("%.12f\n", sqrt(mind));
    }
}
