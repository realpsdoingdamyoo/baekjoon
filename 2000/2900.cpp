#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int n, k;
int v[1010101], u[1010101];

signed main(){
    fastio;

    cin >> n >> k;
    while(k--){int a; cin >> a; v[a]++;}
    for(int i=1; i<1010101; i++) for(int j=0; j<1010101; j+=i) u[j]+=v[i];
    for(int i=1; i<1010101; i++) u[i]+=u[i-1];
    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        cout << u[b]-(a?u[a-1]:0) << "\n";
    }

	return 0;
}
