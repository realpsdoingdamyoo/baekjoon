#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m;
vector<array<int, 3>> ed;
vector<int> dist;

signed main() {
    fastio;

    cin >> n >> m;
    ed.resize(m); dist.resize(n);
    for(array<int, 3>& i : ed){
        cin >> i[0] >> i[1] >> i[2];
        i[0]--; i[1]--;
    }

    for(int i=1; i<n; i++) dist[i]=inf;

    for(int t=0; t<n-1; t++)
        for(array<int, 3> i : ed)
            if(dist[i[0]]!=inf && dist[i[0]]+i[2]<dist[i[1]])
                dist[i[1]]=dist[i[0]]+i[2];

    for(array<int, 3> i : ed){
        if(dist[i[0]]!=inf && dist[i[0]]+i[2]<dist[i[1]]){
            cout << "-1\n";
            return 0;
        }
    }

    for(int i=1; i<n; i++) cout << (dist[i]==inf?-1:dist[i]) << "\n";

    return 0;
}
