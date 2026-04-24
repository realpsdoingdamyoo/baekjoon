#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=3e18;

int N, C;
array<int, 3> V[505050];
set<array<int, 2>> NW[3], MV[3];

int pick(int a, int x) {
    NW[1].erase(NW[1].find({V[x][1], x}));
    NW[2].erase(NW[2].find({V[x][2], x}));
    MV[3-a].insert({V[x][3-a]-V[x][a], x}); C+=V[x][a];
    return V[x][a];
}

int move(int a, int x) {
    MV[a].erase(MV[a].find({V[x][a]-V[x][3-a], x})); C-=V[x][3-a];
    MV[3-a].insert({V[x][3-a]-V[x][a], x}); C+=V[x][a];
    return V[x][a]-V[x][3-a];
}

int del(int a, int x) {
    NW[1].insert({V[x][1], x});
    NW[2].insert({V[x][2], x});
    MV[3-a].erase(MV[3-a].find({V[x][3-a]-V[x][a], x})); C-=V[x][a];
    return -V[x][a];
}

int nwp(int a, int t) {
    int x=(*NW[a].begin())[1];
    int r=pick(a, x); if (t) del(a, x);
    return r;
}

int mov(int a, int t) {
    if (MV[a].size()==0) return inf;
    int x=(*MV[a].begin())[1];
    int r=move(a, x)+nwp(3-a, t); if (t) move(3-a, x);
    return r;
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N*2; i++) {
        cin >> V[i][1] >> V[i][2];
        NW[1].insert({V[i][1], i}); NW[2].insert({V[i][2], i});
    }

    for (int i=1; i<=N; i++) {
        if (nwp(1, 1)<mov(1, 1)) nwp(1, 0); else mov(1, 0);
        if (nwp(2, 1)<mov(2, 1)) nwp(2, 0); else mov(2, 0);
        cout << C << "\n";
    }

    return 0;
}
