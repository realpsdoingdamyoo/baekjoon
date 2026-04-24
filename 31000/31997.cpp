#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define vcout; for(int i=0; i<n; i++) cout << v[i] << " ";
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main(){
    fastio;
    int n, q, t; cin >> n >> q >> t;
    vpii v(n);
    vi njh(t);
    for(int i=0; i<n; i++) cin >> v[i][0] >> v[i][1];
    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b; a--; b--;
        if(max(v[a][0], v[b][0])>=min(v[a][1], v[b][1])) continue;
        njh[max(v[a][0], v[b][0])]++;
        njh[min(v[a][1], v[b][1])]--;
    }
    cout << njh[0] << "\n";
    for(int i=1; i<t; i++) {njh[i]+=njh[i-1]; cout << njh[i] << "\n";}

    return 0;
}
