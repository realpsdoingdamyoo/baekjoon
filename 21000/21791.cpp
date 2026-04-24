#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18, bnd=1e10;

int n, q;
vector<array<int, 5>> vip;
vector<int> x, y;
int N, M;

array<int, 2> vm[6000][6000];
int dp[6000][6000];
int X[6000], Y[6000];

vector<array<int, 3>> query;
int ans[3030303];

bool cmpx(array<int, 3>& a, array<int, 3>& b){return a[0]>b[0];}
bool cmpy(array<int, 3>& a, array<int, 3>& b){return a[1]>b[1];}

struct li_chao{
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
};

signed main(){
    fastio;

    cin >> n >> q;
    for(int i=0; i<n; i++){
        int t, a, b, c; cin >> t >> a >> b >> c;
        int sx=a+t, sy=t-a;
        int ex=b+t+abs(a-b), ey=t+abs(a-b)-b;
        vip.push_back({sx, sy, ex, ey, c/2});
        x.push_back(sx); x.push_back(ex);
        y.push_back(sy); y.push_back(ey);
    }

    x.push_back(inf); y.push_back(inf);
    x.push_back(-inf); y.push_back(-inf);

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    N=x.size(); M=y.size();

    for(array<int, 5> v : vip){
        int sx=lower_bound(x.begin(), x.end(), v[0])-x.begin();
        int sy=lower_bound(y.begin(), y.end(), v[1])-y.begin();
        int ex=lower_bound(x.begin(), x.end(), v[2])-x.begin();
        int ey=lower_bound(y.begin(), y.end(), v[3])-y.begin();

        if(sx==ex) for(int i=sy; i<ey; i++)
            vm[sx][i][1]=max(vm[sx][i][1], v[4]);
        if(sy==ey) for(int i=sx; i<ex; i++)
            vm[i][sy][0]=max(vm[i][sy][0], v[4]);
    }

    for(int i=N-1; i>=0; i--) for(int j=M-1; j>=0; j--){
        if(i!=N-1) dp[i][j]=max(dp[i][j], dp[i+1][j]+vm[i][j][0]*(x[i+1]-x[i]));
        if(j!=M-1) dp[i][j]=max(dp[i][j], dp[i][j+1]+vm[i][j][1]*(y[j+1]-y[j]));
    }

    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        query.push_back({a+b, a-b, i});
    }

    vector<li_chao> lix(M);
    for(int i=0; i<M; i++) lix[i].tree.push_back({-1, -1, -bnd, bnd, {0, -inf}});
    for(int i=0; i<M; i++) X[i]=N;
    sort(query.begin(), query.end(), cmpx);
    for(array<int, 3> i : query){
        int px=lower_bound(x.begin(), x.end(), i[0])-x.begin();
        int py=lower_bound(y.begin(), y.end(), i[1])-y.begin();
        while(X[py]>px){X[py]--; lix[py].update(0, {vm[X[py]][py-1][1], dp[X[py]][py]});}
        ans[i[2]]=max(ans[i[2]], lix[py].query(0, y[py]-i[1]));
    }

    vector<li_chao> liy(N);
    for(int i=0; i<N; i++) liy[i].tree.push_back({-1, -1, -bnd, bnd, {0, -inf}});
    for(int i=0; i<N; i++) Y[i]=M;
    sort(query.begin(), query.end(), cmpy);
    for(array<int, 3> i : query){
        int px=lower_bound(x.begin(), x.end(), i[0])-x.begin();
        int py=lower_bound(y.begin(), y.end(), i[1])-y.begin();
        while(Y[px]>py){Y[px]--; liy[px].update(0, {vm[px-1][Y[px]][0], dp[px][Y[px]]});}
        ans[i[2]]=max(ans[i[2]], liy[px].query(0, x[px]-i[0]));
    }

    for(int i=0; i<q; i++) cout << ans[i] << '\n';

    return 0;
}
