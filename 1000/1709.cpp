#include <stdio.h>
#include <math.h>
#define ll long long int

int sq(ll x){
    ll a=floor(sqrt(x));
    if(a*a==x) return 1;
    else return 0;
}

int main () {
    ll n, c=0;
    scanf("%lld", &n); n/=2;
    for(ll i=0; i<n; i++){
        if(sq(n*n-i*i)) c++;
    }
    printf("%d", 4*(2*n-c));
    return 0;
}
