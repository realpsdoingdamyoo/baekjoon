#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

struct line {int a, b; int get(int x) {return a+b*x;}};
struct Node {line ln; int l, r;} tmp={{0, 0}, -1, -1};
struct lichao {
    vector<Node> seg={tmp};
    int get(int& p){if (p==-1) p=seg.size(), seg.push_back(tmp); return p;}
    void update(int p, int s, int e, line ln) {
        int m=s+e>>1;
        if (ln.get(s)>seg[p].ln.get(s)) swap(ln, seg[p].ln);
        if (ln.get(e)<=seg[p].ln.get(e)) return;

        if (ln.get(m)>seg[p].ln.get(m)) swap(ln, seg[p].ln), update(get(seg[p].l), s, m, ln);
        else update(get(seg[p].r), m+1, e, ln);
    }
    int getv(int p, int s, int e, int x) {
        if (p==-1) return -inf; int m=s+e>>1;
        if (x<=m) return max(seg[p].ln.get(x), getv(seg[p].l, s, m, x));
        return max(seg[p].ln.get(x), getv(seg[p].r, m+1, e, x));
    }

    void push(int a, int b) {update(0, -1e13, 1e13, {a, b});}
    int qry(int x){return getv(0, -1e13, 1e13, x);}
} lct;

int N, S, U, R;

signed main() {
    fastio;

    lct.seg.reserve(10101010);
    cin >> N;
    for (int i=1, A; i<=N; i++) {
        cin >> A; S+=A, U+=A*i;
        lct.push(i*S-U, -i);
        R=max(R, U+lct.qry(S));
    }
    cout << R;

    return 0;
}
