#include "hack.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int Find(int x) {
    int y=x;
    for (int i=2; i*i<=y; i++) if (y%i==0) {
        while (x%i==0 && collisions({1, x/i+1})) x/=i;
        while (y%i==0) y/=i;
    }
    if (y>1 && collisions({1, x/y+1})) x/=y;
    return x;
}

const int X=1000032000;
bool isn(int l, int r) {
    vector<int> vec;
    int B=(int)sqrt(r-l+1);
    for (int i=l; i<=r; i+=B) vec.push_back(min(i, r-B+1));
    for (int i=X-B+1; i<=X; i++) vec.push_back(i);
    return collisions(vec);
}

signed hack() {
    int s=1, e=X>>1;
    while (s<e) {
        int m=s+e>>1;
        if (isn(s, m)) e=m;
        else s=m+1;
    }

    return Find(X-s);
}
