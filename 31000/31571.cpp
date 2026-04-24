#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, Q, K, M;
vector<array<int, 3>> cp;
vector<int> cmp;

struct tree{
    int seg[3020202], lzy[3020202];

    void _chmax(int& x, int y){x=max(x, y);}
    void update1(int p, int s, int e, int l, int r, int x) { // chmax
        if (r<s || e<l) return;
        if (l<=s && e<=r) seg[p]=max(seg[p], x-lzy[p]);
        else {
            int m=s+e>>1; x-=lzy[p];
            _chmax(seg[p<<1], seg[p]-lzy[p<<1]); _chmax(seg[p<<1|1], seg[p]-lzy[p<<1|1]);
            update1(p<<1, s, m, l, r, x); update1(p<<1|1, m+1, e, l, r, x);
            seg[p]=min(seg[p<<1], seg[p<<1|1]);
        }
    }
    void update2(int p, int s, int e, int l, int r, int x) { // add
        if (r<s || e<l) return;
        if (l<=s && e<=r) lzy[p]+=x;
        else {
            int m=s+e>>1;
            _chmax(seg[p<<1], seg[p]-lzy[p<<1]); _chmax(seg[p<<1|1], seg[p]-lzy[p<<1|1]);
            update2(p<<1, s, m, l, r, x); update2(p<<1|1, m+1, e, l, r, x);
            seg[p]=min(seg[p<<1]+lzy[p<<1], seg[p<<1|1]+lzy[p<<1|1]);
        }
    }
    int val(int p, int s, int e, int x) {
        if (s==e) return seg[p]+lzy[p];
        int m=s+e>>1;
        if (x<=m) return max(seg[p], val(p<<1, s, m, x))+lzy[p];
        return max(seg[p], val(p<<1|1, m+1, e, x))+lzy[p];
    }

    void chmax(int s, int e, int x) {
        if (s>e) chmax(s, M-1, x), chmax(0, e, x);
        else update1(1, 0, M-1, s, e, x);
    }
    void add(int s, int e, int x) {
        if (s>e) add(s, M-1, x), add(0, e, x);
        else update2(1, 0, M-1, s, e, x);
    }
    int get(int x) {
        return val(1, 0, M-1, x);
    }
} T;

int Find(int x) {return lower_bound(cmp.begin(), cmp.end(), x)-cmp.begin();}

int play_game(int n, signed q, int k, vector<int> l, vector<int> r) {
    //fill(T.seg, T.seg+500000, 0); N=Q=K=M=0;
    cp.clear(); cmp.clear();


    N=n; Q=q; K=k;
    map<int, int> mp;
    for (int i=0; i<Q; i++) mp[l[i]]++, mp[r[i]+1]--;
    for (pair<int, int> i : mp) if (i.second) cp.push_back({i.first, -1, i.second});
    for (int i=0; i<cp.size()-1; i++) cp[i][1]=cp[i+1][0]-1, cp[i+1][2]+=cp[i][2]; cp.back()[1]=N-1;

    int p=0;
    for (array<int, 3> i : cp) if (i[0]<N) {
        int d=i[1]-i[0]+1;
        cmp.push_back(p); cmp.push_back((p+d-1)%K); cmp.push_back((p+K-1)%K);
        p=(p+d)%K;
    }
    sort(cmp.begin(), cmp.end()); cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());

    M=cmp.size(); p=0;
    for (array<int, 3> i : cp) if (i[0]<N) {
        int d=i[1]-i[0]+1, a=i[2];
        if (d>=K) T.add(0, M-1, d/K*a), d%=K;
        if (d) {
            T.add(Find(p), Find((p+d-1)%K), a);
            T.chmax(Find(p), Find((p+d-1)%K), T.get(Find((p+K-1)%K)));
            p=(p+d)%K;
        }
    }

    int ret=0;
    for (int i=0; i<M; i++) ret=max(ret, T.get(i));
    return ret;
}
