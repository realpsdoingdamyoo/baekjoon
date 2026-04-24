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

vector<pair<int, node>> up;
vector<vector<pair<int, node>>> st;
array<int, 2> x[606060];
vector<array<int, 4>> q;
vector<int> ans;

void update(int nd, Line v){
    up.push_back({nd, tree[nd]});
    int s=tree[nd].s, e=tree[nd].e, m=s+e>>1;
    Line lo=tree[nd].line, hi=v;
    if(lo.get(s)>hi.get(s)) swap(lo, hi);

    if(lo.get(e)<=hi.get(e)){
        tree[nd].line=hi;
        if(nd==0) st.push_back(up), up.clear();
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

    if(nd==0) st.push_back(up), up.clear();
}

int query(int nd, int x){
    if(nd==-1) return -inf;
    int s=tree[nd].s, e=tree[nd].e, m=s+e>>1;
    if(x<=m) return max(tree[nd].line.get(x), query(tree[nd].l, x));
    else return max(tree[nd].line.get(x), query(tree[nd].r, x));
}

void rollback(){
    for(pair<int, node> i : st.back()){
        tree[i.first]=i.second;
    } st.pop_back();
}

void solve(int s, int e, vector<array<int, 4>> qu){
    if(s==e){
        for(array<int, 4> a : qu) update(0, {a[0], a[1]});
        if(x[s][0]==inf){
            int ret=query(0, x[s][1]);
            if(ret==-inf) cout << "EMPTY\n";
            else cout << ret << "\n";
        }
        for(array<int, 4> a : qu) rollback();
        return;
    }

    int m=s+e>>1; int cnt=0;
    vector<array<int, 4>> L, R;
    for(array<int, 4> a : qu){
        if(a[2]<=s && a[3]>=e) update(0, {a[0], a[1]}), cnt++;
        else{
            if(max(a[2], s)<=min(a[3], m)) L.push_back(a);
            if(max(a[2], m+1)<=min(a[3], e)) R.push_back(a);
        }
    }
    solve(s, m, L); solve(m+1, e, R);
    while(cnt--) rollback();
}


signed main(){
    fastio;
    int bnd=2e9;
    tree.push_back({-1, -1, -bnd, bnd, {0, -inf}});

    map<array<int, 3>, int> mp;
    int n; cin >> n;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(a==1){
            int b, c; cin >> b >> c;
            x[i]={b, c};
            mp[{b, c, i}]=i;
        }
        else if(a==2){
            int b; cin >> b; b--;
            q.push_back({x[b][0], x[b][1], mp[{x[b][0], x[b][1], b}], i});
            mp.erase(mp.find({x[b][0], x[b][1], b}));
            x[i]={0, 0};
        }
        else{
            int b; cin >> b;
            x[i]={inf, b};
        }
    }
    for(pair<array<int, 3>, int> p : mp){
        q.push_back({p.first[0], p.first[1], p.second, n++});
    }
    solve(0, n-1, q);
    return 0;
}
