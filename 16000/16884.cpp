#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7;
const int MOD=998244353;

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << (n%2?"koosaga\n":"cubelover\n");
    }
    return 0;
}
