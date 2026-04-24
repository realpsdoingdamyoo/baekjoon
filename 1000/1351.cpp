#include <stdio.h>
#define ll long long int

ll a[1000000], p, q;

void makea(){
    a[0]=1;
    for(ll i=1; i<1000000; i++) a[i]=a[i/p]+a[i/q];
}

ll niga(ll x){
    if(x<1000000) return a[x];
    return niga(x/p)+niga(x/q);
}

int main(){
    ll n;
    scanf("%lld %lld %lld", &n, &p, &q);
    makea();
    printf("%lld", niga(n));
    return 0;
}
