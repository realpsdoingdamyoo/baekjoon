#include "Alice.h"
#include "Bob.h"

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

vector<pair<signed, signed>> Alice() {
    int N=5000, X=setN(N);
    vector<pair<signed, signed>> ret;
    for (int i=1; i<N; i++) ret.push_back({X%i+1, i+1});
    return ret;
}
int Bob(vector<pair<signed, signed>> v) {
    int N=5000; __int128 p=1, x=0;
    for (pair<signed, signed> pr : v) {
        int X=pr.first-1, P=pr.second-1;
        if (__gcd((int)p, P)>1) continue;
        for (int i=0; i<P; i++) if ((p*i+x)%P==X){x=p*i+x; p=p*P; break;}
        if (p>1e18) break;
    }
    return (int)x;
}
