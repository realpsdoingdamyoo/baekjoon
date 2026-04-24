#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    ll n, m, k;
    cin >> n >> k >> m;
    ll l=min(200LL, m/k);
    while(l--) n/=2;
    cout << n;

    return 0;
}
