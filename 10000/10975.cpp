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

    int n; cin >> n;
    vi v(n), vv(n); vcin;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i]>v[j]) vv[i]++;
        }
    }
    v=vv;

    vi vsd(n);
    int c=0;
    for(int i=0; i<n; i++){
        if(!((v[i]>0 && vsd[v[i]-1]) || (v[i]<n-1 && vsd[v[i]+1]))) c++;
        vsd[v[i]]=1;
    }
    cout << c;
    return 0;
}
