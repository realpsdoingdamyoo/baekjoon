#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, k;
int v[202020];
int dp[202020], cnt[202020];
map<int, int> mp;
int u[202020];

const int X=18;
array<int, 2> seg[1<<X+1];
int lazy[1<<X+1];

void prop(int p){
    seg[p][0]+=lazy[p];
    lazy[p<<1]+=lazy[p];
    lazy[p<<1|1]+=lazy[p];
    lazy[p]=0;
}

void segup(int p){
    array<int, 2> L=seg[p<<1]; L[0]+=lazy[p<<1];
    array<int, 2> R=seg[p<<1|1]; R[0]+=lazy[p<<1|1];
    seg[p]=max(L, R);
}

void update(int s, int e, int x){
    s+=1<<X; e+=1<<X; int ss=s, ee=e;
    for(int i=X; i>=1; i--) prop(ss>>i), prop(ee>>i);
    while(s<=e){
        if(s&1) lazy[s]+=x;
        if(~e&1) lazy[e]+=x;
        ++s>>=1; --e>>=1;
    }
    for(int i=1; i<=X; i++) segup(ss>>i), segup(ee>>i);
}

array<int, 2> query(int s, int e){
    array<int, 2> ret={0, 0};
    s+=1<<X; e+=1<<X;
    for(int i=X; i>=1; i--) prop(s>>i), prop(e>>i);
    while(s<=e){
        if(s&1) ret=max(ret, {seg[s][0]+lazy[s], seg[s][1]});
        if(~e&1) ret=max(ret, {seg[e][0]+lazy[e], seg[e][1]});
        ++s>>=1; --e>>=1;
    }
    return ret;
}

int alien(int pnt){
    for(int i=1; i<=n; i++) dp[i]=cnt[i]=0;
    for(int i=1; i<=(1<<X+1); i++) seg[i][0]=lazy[i]=seg[i][1]=0;
    for(int i=1; i<(1<<X); i++) seg[i+(1<<X)][1]=i;

    for(int i=1; i<=n; i++){
        int U=u[i];
        update(U, i-1, 1);
        array<int, 2> pr=query(0, i-1);
        dp[i]=pr[0]-pnt; cnt[i]=cnt[pr[1]]+1;
        update(i, i, dp[i]);
    }

    return dp[n]+cnt[n]*pnt;
}

signed main(){
    fastio;

    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> v[i];
    for(int i=1; i<=n; i++){
        u[i]=mp[v[i]]; mp[v[i]]=i;
    }

    int s=0, e=n;
    while(s<=e){
        int m=s+e>>1;
        alien(m);
        if(cnt[n]>k) s=m+1;
        else e=m-1;
    }
    int sr=alien(s); int sc=cnt[n];
    int er=alien(e); int ec=cnt[n];

    if(sc==ec) cout << sr;
    else{
        cout << (sr*(k-ec)+er*(sc-k))/(sc-ec);
    }

    return 0;
}
