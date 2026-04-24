#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m, k;
vector<array<int, 2>> v, u;
int r[505050], c[505050];
int dp[505050], cnt[505050];

struct line{
    int a, b, c;
    double s;

    double cross(const line& l) const{
        return (double)(b-l.b)/(l.a-a);
    }

    bool operator <(const line& l) const{
        return s<l.s;
    }
};
vector<line> con;

int alien(int pnt){
    for(int i=1; i<=n; i++) dp[i]=0, cnt[i]=0;
    con.clear(); con.push_back({2-r[1]*2, (r[1]-1)*(r[1]-1), 0, -inf});

    for(int i=1; i<=n; i++){
        line up={0, 0, 0, c[i]};
        line p=*(lower_bound(con.begin(), con.end(), up)-1);
        dp[i]=p.a*c[i]+p.b+c[i]*c[i]+pnt; cnt[i]=cnt[p.c]+1;
        line nw={2-r[i+1]*2, dp[i]+(r[i+1]-1)*(r[i+1]-1)-max(0LL, c[i]-r[i+1]+1)*max(0LL, c[i]-r[i+1]+1), i, 0};
        while(con.size()>=2 && con[con.size()-2].cross(nw)>con[con.size()-1].cross(nw)) con.pop_back();
        nw.s=nw.cross(con.back()); con.push_back(nw);
    }
    return dp[n]-cnt[n]*pnt;
}

int take_photos(signed N, signed M, signed K, vector<signed> R, vector<signed> C){
    n=N; m=M; k=K;
    for(int i=0; i<n; i++) u.push_back({max(R[i], C[i]), min(R[i], C[i])});
    sort(u.begin(), u.end());
    for(array<int, 2> i : u){
        while(v.size() && v.back()[1]>=i[1]) v.pop_back();
        v.push_back(i);
    }
    n=v.size();
    for(int i=1; i<=n; i++) c[i]=v[i-1][0], r[i]=v[i-1][1];

    int s=0, e=m*m;
    while(s<=e){
        int M=s+e>>1;
        alien(M);
        if(cnt[n]<=k) e=M-1;
        else s=M+1;
    }
    int ret=alien(s); int cr=cnt[n];
    int d=alien(s-1); int dr=cnt[n];
    if(cr==dr) return ret;
    ret-=(ret-d)*(k-cr)/(dr-cr);
    return ret;
}
