#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
int N, A, ans;
array<int, 4> V[10101];
 
int pw(int x) {
    int a=A, r=1;
    while (x) {
        if (x&1) r=r*a%mod;
        a=a*a%mod; x>>=1;
    }
    return r;
}
 
signed main() {
    fastio;
 
    cin >> N >> A;
    for (int i=1; i<=N; i++) {
        cin >> V[i][0] >> V[i][1] >> V[i][2];
        V[i][3] = V[i][2] * (V[i][1] + 1);
    }
    sort(V+1, V+N+1, [&](array<int, 4> a, array<int, 4> b){return a[1]>b[1];});
 
    int L=V[1][0]-V[1][2]+1, R=V[1][0]+V[1][2]-1;
    map<int, vector<int>> mp;
 
    for (int i=1; i<=N; i++) {
        int p=V[i][0], l=V[i][1], d=V[i][2], w=V[i][3];
        for (int x=L; x<=R; x++) if (abs(p-x)<w)
            mp[x].push_back(l-abs(p-x)/d);
    }
 
    pair<vector<int>, int> pr={{}, 0};
    for (pair<int, vector<int>> i : mp) {
        sort(i.second.begin(), i.second.end());
        reverse(i.second.begin(), i.second.end());
        pr=max(pr, {i.second, i.first});
    }
    for (int i : pr.first) ans+=pw(i);
 
    cout << ans%mod << "\n" << pr.second;
 
    return 0;
}
