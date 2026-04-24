#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int N;
array<int, 3> R={0, 0, 0};
vector<int> T[2][101010];

int sz[101010], CO[101010];
void szm(int p, int x) {
    sz[p]=1;
    for (int i : T[0][p]) if (i!=x && !CO[i])  szm(i, p), sz[p]+=sz[i];
}

int gc(int p, int x, int s) {
    for (int i : T[0][p]) if (i!=x && !CO[i] && sz[i]>s) return gc(i, p, s);
    return p;
}

array<int, 2> dfs(int p, int x) {
    map<int, int> mp; array<int, 2> ret={0, p};
    for (int i : T[0][p]) if (i!=x && !CO[i]) mp[i]++;
    for (int i : T[1][p]) if (i!=x && !CO[i]) mp[i]++;
    for (pair<int, int> i : mp) if (i.second==2) ret=max(ret, dfs(i.first, p));
    ret[0]++; return ret;
}

void dcp(int p) {
    szm(p, 0); int c=gc(p, 0, sz[p]/2);
    map<int, int> mp;
    for (int i : T[0][c]) if (!CO[i]) mp[i]++;
    for (int i : T[1][c]) if (!CO[i]) mp[i]++;
    array<array<int, 2>, 3> dis={array<int, 2>{0, 0}, {0, 0}, {0, c}};
    for (pair<int, int> i : mp) if (i.second==2) {
        dis[0]=dfs(i.first, c);
        sort(dis.begin(), dis.end());
    }
    R=max(R, {dis[1][0]+dis[2][0], dis[1][1], dis[2][1]});

    CO[c]=1;
    for (int i : T[0][c]) if (!CO[i]) dcp(i);
}

signed main() {
    fastio;

    cin >> N;
    for (int j=0; j<=1; j++) for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        T[j][a].push_back(b); T[j][b].push_back(a);
    }

    dcp(1);

    if (R[0]==0) cout << "-1\n";
    else cout << R[1] << " " << R[2] << "\n";


    return 0;
}
