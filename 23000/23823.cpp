#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int w[101010], h[101010];
int wm, wc, hm, hc;

signed main(){
    fastio;

    int n, q; cin >> n >> q;
    wc=n; hc=n;
    for(int i=1; i<=q; i++){
        int a, b; cin >> a >> b;
        if(a==1){
            w[b]++;
            if(w[b]>wm){wm=w[b]; wc=1;}
            else if(w[b]==wm) wc++;
        }
        if(a==2){
            h[b]++;
            if(h[b]>hm){hm=h[b]; hc=1;}
            else if(h[b]==hm) hc++;
        }
        cout << wc*hc << "\n";
    }


	return 0;
}
