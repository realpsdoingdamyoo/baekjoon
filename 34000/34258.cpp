#include "macht.h"
#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
vector<int> lnk[50505];
int L[50505];

int P[50505], SZ[50505], D[50505];
void dfs(int p) {
    for (int& i : lnk[p]) if (i==P[p]) {swap(i, lnk[p].back()); lnk[p].pop_back(); break;}
    SZ[p]=1;
    for (int& i : lnk[p]) {
        P[i]=p; dfs(i); SZ[p]+=SZ[i];
        if (SZ[lnk[p][0]]<SZ[i]) swap(lnk[p][0], i);
    }
}
void dfs2(int p) {
    for (int i : lnk[p]) D[i]=D[p]+(i!=lnk[p][0]), dfs2(i);
}

pair<vector<int>, vector<int>> RFS(int w, int x) {
    vector<int> ret1(n-1, 1), ret2(n, 0);
    for (int i=1; i<n; i++) if (D[i]==w) ret1[L[i]]=0;
    for (int i=1; i<n; i++) if (D[i]==w && lnk[i].size()==0) ret2[i]=x;
    return {ret1, ret2};
}

void unravel(vector<int> U, vector<int> V) {
    n=U.size()+1;
    for (int i=0; i<n-1; i++) {
        lnk[U[i]].push_back(V[i]);
        lnk[V[i]].push_back(U[i]);
    }
    dfs(0); dfs2(0);
    int X=0; for (int i=0; i<n; i++) X=max(X, D[i]);
    for (int i=0; i<n-1; i++) L[(P[U[i]]==V[i])?U[i]:V[i]]=i;

    int ans=1e5;

    vector<int> ord;
    for (int i=0; i<=X; i++) ord.push_back(i);
    for (int i=X; i>=0; i--) swap(ord[i], ord[rand()%(i+1)]);
    
    for (int i : ord) {
        pair<vector<int>, vector<int>> vec=RFS(i, ans);
        int x=trigger(vec.first, vec.second), y=0;
        for (int j : vec.second) y+=j;
        if (x==y) continue;
        
        int s=1, e=ans-1;
        while (s<=e) {
            int m=s+e>>1;
            vec=RFS(i, m);
            x=trigger(vec.first, vec.second); y=0;
            for (int j : vec.second) y+=j;
            if (x==y) s=m+1; else e=m-1;
        }
        ans=min(ans, e);
    }
    answer(ans);
}
