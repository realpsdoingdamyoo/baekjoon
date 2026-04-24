#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, K, C, OMX;
int V[550][10], U[550];
set<vector<int>> st;
unordered_map<int, int> mp;
int wp(vector<int>& v){int r=0; for (int i=0; i<K; i++) r|=v[i+1]<<(i*10); return r;}

signed main() {
    fastio;

    cin >> N >> K >> C;
    for (int i=1; i<=N; i++) for (int j=1; j<=K; j++) cin >> V[i][j];
    vector<int> p(K+1);
    for (int j=1; j<=K; j++) {
        for (int i=1; i<=N; i++) if (V[p[j]][j]<V[i][j]) p[j]=i;
        p[0]+=V[p[j]][j];
        if (U[p[j]]) {p[j]=1; while (U[p[j]]) p[j]++;}
        U[p[j]]=-1;
    }
    sort(p.begin()+1, p.end());

    st.insert(p); mp[wp(p)]++;
    for (int t=1; t<C; t++) {
        p=*prev(st.end()); st.erase(prev(st.end()));
        for (int j=1; j<=K; j++) U[p[j]]=t;
        for (int j=1; j<=K; j++) {
            vector<int> prq(K+1, 0);
            for (int k=1; k<=K; k++) for (int l=1; l<=K; l++) if (j!=l) prq[k]=max(prq[k], V[p[l]][k]);
            for (int i=1; i<=N; i++) if (U[i]!=t) {
                vector<int> q=p; q[j]=i; q[0]=0;
                for (int k=1; k<=K; k++) q[0]+=max(V[i][k], prq[k]);
                if (q[0]<=OMX) continue;
                sort(q.begin()+1, q.end());
                if (!mp[wp(q)]++) st.insert(q);
            }
        }
        while (st.size()>C) OMX=max(OMX, (*st.begin())[0]), st.erase(st.begin());
    }
    cout << (*prev(st.end()))[0];

    return 0;
}
