#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int N, M, K;
set<int> st;
map<int, int> mp;

int get(int x) {
    if (mp.find(x)!=mp.end()) return mp[x];
    return x;
}

signed main(){
    fastio;

    cin >> N >> M >> K;
    for (int i=1; i<=K; i++) {
        int x; cin >> x;
        if (x%2==0) st.insert(x);
    }

    if (N==1) {
        int X=0, g=0;
        for (int i=1; i<=M; i++, X+=2) if (st.find(X+2)!=st.end()) {X+=2; g=1; break;}
        if (X==2*M) X=0;
        cout << X;
        return 0;
    }

    for (int i : st) mp[i]=get(i-2);

    int X=0, ss=0;
    for (int i=1; i<M; i++) ss+=(X==get(X+N*2)), X=get(X+N*2);
    cout << (ss?X+2*N:X+2*N-1);

    return 0;
}
