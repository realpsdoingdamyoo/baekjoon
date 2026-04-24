#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int n, q;
int v[101010], L[101010], R[101010];
vector<array<int, 2>> qryl[101010], recl[101010];
vector<array<int, 2>> qryr[101010], recr[101010];
int ans[101010];

int sp[101010][18];

int Min(int s, int e){
    int w=(int)log2(e-s+1);
    return min(sp[s][w], sp[e-(1<<w)+1][w]);
}


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

void update(int nd, Line v, int l, int r){
    int s=tree[nd].s, e=tree[nd].e, m=s+e>>1;
    if(r<s || e<l) return;
    if(!(l<=s && e<=r)){
        if(tree[nd].l==-1){
            tree[nd].l=tree.size();
            tree.push_back({-1, -1, s, m, {0, -inf}});
        }
        update(tree[nd].l, v, l, r);
        if(tree[nd].r==-1){
            tree[nd].r=tree.size();
            tree.push_back({-1, -1, m+1, e, {0, -inf}});
        }
        update(tree[nd].r, v, l, r);
        return;
    }

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
        update(tree[nd].r, lo, l, r);
    }
    else{
        tree[nd].line=lo;
        if(tree[nd].l==-1){
            tree[nd].l=tree.size();
            tree.push_back({-1, -1, s, m, {0, -inf}});
        }
        update(tree[nd].l, hi, l, r);
    }
}

int query(int nd, int x){
    if(nd==-1) return -inf;
    int s=tree[nd].s, e=tree[nd].e, m=s+e>>1;
    if(x<=m) return max(tree[nd].line.get(x), query(tree[nd].l, x));
    else return max(tree[nd].line.get(x), query(tree[nd].r, x));
}


const int X=17;
int seg[1<<X+1];
void Update(int p, int x){
    p+=1<<X;
    while(p) seg[p]=max(seg[p], x), p>>=1;
}
int Query(int s, int e){
    int r=0; s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) r=max(r, seg[s]); ++s>>=1;
        if(~e&1) r=max(r, seg[e]); --e>>=1;
    } return r;
}


signed main(){
    fastio;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];

    for(int i=1; i<=n; i++) sp[i][0]=v[i];
    for(int j=1; j<18; j++) for(int i=1; i<=n-(1<<j-1); i++)
        sp[i][j]=min(sp[i][j-1], sp[i+(1<<j-1)][j-1]);

    for(int i=1; i<=n; i++){
        int Ls=0, Le=i-1, Rs=i+1, Re=n+1;
        while(Ls<Le){
            int Lm=Ls+Le>>1;
            if(Min(Lm+1, Le)<v[i]) Ls=Lm+1;
            else Le=Lm;
        }
        while(Rs<Re){
            int Rm=Rs+Re>>1;
            if(Min(Rs, Rm)<v[i]) Re=Rm;
            else Rs=Rm+1;
        }
        L[i]=Le+1; R[i]=Rs-1;
        recl[L[i]].push_back({R[i], v[i]});
        recr[R[i]].push_back({L[i], v[i]});
    }

    cin >> q;
    for(int i=1; i<=q; i++){
        int a, b; cin >> a >> b;
        qryl[a].push_back({b, i});
        qryr[b].push_back({a, i});
        ans[i]=Min(a, b)*(b-a+1);
    }

    for(int i=1; i<1<<X+1; i++) seg[i]=0;
    tree.clear();
    tree.push_back({-1, -1, 1, n, {0, -inf}});

    for(int i=n; i>=1; i--){
        for(array<int, 2> x : recl[i]){
            Update(x[0], (x[0]-i+1)*x[1]);
            update(0, {x[1], -(i-1)*x[1]}, i, x[0]);
        }
        for(array<int, 2> x : qryl[i]){
            ans[x[1]]=max(ans[x[1]], query(0, x[0]));
            ans[x[1]]=max(ans[x[1]], Query(i, x[0]));
        }
    }

    for(int i=1; i<1<<X+1; i++) seg[i]=0;
    tree.clear();
    tree.push_back({-1, -1, 1, n, {0, -inf}});

    for(int i=1; i<=n; i++){
        for(array<int, 2> x : recr[i]){
            Update(x[0], (i-x[0]+1)*x[1]);
            update(0, {-x[1], (i+1)*x[1]}, x[0], i);
        }
        for(array<int, 2> x : qryr[i]){
            ans[x[1]]=max(ans[x[1]], query(0, x[0]));
            ans[x[1]]=max(ans[x[1]], Query(x[0], i));
        }
    }

    for(int i=1; i<=q; i++) cout << ans[i] << "\n";

    return 0;
}
