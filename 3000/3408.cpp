#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int X;
vector<int> seg, lazy;

void init(int n){
    X=0; while((1<<X)<n) X++;
    seg=vector<int>(1<<X+1, 0);
    lazy=vector<int>(1<<X+1, 0);
}

void prop(int p){
    lazy[p<<1]+=lazy[p]; lazy[p<<1|1]+=lazy[p];
    seg[p]+=lazy[p]; lazy[p]=0;
}

void segup(int p){
    seg[p]=min(seg[p<<1]+lazy[p<<1], seg[p<<1|1]+lazy[p<<1|1]);
}

void update(int s, int e, int x){
    int ss=s+=1<<X, ee=e+=1<<X;
    for(int i=X; i>=1; i--) prop(ss>>i), prop(ee>>i);
    while(s<=e){
        if(s&1) lazy[s]+=x;
        if(~e&1) lazy[e]+=x;
        ++s>>=1; --e>>=1;
    }
    for(int i=1; i<=X; i++) segup(ss>>i), segup(ee>>i);
}

int mnv(int s, int e){
    int ss=s+=1<<X, ee=e+=1<<X;
    for(int i=X; i>=1; i--) prop(ss>>i), prop(ee>>i);
    int ret=inf;
    while(s<=e){
        if(s&1) ret=min(ret, seg[s]+lazy[s]);
        if(~e&1) ret=min(ret, seg[e]+lazy[e]);
        ++s>>=1; --e>>=1;
    }
    return ret;
}

void solve(){
    int n; cin >> n; init(n);
    vector<int> v(n), u(n);
    map<int, int> mp;
    for(int& i : v) cin >> i;

    for(int i=0; i<n; i++){
        u[i]=mp[v[i]];
        mp[v[i]]=i+1;
    }

    for(int i=0; i<n; i++){
        update(u[i], i, 1);
        if(u[i]!=0){
            int j=u[i]-1;
            update(u[j], j, -1);
        }
        if(mnv(0, i)==0){
            cout << "boring\n";
            return;
        }
    }

    cout << "non-boring\n";

}

signed main(){
    fastio;

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
