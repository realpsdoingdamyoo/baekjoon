#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

struct Node{int l, r, c, s;} node[5050505];
int root[202020], pv;
vector<int> comp;

void update(int p, int n, int l, int r, int x){
    node[p].c=node[n].c+1;
    node[p].s=node[n].s+comp[x];
    if(l==r) return;
    int m=l+r>>1;
    if(x<=m){
        if(node[p].l==0) node[p].l=++pv; node[p].r=node[n].r;
        update(node[p].l, node[n].l, l, m, x);
    }
    else{
        if(node[p].r==0) node[p].r=++pv; node[p].l=node[n].l;
        update(node[p].r, node[n].r, m+1, r, x);
    }
}

int query(int p, int n, int l, int r, int k){
    if(l==r) return comp[l]*k;
    int rc=node[node[p].r].c-node[node[n].r].c;
    int m=l+r>>1;
    if(rc>=k) return query(node[p].r, node[n].r, m+1, r, k);
    else return query(node[p].l, node[n].l, l, m, k-rc)+(node[node[p].r].s-node[node[n].r].s);
}

int n, k;
array<int, 2> v[202020];

int ans=-inf;
void dnc(int s, int e, int l, int r){
    if(s>e) return;
    int m=s+e>>1;
    array<int, 2> ret={-inf, r};
    for(int i=max(l, m+k-1); i<=r; i++){
        int t=query(root[i], root[m-1], 0, comp.size()-1, k);
        ret=max(ret, {t-(v[i][1]-v[m][1]), i});
    }
    ans=max(ans, ret[0]);
    dnc(s, m-1, l, ret[1]);
    dnc(m+1, e, ret[1], r);
}

signed main(){
    fastio;

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> v[i][0] >> v[i][1]; v[i][1]*=2;
        comp.push_back(v[i][0]);
    }
    sort(v+1, v+n+1, [&](array<int, 2> a, array<int, 2> b){return a[1]<b[1];});
    for(int i=0; i<=n; i++) root[i]=++pv;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for(int i=1; i<=n; i++){
        int x=lower_bound(comp.begin(), comp.end(), v[i][0])-comp.begin();
        update(root[i], root[i-1], 0, comp.size()-1, x);
    }

    dnc(1, n, 1, n);
    cout << ans;

    return 0;
}
