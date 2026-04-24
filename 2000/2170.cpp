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
    for(int i=0; i<2*n; i++){
        int k; cin >> k;
        v.push_back({k, 1-2*(i%2)});
    }
    sort(v.begin(), v.end());
    int len=0, st=v[0][0], op=0;
    for(int i=0; i<2*n; i++){
        op+=v[i][1];
        if(op==0){
            len+=v[i][0]-st;
        }
        if(op==1 && v[i][1]==1){
            st=v[i][0];
        }
    }
    cout << len;
    return 0;
}
