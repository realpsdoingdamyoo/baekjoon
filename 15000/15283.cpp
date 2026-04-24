#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

int N, C;
vector<int> co;
array<int, 3> qry[202020];

const int X=18;
int seg[1<<X+1];

void update(int p, int x) {
    p+=1LL<<X; seg[p]=x; p>>=1;
    while (p) seg[p]=max(seg[p<<1], seg[p<<1|1]), p>>=1;
}

int Max(int s, int e) {
    s+=1LL<<X; e+=1LL<<X; int r=0;
    while (s<=e) {
        if (s&1) r=max(r, seg[s]); ++s>>=1;
        if (~e&1) r=max(r, seg[e]); --e>>=1;
    }
    return r;
}

unordered_map<int, int> ht, nb;

signed main(){
    fastio;

    cin >> N;

    for (int i=1; i<=N; i++) {
        int t, x, y; cin >> t >> x >> y;
        co.push_back(x); qry[i]={t, x, y};
    }

    sort(co.begin(), co.end());
    co.erase(unique(co.begin(), co.end()), co.end());

    for (int i=1; i<=N; i++) {
        int t=qry[i][0], x=qry[i][1], y=qry[i][2];
        x=lower_bound(co.begin(), co.end(), x)-co.begin();
        if (t==1) {ht[co[x]]=y; update(x, 2*y); nb[co[x]]=i; continue;}

        int ls=0, le=x;
        if (Max(ls, x)>=y) {
            while (ls<=le) {
                int lm=(ls+le)/2;
                if (Max(lm, x)>=y) ls=lm+1; else le=lm-1;
            }
            int p=co[le];
            if ((p-co[x])*(p-co[x])+(ht[p]-y)*(ht[p]-y)<ht[p]*ht[p]) {
                ht[p]=0; update(le, 0); cout << nb[p] << "\n";
                continue;
            }
        }
        int rs=x, re=co.size()-1;
        if (Max(x, re)>=y) {
            while (rs<=re) {
                int rm=(rs+re)/2;
                if (Max(x, rm)>=y) re=rm-1; else rs=rm+1;
            }
            int p=co[rs];
            if ((p-co[x])*(p-co[x])+(ht[p]-y)*(ht[p]-y)<ht[p]*ht[p]) {
                ht[p]=0; update(rs, 0); cout << nb[p] << "\n";
                continue;
            }
        }
        cout << "-1\n";
    }

    return 0;
}
