#include <stdio.h>
#include <math.h>
#define ll long long int

ll tx, ty, n;
ll px[500000], py[500000];

int main() {
    scanf("%lld", &n);
    for(int i=0; i<n; i++) scanf("%lld %lld", &px[i], &py[i]);
    scanf("%lld %lld", &tx, &ty);
    ll a[4]={};
    for(int i=0; i<n; i++){
        if(px[i]>tx && -(px[i]-tx)<=(py[i]-ty) && (py[i]-ty)<=(px[i]-tx)) a[0]=1;
    }
    for(ll i=0; i<n; i++){
        if(py[i]>ty && -(py[i]-ty)<=(px[i]-tx) && (px[i]-tx)<=(py[i]-ty)) a[1]=1;
    }
    for(ll i=0; i<n; i++){
        if(px[i]<tx && -(tx-px[i])<=(py[i]-ty) && (py[i]-ty)<=(tx-px[i])) a[2]=1;
    }
    for(ll i=0; i<n; i++){
        if(py[i]<ty && -(ty-py[i])<=(px[i]-tx) && (px[i]-tx)<=(ty-py[i])) a[3]=1;
    }
    if(a[0]*a[1]*a[2]*a[3]) printf("NO"); else printf("YES");


    return 0;
}
