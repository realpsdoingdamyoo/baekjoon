#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, A[1515];

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) {
        string S; cin >> S;
        int H=(S[0]-'0')*10+(S[1]-'0'), M=(S[3]-'0')*10+(S[4]-'0');
        A[i]=(H*60+M)%720;
    }

    int ans=N;
    for (int i=1; i<=720; i++) {
        set<int> st;
        for (int j=1; j<=N; j++) st.insert((A[j]-j*i-720)%720);
        ans=min(ans, (int)st.size());
    }
    cout << ans;

    return 0;
}
