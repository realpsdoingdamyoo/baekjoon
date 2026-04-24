#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int n, q;
int hei[101010], ans[101010];
vector<array<int, 2>> h;
vector<array<int, 4>> qr;

const int X=18;
array<int, 4> seg[1<<X+1];

array<int, 4> mrg(array<int, 4> a, array<int, 4> b){
    array<int, 4> ret;
    ret[0]=max(a[0], a[3]+b[0]);
    ret[1]=max(b[1], b[3]+a[1]);
    ret[2]=max(max(a[2], b[2]), a[1]+b[0]);
    ret[3]=a[3]+b[3];
    return ret;
}

void update(int p, int x){
    p+=1<<X; seg[p]={max(x, 0LL), max(x, 0LL), max(x, 0LL), x}; p>>=1;
    while(p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
}

int query(int s, int e){
    array<int, 4> ret={0, 0, 0, 0};
    vector<int> S, E;
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) S.push_back(s);
        if(~e&1) E.push_back(e);
        ++s>>=1; --e>>=1;
    }

    for(int i=(int)S.size()-1; i>=0; i--) ret=mrg(seg[S[i]], ret);
    for(int i=(int)E.size()-1; i>=0; i--) ret=mrg(ret, seg[E[i]]);

    return ret[2];
}

void solve(int s, int e, vector<array<int, 4>> Q){
    if(s==e){
        for(array<int, 4> i : Q) ans[i[3]]=h[e][0];
        return;
    }

    int m=s+e>>1;
    for(int i=s; i<=m; i++) update(h[i][1], 1);
    vector<array<int, 4>> Qsm, Qme;
    for(array<int, 4> i : Q){
        if(query(i[0], i[1])>=i[2]) Qsm.push_back(i);
        else Qme.push_back(i);
    }
    solve(m+1, e, Qme);
    for(int i=s; i<=m; i++) update(h[i][1], -inf);
    solve(s, m, Qsm);
}

signed main(){
    fastio;

    cin >> n;
    for(int i=0; i<n; i++) cin >> hei[i];
    for(int i=0; i<n; i++) h.push_back({hei[i], i});
    sort(h.begin(), h.end()); reverse(h.begin(), h.end());

    for(int i=0; i<n; i++) update(i, -inf);

    cin >> q;
    for(int i=0; i<q; i++){
        int a, b, c; cin >> a >> b >> c;
        qr.push_back({a-1, b-1, c, i});
    }

    solve(0, n-1, qr);

    for(int i=0; i<q; i++) cout << ans[i] << "\n";

    return 0;
}
