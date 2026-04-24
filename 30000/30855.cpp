#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

__int128 gcd(__int128 a, __int128 b){return b?gcd(b, a%b):a;}

struct frac {
    int g;
    __int128 a, b;
    void yak() {
        int d=gcd(a, b);
        a/=d; b/=d;
    }
};

frac add(frac x, frac y) {
    frac r={0, x.a*y.b+y.a*x.b, x.b*y.b};
    r.yak(); return r;
}

frac div(frac x, frac y) {
    frac r={0, x.a*y.b, y.a*x.b};
    r.yak(); return r;
}

vector<frac> st;

signed main() {
    fastio;

    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        string s; cin >> s; frac x;
        if (s=="(") x={1, 0, 0};
        else if (s==")") x={-1, 0, 0};
        else x={0, s[0]-'0', 1};
        if (x.g==-1) {
            if (st.size()<4){cout << "-1\n"; return 0;}
            frac a, b, c, d;
            d=st.back(); st.pop_back();
            c=st.back(); st.pop_back();
            b=st.back(); st.pop_back();
            a=st.back(); st.pop_back();
            if (a.g!=1 || b.g!=0 || c.g!=0 || d.g!=0){cout << "-1\n"; return 0;}
            st.push_back(add(b, div(c, d)));
        }
        else st.push_back(x);
    }
    if (st.size()==1 && st[0].g==0) cout << (int)st[0].a << " " << (int)st[0].b << "\n";
    else cout << "-1\n";

    return 0;
}
