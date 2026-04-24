#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

const int MX=303030;
int N, K, mn, s;
char C[MX];
struct sv {
    int id;
    vector<int> q;

    int front(int x) {
        while (id<q.size() && q[id]<x) id++;
        return id<q.size()?q[id]:-1;
    }
} sc[MX];
int DP[MX], dpc[MX];
int p;

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> C[i], mn=min(mn, s+=(C[i]=='H')*2-1);
    s=10-mn;
    dpc[0]=1; sc[s].q.push_back(0);
    for (int i=1; i<=N; i++) {
        s+=(C[i]=='H')*2-1;
        if (sc[s-1].front(i-K)!=-1) DP[i]=DP[sc[s-1].front(i-K)];
        else {while (!dpc[p]) p++; DP[i]=p+1;}
        dpc[DP[i]]++; p=min(p, DP[i]); sc[s].q.push_back(i);
        if (i>=K) dpc[DP[i-K]]--;
        //cout << i << " " << s << " " << DP[i] << "\n";
    }
    cout << DP[N];

    return 0;
}
