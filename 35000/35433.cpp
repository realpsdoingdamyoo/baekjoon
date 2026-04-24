#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
int N, X, dv=1, R;
int A[10101010];
 
signed main() {
    fastio;
 
    cin >> N >> X;
    vector<array<int, 2>> g={{0, 1}};
 
    for (int i=1; i<=N; i++) {
        int a, l; cin >> a >> l; dv*=X-1;
        vector<array<int, 2>> ng;
        for (array<int, 2> p : g) ng.push_back({p[0]+l, a*p[1]}), ng.push_back({p[0], -a*p[1]});
        g=ng;
    }
 
    for (array<int, 2> i : g) A[i[0]]+=i[1], R=max(R, i[0]);
 
    for (int i=0; i<R || A[i]; i++) {
        int up=(A[i]+mod*X)/X-mod;
        A[i]-=up*X; A[i+1]+=up; R=max(R, i+1);
    }
    while (A[R]==0) R--;
 
    for (int i=R; i>=0; i--) {
        if (i) A[i-1]+=A[i]%dv*X;
        A[i]/=dv;
    }
    while (A[R]==0) R--;
 
    for (int i=R; i>=0; i--) cout << A[i];
 
    return 0;
}
