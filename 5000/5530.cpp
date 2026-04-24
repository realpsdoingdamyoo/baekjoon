#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e19;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2")

int n;
string s;
vector<int> L, R;
bool out[1010101];

bool chk(int k) {
    for (int i=0; i<n; i++) out[i]=0;

    if (k==0) return true;
    L.clear(); R.clear();

    for (int i=n-1; i>=0; i--) {
        if (s[i]=='I') {
            R.push_back(i);
            out[i]=1;
        }
        if (R.size()>=k) break;
    }
    reverse(R.begin(), R.end());

    for (int i=0; i<n; i++) {
        if (out[i]) continue;
        if (s[i]=='J' || s[i]=='I') L.push_back(i);
        if (L.size()>=k) break;
    }
    if (L.size()<k || R.size()<k) return false;


    int c=0;
    for (int i=0; i<n; i++) {
        if (s[i]!='O') continue;
        if (i<L[c] || R[c]<i) continue;
        c++;
        if (c==k) return true;
    }
    return false;
}

signed main() {
    fastio;

    cin >> n >> s;

    int S=0, E=n/3;
    while (S<=E) {
        int M=S+E>>1;
        if (chk(M)) S=M+1; else E=M-1;
    }
    cout << E;

    return 0;
}
