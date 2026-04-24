#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int pw(int a) {
    int x=2, r=1;
    while (a) {if (a&1) r=r*x%mod; x=x*x%mod; a>>=1;}
    return r;
}

signed main() {
    fastio;

    int N, M, K;
    map<int, int> mp;
    map<int, vector<array<int, 2>>> p;

    cin >> N >> M >> K;
    int T=N, R=0;

    for (int i=1; i<=K; i++) {
        int x, y; char c;
        cin >> c >> x >> y;
        int z=c=='+';
        p[y].push_back({x, z});
        z^=1^y&1;
        if (mp.find(x)==mp.end()) mp[x]=z, T--;
        else if (mp[x]!=z) T=-1;
    }

    if (T>=0) {
        R+=pw(T);
        int f1=1, f2=1;

        for (pair<int, int> i : mp) if ((i.first&1)==i.second) f1=0;
        if (f1) R--;

        for (pair<int, int> i : mp) if ((i.first&1)!=i.second) f2=0;
        if (f2) R--;
    }

    T=M;

    for (pair<int, vector<array<int, 2>>> i : p) {
        int c=-1;
        for (array<int, 2> j : i.second) {
            int f=1^j[0]&1;
            if (c==-1) T--, c=j[1]^f;
            else if (c!=(j[1]^f)) {T=-1; break;}
        }
    }

    if (T>=0) R+=pw(T);

    cout << (R+mod)%mod;

    return 0;
}
