#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int N, Q, MX=200000;
int V[202020];

struct node {
    array<array<int, 3>, 3> X;
    int SZ;
} emp;

void fill(node& p, int x) {
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) p.X[i][j]=x;
}

node mrg(node A, node B) {
    if (A.SZ==0) return B;
    if (B.SZ==0) return A;

    node R=emp; R.SZ=A.SZ+B.SZ; fill(R, -MX);
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) for (int k=0; k<3; k++) R.X[i][j]=max(R.X[i][j], A.X[i][k]+B.X[2-k][j]);
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) R.X[j][i]=max(R.X[j][i], B.X[(A.SZ&1)^(j&1)][i]);
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) R.X[i][j]=max(R.X[i][j], A.X[i][(B.SZ&1)^(j&1)]);
    return R;
}

const int X=18;
node seg[1<<X+1];
int ovp[1<<X+1];

void nupdate(int p) {
    if (ovp[p]) fill(seg[p], -MX);
    else if (p>=(1<<X)) fill(seg[p], -MX), seg[p].X[0][0]=1;
    else seg[p]=mrg(seg[p<<1], seg[p<<1|1]);
}

void update(int s, int e, int x) {
    int S=s+=1<<X, E=e+=1<<X;
    while (s<=e) {
        if (s&1) ovp[s]+=x, nupdate(s); ++s>>=1;
        if (~e&1) ovp[e]+=x, nupdate(e); --e>>=1;
    }
    for (int i=1; i<=X; i++) nupdate(S>>i), nupdate(E>>i);
}

int query(int s, int e) {
    node ret=emp; s+=1<<X; e+=1<<X;
    for(int i=X; i>=0; i--){
        int S=(s-1>>i)+1, E=(e+1>>i)-1;
        if(S>E) continue;
        if(S&1) ret=mrg(seg[S], ret);
        if(~E&1) ret=mrg(ret, seg[E]);
    }
    return ret.X[2][2];
}

signed main(){
    fastio;

    for (int i=0; i<=X; i++) for (int j=(1<<i); j<(1<<i+1); j++) seg[j].SZ=1<<X-i;
    for (int i=(1<<X); i<(1<<X+1); i++) fill(seg[i], -MX), seg[i].X[0][0]=1;
    for (int i=(1<<X)-1; i>=1; i--) seg[i]=mrg(seg[i<<1], seg[i<<1|1]);

    cin >> N >> Q;

    for (int i=0; i<=N; i++) {
        cin >> V[i];
        update(i-V[i]+1, i+V[i], 1);
    }
    cout << (N-max(query(1, N), 0LL)+1)/2 << "\n";

    for (int i=1; i<=Q; i++) {
        int x, y; cin >> x >> y;
        update(x-V[x]+1, x+V[x], -1); V[x]=y;
        update(x-V[x]+1, x+V[x], 1);
        cout << (N-max(query(1, N), 0LL)+1)/2 << "\n";
    }
}
