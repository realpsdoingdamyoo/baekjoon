#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int ask(int x) {
    cout << "? " << x << endl;
    cin >> x; return x;
}

signed main() {
    int N; cin >> N;
    int pv=1, D=1, g=1, L=N, R=1;
    while (D<=N-1) {
        pv-=g*(D+N-1>>1); g=-g; D=D+N+1>>1;
        L=min(L, pv); R=max(R, pv);
    }
    pv=2-L;

    ask(pv);

    map<int, int> mp; g=-1;
    int s=1, e=N-1;
    while (s<=e) {
        int m=s+e>>1;
        pv+=g*m; g=-g;
        if (ask(pv)==0) s=m+1;
        else e=m-1;
    }
    cout << "= " << s;

    return 0;
}
