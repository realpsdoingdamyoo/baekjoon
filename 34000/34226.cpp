#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2")

int N, M, Q;
array<int, 2> edg[101010];
array<int, 3> qry[101010];
long long ans[101010];
const int X=300;

int g[101010];
long long R;
vector<array<int, 2>> vec;
int Find(int x){return g[x]<0?x:Find(g[x]);}
void Union(int a, int b) {
    a=Find(a); b=Find(b);
    if (a==b) {vec.push_back({0, 0}); vec.push_back({0, 0}); return;}
    vec.push_back({a, g[a]}); vec.push_back({b, g[b]}); R+=1LL*g[a]*g[b];
    if (-g[a]<-g[b]) swap(a, b); g[a]+=g[b]; g[b]=a;
}
void Rollback() {
    R-=1LL*vec[vec.size()-2][1]*vec[vec.size()-1][1];
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
}

int LQS(int l, int r) {
    for (int i=l; i<=r; i++) Union(edg[i][0], edg[i][1]);
    int ret=R;
    for (int i=l; i<=r; i++) Rollback();
    return ret;
}

int l=X, lb=X, r=X-1;

long long solve(int s, int e) {
    while (r<e) r++, Union(edg[r][0], edg[r][1]);
    while (s<l) l--, Union(edg[l][0], edg[l][1]);
    long long ret=R;
    while (l<lb) Rollback(), l++;
    return ret;
}

signed main() {
    fastio;

    cin >> N >> M >> Q; int RQ=Q;
    for (int i=1; i<=M; i++) cin >> edg[i][0] >> edg[i][1];
    for (int i=1; i<=Q; i++) {cin >> qry[i][0] >> qry[i][1]; qry[i][2]=i;}
    for (int i=1; i<=N; i++) g[i]=-1;

    for (int i=Q; i>=1; i--) {
        if (qry[i][0]/X==qry[i][1]/X) {
            ans[qry[i][2]]=LQS(qry[i][0], qry[i][1]);
            swap(qry[i], qry[Q]); Q--;
        }
    }
    sort(qry+1, qry+Q+1, [&](array<int, 3> a, array<int, 3> b){return a[0]/X*M+a[1]<b[0]/X*M+b[1];});

    for (int i=1; i<=Q; i++) {
        if (qry[i][0]/X!=qry[i-1][0]/X) {
            for (int j=1; j<=N; j++) g[j]=-1;
            vec.clear(); R=0;
            l=lb=qry[i][0]/X*X+X; r=l-1;
        }
        ans[qry[i][2]]=solve(qry[i][0], qry[i][1]);
    }

    for (int i=1; i<=RQ; i++) cout << ans[i] << "\n";


    return 0;
}
