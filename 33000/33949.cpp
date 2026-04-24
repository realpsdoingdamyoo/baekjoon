#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Q;

const int X=18;
struct gsg {
    array<int, 4> seg[1<<X+1];

    array<int, 4> mrg(array<int, 4> a, array<int, 4> b) {
        return {a[0]+b[0], max(a[1], a[0]+b[1]), max(a[2]+b[0], b[2]), max(max(a[3], b[3]), a[2]+b[1])};
    }

    void update(int p, int x) {
        p+=1<<X; seg[p][0]+=x;
        seg[p][1]=seg[p][2]=seg[p][3]=max(seg[p][0], 0LL); p>>=1;
        while (p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
    }

    int Max(int s, int e) {
        s+=1<<X; e+=1<<X; array<int, 4> ret={};
        for (int i=X; i>=0; i--) {
            int S=(s-1>>i)+1, E=(e+1>>i)-1;
            if (S>E) continue;
            if (S&1) ret=mrg(seg[S], ret);
            if (~E&1) ret=mrg(ret, seg[E]);
        }
        return ret[3];
    }
} mxs, mns;

int V[303030];
multiset<int> st;

int sum=0;
signed main(){
    fastio;

    cin >> N >> Q;
    for (int i=1; i<=N; i++) st.insert(0);

    for (int i=1; i<=Q; i++) {
        int a; cin >> a;
        if (a==1) {
            int b, c; cin >> b >> c;
            st.erase(st.find(-V[b])); V[b]+=c; st.insert(-V[b]);
            mxs.update(b, c); mns.update(b, -c); sum+=c;
        }
        else {
            int ret=max(mxs.Max(1, N), sum+mns.Max(1, N));
            cout << (ret?ret:-*st.begin()) << "\n";
        }
    }

    return 0;
}
