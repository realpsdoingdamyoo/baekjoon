//code by p1ckle/sft/yukicoder
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#define int long long int
#define F first
#define X first
#define S second
#define Y second
#define mid ((start+end)/2)
#define all(x) x.begin(), x.end()
#define ub(a, b) upper_bound(all(a), b) - a.begin()
#define lb(a, b) lower_bound(all(a), b) - a.begin()
#define forf(a, b, c) for (int a = b; a <= c; a++)
#define ford(a, b, c) for (int a = b; a < c; a++)
#define forp(a, b) for (auto a : b)
#define pb push_back
#define endl '\n'

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef long double ld;

const int inf = 3e18, mod = 1e9+7, mx = 1e12;
vpii dr4 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, dr8 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

struct line {

    int a, b;
    int f(int x) {return a*x+b;}

};

struct node {

    int l, r;
    int s, e;
    line fx;

};

vector<node> lichao;

void init(int s = -mx, int e = mx) {lichao.pb({-1, -1, s, e, {0, -inf}});}

void updt(int idx, line val) {

    int start = lichao[idx].s, end = lichao[idx].e;
    line lo = lichao[idx].fx, hi = val;

    if (lo.f(start) > hi.f(start)) swap(hi, lo);
    if (lo.f(end) <= hi.f(end)) {lichao[idx].fx = hi; return;}

    if (lo.f(mid) > hi.f(mid)) {

        lichao[idx].fx = lo;
        if (lichao[idx].l == -1) {

            lichao[idx].l = lichao.size();
            lichao.pb({-1, -1, start, mid, {0, -inf}});

        }
        updt(lichao[idx].l, hi);

    } else {

        lichao[idx].fx = hi;
        if (lichao[idx].r == -1) {

            lichao[idx].r = lichao.size();
            lichao.pb({-1, -1, mid+1, end, {0, -inf}});

        }
        updt(lichao[idx].r, lo);

    }

}

int query(int idx, int x) {

    if (idx == -1) return -inf;
    int start = lichao[idx].s, end = lichao[idx].e;
    if (x <= mid) return max(lichao[idx].fx.f(x), query(lichao[idx].l, x));
    else return max(lichao[idx].fx.f(x), query(lichao[idx].r, x));

}

int n, w[250003], h[250003], s, v;
vpii vp;

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    forf (i, 1, n) {
        
        cin >> w[i] >> h[i]; 
        if (w[i] < h[i]) swap(w[i], h[i]); //w[i] >= h[j], 눕히면 길이 w[i]
        vp.pb({w[i], -h[i]});
        v += w[i]*h[i];
        s += w[i];
    
    }
    sort(all(vp));
    forf (i, 1, n) {tie(w[i], h[i]) = vp[i-1]; h[i] *= -1;}
    init();
    int ans = 0;
    forf (i, 1, n) {

        ans = max(ans, query(0, -w[i])+w[i]*h[i]);
        updt(0, {w[i], w[i]*h[i]+w[i]*(s-w[i])-v});

    }
    cout << ans;

}
