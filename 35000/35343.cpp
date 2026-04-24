#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e17;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,sse,sse2,lzcnt,popcnt")

int N, M, R=1;
array<int, 2> C[202020][2];
int dep[202020];

const int X=300;
struct dp{
    vector<pair<int, vector<int>>> V;
    int sz=0;

    void update(int p) {
        if (V[p].second.size()>2*X) {
            vector<int> tmp;
            for (int i=X; i<V[p].second.size(); i++) tmp.push_back(V[p].second[i]);
            V[p].second.resize(X);
            V.insert(V.begin()+p+1, {0, tmp});
            update(p+1); update(p);
        }
        else {
            V[p].first=inf;
            for (int i=0; i<V[p].second.size(); i++) V[p].first=min(V[p].first, V[p].second[i]-i);
        }
    }
    void insert(int x) {
        sz++;
        if (V.size()==0) {
            V.push_back({}), V[0].second.push_back(x); update(0);
            return;
        }
        if (x<V[0].second[0]) {
            V[0].second.insert(V[0].second.begin(), x); update(0);
            return;
        }
        for (int i=V.size()-1; i>=0; i--) if (V[i].second[0]<=x) {
            if (V[i].second.back()<x) {V[i].second.push_back(x); update(i); break;}
            for (int j=0; j<V[i].second.size(); j++) if (V[i].second[j]>=x) {
                V[i].second.insert(V[i].second.begin()+j, x); update(i); i=-1; break;
            }
        }
    }
    void erase(int x) {
        sz--;
        for (int i=V.size()-1; i>=0; i--) if (V[i].second[0]<=x) {
            for (int j=0; j<V[i].second.size(); j++) if (V[i].second[j]==x) {
                V[i].second.erase(V[i].second.begin()+j);
                if (V[i].second.size()==0) V.erase(V.begin()+i);
                else update(i); return;
            }
        }
    }
    int back() {
        return V.back().second.back();
    }

    int get() {
        int ret=inf, S=0;
        for (pair<int, vector<int>>& i : V) {
            ret=min(ret, i.first-S);
            S+=i.second.size();
        }
        return ret;
    }
} DP[202020];

void dfs(int p) {
    for (array<int, 2> i : {C[p][0], C[p][1]}) if (i[0]>=0) {
        dfs(i[0]); dep[p]=min(dep[p], dep[i[0]]-i[1]);
        if (DP[p].sz<DP[i[0]].sz) swap(DP[p], DP[i[0]]);
        while (DP[i[0]].V.size()) {
            int x=DP[i[0]].back();
            DP[p].insert(x); DP[i[0]].erase(x);
        }
    }

    dep[p]=min(dep[p], DP[p].get()-2);
    for (array<int, 2> i : {C[p][0], C[p][1]}) if (i[0]>=0) DP[p].insert(dep[p]+1);

    if (C[p][0][0] && C[p][0][1]) DP[p].erase(dep[p]+1);
}

int compute_min_depth(signed n, vector<signed> P, vector<signed> c, vector<signed> d) {
    N=n;
    for (int i=0; i<N; i++) C[i][0]=C[i][1]={-1, -1};
    for (int i=0; i<N-1; i++) C[P[i]][d[i]]={i+1, c[i]};
    dfs(0);

    return R?-dep[0]:-1;
}
