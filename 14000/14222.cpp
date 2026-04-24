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

    int n, k; cin >> n >> k;
    bool flag=false;
    vi v(n), chk(n+1); vcin;
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        while(v[i]<=n && chk[v[i]]) v[i]+=k;
        if(v[i]>n || chk[v[i]]==1) {cout << "0\n"; return 0;}
        chk[v[i]]=1;

    }
    cout << "1\n";
    return 0;
}
