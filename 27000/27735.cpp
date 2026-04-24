#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, Q, P;
int S[101010], E[101010], W[101010], U[101010];

const int X=17, M=8;
int F[2<<X];
set<array<int, 2>> st[2<<X], rst[2<<X];

int hm(int s, int e) {
    s+=1<<X; e+=1<<X; int r=0;
    while (s<=e) {
        if (s&1) r+=F[s];
        if (~e&1) r+=F[e];
        ++s>>=1; --e>>=1;
    }
    return r;
}

void add(int s, int e, int x) {
    s+=1<<X; e+=1<<X;
    while (s<=e) {
        if (s&1) st[s].insert({F[s]+(W[x]+M-1)/M, x}), rst[s].insert({x, F[s]+(W[x]+M-1)/M});
        if (~e&1) st[e].insert({F[e]+(W[x]+M-1)/M, x}), rst[e].insert({x, F[e]+(W[x]+M-1)/M});
        ++s>>=1; --e>>=1;
    }
}

vector<int> out, tt;
void sol(int p) {
    int s=S[p]+(1<<X), e=E[p]+(1<<X);
    while (s<=e) {
        if (s&1) {
            array<int, 2> v=*rst[s].lower_bound({p, -inf});
            st[s].erase(st[s].find({v[1], v[0]})); rst[s].erase(rst[s].find(v));
        }
        if (~e&1) {
            array<int, 2> v=*rst[e].lower_bound({p, -inf});
            st[e].erase(st[e].find({v[1], v[0]})); rst[e].erase(rst[e].find(v));
        }
        ++s>>=1; --e>>=1;
    }
    int nw=hm(S[p], E[p]);
    assert((nw-U[p])*M>=W[p]);
    W[p]-=nw-U[p];
    if (W[p]<=0) out.push_back(p);
    else U[p]=nw, tt.push_back(p);
}

void update(int p, int x) {
    p+=1<<X;
    while (p) {
        F[p]+=x;
        while (st[p].size() && F[p]>=(*st[p].begin())[0]) sol((*st[p].begin())[1]);
        p>>=1;
    }
}

signed main() {
    fastio;

    cin >> N >> Q;
    int lst=0;
    while (Q--) {
        int t; cin >> t;
        if (t==1) {
            ++P; cin >> S[P] >> E[P] >> W[P]; S[P]^=lst; E[P]^=lst;
            U[P]=hm(S[P], E[P]); add(S[P], E[P], P);
        }
        else {
            int a, b; cin >> a >> b; a^=lst;
            update(a, b);
            sort(out.begin(), out.end());

            cout << out.size() << " "; lst=out.size();
            for (int i : out) cout << i << " ";
            cout << "\n";

            for (int i : tt) add(S[i], E[i], i);

            out.clear(); tt.clear();
        }
    }

    return 0;
}
