#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main(){
    fastio;

    int n; cin >> n;
    vpii v;
    for(int i=0; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        v.push_back({b, 1});
        v.push_back({c, -1});
    }
    sort(v.begin(), v.end());
    int op=0, mop=0;
    for(int i=0; i<2*n; i++){
        op+=v[i][1];
        mop=max(op, mop);
    }
    cout << mop;
    return 0;
}
