#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, A[202020], H[202020], C[202020], G[202020], ans;
vector<int> vec;
map<int, int> mp[202020];

void push(int p, int h, int c) {
    mp[p][0]+=c; mp[p][h]+=c;
    while (c) {
        map<int, int>::iterator it=mp[p].lower_bound(h); it--;
        if (c<it->second) mp[p][it->first]-=c, c=0;
        else c-=it->second, mp[p].erase(it);
    }
}
void mrg(int a, int b) {
    if (mp[a].size()<mp[b].size()) swap(mp[a], mp[b]);
    for (pair<int, int> i : mp[b]) mp[a][i.first]+=i.second;
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i] >> H[i] >> C[i], G[A[i]]++;
    for (int i=1; i<=N; i++) if (G[i]==0) vec.push_back(i);

    while (vec.size()) {
        int p=vec.back(); vec.pop_back();
        push(p, H[p], C[p]); mrg(A[p], p);
        if (!--G[A[p]]) vec.push_back(A[p]);
    }

    for (int i=1; i<=N; i++) if (G[i]) {
        map<int, int> MP; mp[0].clear();
        int p=i;
        while (G[p]) mrg(0, p), G[p]--, ans+=C[p], MP[H[p]]+=C[p], p=A[p];
        int w=mp[0][0], sum=0; mp[0][mod]=-1;
        map<int, int>::iterator it=mp[0].begin();

        for (pair<int, int> pv : MP) {
            while (it->first<pv.first) sum+=it->second, it++;
            w=min(w, sum-pv.second);
        }
        ans+=w;
    }
    cout << ans;

    return 0;
}
