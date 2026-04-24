#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, q;

const int X=18;

int D[202020];
int dif[1<<X+1];
void update1(int p, int x) {
    p+=1<<X; dif[p]=x; p>>=1;
    while (p) dif[p]=dif[p<<1]+dif[p<<1|1], p>>=1;
}
int sum(int s, int e) {
    s+=1<<X; e+=1<<X; int r=0;
    while (s<=e) {
        if (s&1) r+=dif[s]; ++s>>=1;
        if (~e&1) r+=dif[e]; --e>>=1;
    } return r;
}

int seg[1<<X+1], lzy[1<<X+1];
void prop(int p) {
    lzy[p<<1]+=lzy[p]; lzy[p<<1|1]+=lzy[p];
    seg[p]+=lzy[p]; lzy[p]=0;
}
void segup(int p){seg[p]=max(seg[p<<1]+lzy[p<<1], seg[p<<1|1]+lzy[p<<1|1]);}
void update2(int s, int e, int x) {
    int S=s+=1<<X, E=e+=1<<X;
    for (int i=X; i>=1; i--) prop(S>>i), prop(E>>i);
    while (s<=e) {
        if (s&1) lzy[s]+=x; ++s>>=1;
        if (~e&1) lzy[e]+=x; --e>>=1;
    }
    for (int i=1; i<=X; i++) segup(S>>i), segup(E>>i);
}
int Max(int s, int e) {
    int r=-inf;
    s+=1<<X; e+=1<<X;
    for (int i=X; i>=1; i--) prop(s>>i), prop(e>>i);
    while (s<=e) {
        if (s&1) r=max(r, seg[s]+lzy[s]); ++s>>=1;
        if (~e&1) r=max(r, seg[e]+lzy[e]); --e>>=1;
    }
    return r;
}

int v[1<<X+1];
void update3(int s, int e, int x) {
    s+=1<<X; e+=1<<X;
    while (s<=e) {
        if (s&1) v[s]+=x; ++s>>=1;
        if (~e&1) v[e]+=x; --e>>=1;
    }
}
int val(int p) {
    int r=0; p+=1<<X;
    while (p) r+=v[p], p>>=1;
    return r;
}

signed main() {
    fastio;

    cin >> n >> q;
    for (int i=1; i<=q; i++) {
        int a; cin >> a;
        if (a==1) {
            int b, c, d; cin >> b >> c >> d;
            D[b]+=d; D[c+1]-=d;
            update1(b, max(0LL, D[b])); update1(c+1, max(0LL, D[c+1]));
            update2(b-1, c+1, -d); update2(b, b, d); update2(c, c, d);
            update3(b, c, d);
        }
        else {
            int b, c; cin >> b >> c;
            if (b==c && val(b)==0) cout << "0\n";
            else if (b<c && val(b)<=val(b+1) && val(c-1)>=val(c) && Max(b+1, c-1)<=0) cout << val(b)+sum(b+1, c) << "\n";
            else cout << "-1\n";
        }
    }

    return 0;
}
