#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

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

array<int, 2> x[606060];
vector<array<int, 4>> q;
vector<int> ans;

void update(int nd, Line v){
    int s=tree[nd].s, e=tree[nd].e, m=s+e>>1;
    Line lo=tree[nd].line, hi=v;
    if(lo.get(s)<hi.get(s)) swap(lo, hi);

    if(lo.get(e)>=hi.get(e)){
        tree[nd].line=hi;
        return;
    }

    if(lo.get(m)>hi.get(m)){
        tree[nd].line=hi;
        if(tree[nd].r==-1){
            tree[nd].r=tree.size();
            tree.push_back({-1, -1, m+1, e, {0, inf}});
        }
        update(tree[nd].r, lo);
    }
    else{
        tree[nd].line=lo;
        if(tree[nd].l==-1){
            tree[nd].l=tree.size();
            tree.push_back({-1, -1, s, m, {0, inf}});
        }
        update(tree[nd].l, hi);
    }
}

int query(int nd, int x){
    if(nd==-1) return inf;
    int s=tree[nd].s, e=tree[nd].e, m=s+e>>1;
    if(x<=m) return min(tree[nd].line.get(x), query(tree[nd].l, x));
    else return min(tree[nd].line.get(x), query(tree[nd].r, x));
}

int n;
int d[101010];
int a[101010];
int b[101010];
int dp[101010];

signed main(){
    fastio;

    cin >> n;
    for(int i=2; i<=n; i++){cin >> d[i]; d[i]+=d[i-1];}
    for(int i=1; i<n; i++) cin >> a[i] >> b[i];

    tree.push_back({-1, -1, (int)-1e9, (int)1e9, {0, inf}});
    update(0, {b[1], a[1]});

    for(int i=2; i<=n; i++){
        dp[i]=query(0, d[i]);
        update(0, {b[i], dp[i]-b[i]*d[i]+a[i]});
    }
    cout << dp[n];

    return 0;
}
