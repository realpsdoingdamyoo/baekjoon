#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

struct Line{
    int a, b;
    int get(int x){return a*x+b;}
};

struct node{
    int l, r;
    int s, e;
    Line line;
};

vector<node> tree;

void update(int nd, Line v){
    int s=tree[nd].s, e=tree[nd].e, m=s+e>>1;
    Line lo=tree[nd].line, hi=v;
    if(lo.get(s)>hi.get(s)) swap(lo, hi);

    if(lo.get(e)<=hi.get(e)){
        tree[nd].line=hi;
        return;
    }

    if(lo.get(m)<hi.get(m)){
        tree[nd].line=hi;
        if(tree[nd].r==-1){
            tree[nd].r=tree.size();
            tree.push_back({-1, -1, m+1, e, {0, -inf}});
        }
        update(tree[nd].r, lo);
    }
    else{
        tree[nd].line=lo;
        if(tree[nd].l==-1){
            tree[nd].l=tree.size();
            tree.push_back({-1, -1, s, m, {0, -inf}});
        }
        update(tree[nd].l, hi);
    }
}

int query(int nd, int x){
    if(nd==-1) return -inf;
    int s=tree[nd].s, e=tree[nd].e, m=s+e>>1;
    if(x<=m) return max(tree[nd].line.get(x), query(tree[nd].l, x));
    else return max(tree[nd].line.get(x), query(tree[nd].r, x));
}

signed main(){
    fastio;
    int bnd=2e12;
    tree.push_back({-1, -1, -bnd, bnd, {0, -inf}});

    int n; cin >> n;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(a==1){
            int b, c; cin >> b >> c;
            update(0, {b, c});
        }
        else{
            int b; cin >> b;
            cout << query(0, b) << "\n";
        }
    }

    return 0;
}
