#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int N, A[303030], P[303030];
vector<int> R[303030];

const int X=20;
int seg[2<<X];

void update(int p, int x) {
    p+=1<<X;
    while (p) seg[p]+=x, p>>=1;
}
int sum(int s, int e) {
    s+=1<<X; e+=1<<X; int r=0;
    while (s<=e) {
        if (s&1) r+=seg[s];
        if (~e&1) r+=seg[e];
        ++s>>=1; --e>>=1;
    }
    return r;
}

void solve() {
    cin >> N;
    for (int i=1; i<=N; i++) R[i].clear(), update(i, -sum(i, i));
    for (int i=1; i<=N; i++) cin >> A[i], R[A[i]].push_back(i);

    set<int> st;
    for (int i=N; i>=1; i--) {
        for (int j : R[i]) st.insert(j);
        if (st.size()==0) {cout << "-1\n"; return;}
        int p=*prev(st.end()); st.erase(st.find(p));
        P[i]=p;
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        ans+=sum(P[i], N);
        update(P[i], 1);
    }
    cout << ans << "\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
