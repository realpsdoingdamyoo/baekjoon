#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

const int X=19, M=100003;
struct pol {
    int sp[101010][20];
    void init(int x) {
        for (int i=0; i<M; i++) {
            if (x==0) sp[i][0]=(2*i*i-1)%M;
            if (x==1) sp[i][0]=(4*i*i*i-3*i)%M;
        }
        for (int j=1; j<20; j++) for (int i=0; i<M; i++)
            sp[i][j]=sp[sp[i][j-1]][j-1];
    }

    int seg[2<<X];
    void update(int s, int e, int x) {
        s+=1<<X; e+=1<<X;
        while (s<=e) {
            if (s&1) seg[s]+=x; ++s>>=1;
            if (~e&1) seg[e]+=x; --e>>=1;
        }
    }
    int val(int p) {
        p+=1<<X; int r=0;
        while (p) r+=seg[p], p>>=1;
        return r;
    }

    int get(int p, int x) {
        int t=val(p);
        for (int i=0; i<20; i++) if (t&1<<i) x=sp[x][i];
        return x;
    }
} P[2];

int N, Q, A[505050];

signed main(){
    fastio;

    cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> A[i];
    P[0].init(0); P[1].init(1);

    for (int i=1; i<=Q; i++) {
        int a; cin >> a;
        if (a==1) {
            int b, c; cin >> b >> c;
            P[0].update(b, c, 1);
        }
        if (a==2) {
            int b, c; cin >> b >> c;
            P[1].update(b, c, 1);
        }
        if (a==3) {
            int x; cin >> x;
            cout << P[1].get(x, P[0].get(x, A[x])) << "\n";
        }
    }

    return 0;
}
