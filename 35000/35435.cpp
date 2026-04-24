#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
#define m (s+e>>1)
 
struct Node {
    int PS, PQS, NS, NQS;
    array<int, 2> PM, NM;
} seg[1200000];
Node mrg(Node A, Node B) {
    if (A.PM[0]>B.PM[0]) swap(A.PM, B.PM);
    if (A.NM[0]<B.NM[0]) swap(A.NM, B.NM);
    return {A.PS+B.PS, A.PQS+B.PQS, A.NS+B.NS, A.NQS+B.NQS,
        {A.PM[0], min(A.PM[1], B.PM[0])}, {A.NM[0], max(A.NM[1], B.NM[0])}};
}
 
void update(int p, int s, int e, int x, int y) {
    if (s==e) {
        if (y<0) seg[p]={0, 0, y, y*y, {inf, inf}, {y, -inf}};
        if (y>0) seg[p]={y, y*y, 0, 0, {y, inf}, {-inf, -inf}};
        if (y==0) seg[p]={0, 0, 0, 0, {0, inf}, {0, -inf}};
        return;
    }
    if (x<=m) update(p<<1, s, m, x, y); else update(p<<1|1, m+1, e, x, y);
    seg[p]=mrg(seg[p<<1], seg[p<<1|1]);
}
 
Node query(int p, int s, int e, int l, int r) {
    if (e<l || r<s) return {0, 0, 0, 0, {inf, inf}, {-inf, -inf}};
    if (l<=s && e<=r) return seg[p];
    return mrg(query(p<<1, s, m, l, r), query(p<<1|1, m+1, e, l, r));
}
 
int N, Q;
 
signed main() {
    fastio;
 
    cin >> N;
    for (int i=1; i<=N; i++) {
        int a; cin >> a;
        update(1, 1, N, i, a);
    }
    cin >> Q;
 
    for (int i=1; i<=Q; i++) {
        int t; cin >> t;
        if (t==1) {
            int x, v; cin >> x >> v;
            update(1, 1, N, x, v);
        }
        else {
            int l, r, k; cin >> l >> r >> k;
            Node g=query(1, 1, N, l, r);
 
            if (k==1) {
                int S=g.PS+g.NS, QS=g.PQS+g.NQS;
                cout << (S*S-QS)/2 << "\n";
            }
            if (k==2) {
                if (g.PM[0]==inf) {
                    int S1=g.NS-g.NM[0], QS1=g.NQS-g.NM[0]*g.NM[0];
                    cout << (S1*S1-QS1)/2 << "\n";
                }
                else if (g.NM[0]==-inf) {
                    int S1=g.PS-g.PM[0], QS1=g.PQS-g.PM[0]*g.PM[0];
                    cout << (S1*S1-QS1)/2 << "\n";
                }
                else {
                    cout << (g.PS*g.PS-g.PQS)/2+(g.NS*g.NS-g.NQS)/2 << "\n";
                }
            }
            else if (k==3) {
                if (g.PM[0]==inf || (g.PM[0]==0 && g.PM[1]==inf)) {
                    int S1=g.NS-g.NM[0]-g.NM[1], QS1=g.NQS-g.NM[0]*g.NM[0]-g.NM[1]*g.NM[1];
                    cout << (S1*S1-QS1)/2 << "\n";
                }
                else if (g.NM[0]==-inf || (g.NM[0]==0 && g.NM[1]==-inf)) {
                    int S1=g.PS-g.PM[0]-g.PM[1], QS1=g.PQS-g.PM[0]*g.PM[0]-g.PM[1]*g.PM[1];
                    cout << (S1*S1-QS1)/2 << "\n";
                }
                else {
                    int ans=0;
                    if (g.PM[1]!=inf) {
                        int S1=g.PS-g.PM[0], QS1=g.PQS-g.PM[0]*g.PM[0];
                        ans=max(ans, (S1*S1-QS1)/2 + (g.NS*g.NS-g.NQS)/2);
                    }
                    if (g.NM[1]!=-inf) {
                        int S1=g.NS-g.NM[0], QS1=g.NQS-g.NM[0]*g.NM[0];
                        ans=max(ans, (S1*S1-QS1)/2 + (g.PS*g.PS-g.PQS)/2);
                    }
                    cout << ans << "\n";
                }
            }
        }
    }
 
    return 0;
}
