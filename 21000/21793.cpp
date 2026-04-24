#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, K;
array<int, 2> v[303030];
vector<int> x;
int sp[606060][20];

int mxs(int s, int e) {
    if (s>=e) return 0;
    int r=0;
    for (int i=19; i>=0; i--) if (sp[s][i]<e) s=sp[s][i]+1, r+=1<<i;
    return r;
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> v[i][0] >> v[i][1]; v[i][1]--;
        x.push_back(v[i][0]); x.push_back(v[i][1]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i=1; i<=N; i++) {
        v[i][0]=lower_bound(x.begin(), x.end(), v[i][0])-x.begin()+1;
        v[i][1]=lower_bound(x.begin(), x.end(), v[i][1])-x.begin()+1;
    }

    for (int i=1; i<=N*2+1; i++) sp[i][0]=inf;
    for (int j=1; j<20; j++) sp[N*2+1][j]=inf;

    for (int i=1; i<=N; i++) sp[v[i][0]][0]=min(sp[v[i][0]][0], v[i][1]);
    for (int i=N*2; i>=1; i--) sp[i][0]=min(sp[i][0], sp[i+1][0]);

    for (int j=1; j<20; j++) {
        for (int i=1; i<=N*2; i++) {
            if (sp[i][j-1]==inf) sp[i][j]=inf;
            else sp[i][j]=sp[sp[i][j-1]+1][j-1];
        }
    }

    set<array<int, 2>> st; st.insert({-1, 0}); st.insert({N*2+1});
    int M=mxs(1, 2*N+1);

    vector<int> ans;
    for (int i=1; i<=N; i++) {
        array<int, 2> pv, nx;
        pv=*prev(st.lower_bound({v[i][0], v[i][1]}));
        nx=*st.lower_bound({v[i][0], v[i][1]});
        if (v[i][0]<=pv[1] || nx[0]<=v[i][1]) continue;
        int D=mxs(pv[1]+1, nx[0])-mxs(pv[1]+1, v[i][0])-mxs(v[i][1]+1, nx[0]);
        if (M-D+1>=K) M-=D-1, ans.push_back(i), st.insert(v[i]);
    }

    if (ans.size()>=K) for (int i=0; i<K; i++) cout << ans[i] << "\n";
    else cout << "-1";

    return 0;
}
