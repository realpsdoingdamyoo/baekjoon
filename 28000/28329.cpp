#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Q;
string S;

const int X=17, Y=26;
struct node{int F[Y+1], B[Y+1], L;} seg[1<<X+1];

node mrg(node a, node b) {
    node ret;

    int S[Y+2], F[Y+2], B[Y+2]; F[0]=B[Y+1]=inf;
    for (int i=1; i<=Y; i++) F[i]=min(F[i-1], a.F[i]+b.B[i]);
    for (int i=Y; i>=1; i--) B[i]=min(B[i+1], a.F[i]+b.B[i]);

    for (int k=1; k<=Y; k++) ret.F[k]=b.F[k]-b.L+F[k];
    for (int k=1; k<=Y; k++) ret.B[k]=a.B[k]-a.L+B[k];
    ret.L=ret.F[Y];

    return ret;
}

void update(int p, int x) {
    p+=1<<X;
    for (int i=1; i<=Y; i++) seg[p].F[i]=max(x-i, 0LL);
    for (int i=1; i<=Y; i++) seg[p].B[i]=max(i-x, 0LL);
    seg[p].L=0; p>>=1;

    while (p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
}


signed main() {
    fastio;

    cin >> S; N=S.length(); S=" "+S;
    cin >> Q;

    for (int i=1; i<=N; i++) update(i, S[i]-'a'+1);

    cout << seg[1].L << "\n";

    for (int i=1; i<=Q; i++) {
        int a; char c; cin >> a >> c;
        update(a, c-'a'+1);
        cout << seg[1].L << "\n";
    }

    return 0;
}
