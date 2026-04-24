#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, q;
array<int, 2> v[252525];
array<int, 3> qry[252525];
int ans[252525];

bool cmp2(array<int, 2> a, array<int, 2> b){
    return a[0]+a[1]<b[0]+b[1];
}
bool cmp3(array<int, 3> a, array<int, 3> b){
    return a[0]+a[1]<b[0]+b[1];
}

const int X=20;
array<int, 2> seg[2][1<<X+1];

void update(int t, int p, int x){
    seg[t][p+(1<<X)][0]+=x; seg[t][p+(1<<X)][1]+=x*p;
    p=p+(1<<X)>>1;
    while(p){
        seg[t][p][0]=seg[t][p<<1][0]+seg[t][p<<1|1][0];
        seg[t][p][1]=seg[t][p<<1][1]+seg[t][p<<1|1][1];
        p>>=1;
    }
}

int sum(int t, int s, int e, int x){
    array<int, 2> ret={0, 0};
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) ret[0]+=seg[t][s][0], ret[1]+=seg[t][s][1]; ++s>>=1;
        if(~e&1) ret[0]+=seg[t][e][0], ret[1]+=seg[t][e][1]; --e>>=1;
    }
    return abs(ret[1]-ret[0]*x);
}

signed main(){
    fastio;

    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
    for(int i=1; i<=q; i++){cin >> qry[i][0] >> qry[i][1]; qry[i][2]=i;}
    sort(v+1, v+n+1, cmp2); sort(qry+1, qry+q+1, cmp3);

    for(int i=1; i<=n; i++) update(1, v[i][0], v[i][1]-v[i][0]);

    int p=1;
    for(int i=1; i<=q; i++){
        while(p<=n && v[p][0]+v[p][1]<qry[i][0]+qry[i][1]){
            update(0, v[p][1], v[p][1]-v[p][0]); update(1, v[p][0], -v[p][1]+v[p][0]); p++;
        }
        ans[qry[i][2]]+=sum(0, qry[i][0], (1<<X)-1, qry[i][0])*2;
        ans[qry[i][2]]+=sum(1, 1, qry[i][1], qry[i][1])*2;
    }

    for(int i=1; i<=q; i++) cout << ans[i] << "\n";

	return 0;
}
