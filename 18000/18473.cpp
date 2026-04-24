#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M, X[303030];
int A[303030], B[303030], C[303030];
priority_queue<int, vector<int>, greater<int>> up;
vector<int> ans;

int g[303030];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}

priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq[303030];
map<int, int> mp[303030];

int uv(int x){return (x+1)>>1;}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> X[i], g[i]=i;
    for (int i=1; i<=M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        if (X[A[i]]+X[B[i]]>=C[i]) up.push(i);
        else {
            int lef=uv(C[i]-X[A[i]]-X[B[i]]);
            pq[A[i]].push({X[A[i]]+lef, i}); mp[A[i]][i]=X[A[i]]+lef;
            pq[B[i]].push({X[B[i]]+lef, i}); mp[B[i]][i]=X[B[i]]+lef;
        }
    }

    while (up.size()) {
        int p=up.top(); up.pop();
        if (Find(A[p])==Find(B[p])) continue;
        ans.push_back(p);

        int x=Find(A[p]), y=Find(B[p]);
        if (mp[x].size()<mp[y].size()) swap(x, y);

        while (pq[y].size()) pq[x].push(pq[y].top()), pq[y].pop();
        for (pair<int, int> i : mp[y]) mp[x][i.first]=i.second;
        X[x]+=X[y]; g[y]=x;

        while (pq[x].size() && X[x]>=pq[x].top()[0]) {
            array<int, 2> v=pq[x].top(); pq[x].pop();
            int n=v[1];
            if (mp[x].find(n)==mp[x].end() || mp[x][n]!=v[0]) continue;
            A[n]=Find(A[n]); B[n]=Find(B[n]);
            if (A[n]==B[n]) continue;
            if (X[A[n]]+X[B[n]]>=C[n]) {
                up.push(n);
                for (int i : {A[n], B[n]}) mp[i][n]=-1;
            }
            else {
                int lef=uv(C[n]-X[A[n]]-X[B[n]]);
                pq[A[n]].push({X[A[n]]+lef, n}); mp[A[n]][n]=X[A[n]]+lef;
                pq[B[n]].push({X[B[n]]+lef, n}); mp[B[n]][n]=X[B[n]]+lef;
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";


    return 0;
}
