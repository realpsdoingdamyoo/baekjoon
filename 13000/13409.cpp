#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

const int X=1LL<<40;

signed main(){
    fastio;

    int N; cin >> N;
    vector<array<int, 2>> V[2];
    unordered_map<int, int> mp;

    for (int i=1; i<=N; i++) {
        string S; cin >> S;
        int R=0, T=X;
        for (int c : S) {
            if (c!=S[0] || T!=X) T>>=1;
            R+=(c=='B'?1:-1)*T;
        }
        V[i%2].push_back({R, (int)S.length()});
    }

    int ans=0;
    for (int b : {0, 1}) {
        for (int x=0; x<1<<V[b].size(); x++) {
            array<int, 2> R={0, 0};
            for (int i=0; i<V[b].size(); i++) if (x&1<<i)
                R[0]+=V[b][i][0], R[1]+=V[b][i][1];
            if (b==0) mp[R[0]]=max(mp[R[0]], R[1]+inf);
            else ans=max(ans, R[1]+mp[-R[0]]-inf);
        }
    }
    cout << ans;

    return 0;
}
