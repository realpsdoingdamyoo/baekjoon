#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int ans, use[20], v[20];
int a, b, c, d, e, f, g, h;

void Find(int p){
    if(p==14){
        ans++;
        return;
    }

    for(int i=1; i<=13; i++){
        if(use[i]==1) continue;
        use[i]=1; v[p]=i;

        int x=0;
        if(p==4 && v[1]+v[2]+v[3]+v[4]!=a) x=1;
        if(p==8 && v[5]+v[6]+v[7]+v[8]!=b) x=1;
        if(p==11 && v[9]+v[10]+v[11]!=c) x=1;
        if(p==13 && v[12]+v[13]!=d) x=1;
        if(p==12 && v[1]+v[5]+v[9]+v[12]!=e) x=1;
        if(p==13 && v[2]+v[6]+v[10]+v[13]!=f) x=1;
        if(p==11 && v[3]+v[7]+v[11]!=g) x=1;
        if(p==8 && v[4]+v[8]!=h) x=1;

        if(x==0) Find(p+1);

        use[i]=0; v[p]=0;
    }
}

signed main(){
    //fastio;

    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    Find(1);
    cout << ans;

	return 0;
}
