#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int L, N;
array<int, 3> V[101010];
int C[101010], R[101010], RR[101010];
vector<array<int, 2>> st;
vector<int> ct[101010];

const int X=18;
namespace S1 {
    int seg[1<<X+1];
    void update(int p, int x) {
        p+=1<<X;
        while (p) seg[p]=max(seg[p], x), p>>=1;
    }
    int Max(int s, int e) {
        s+=1<<X; e+=1<<X; int r=0;
        while (s<=e) {
            if (s&1) r=max(r, seg[s]); ++s>>=1;
            if (~e&1) r=max(r, seg[e]); --e>>=1;
        } return r;
    }
}

struct lzyseg {
    int tt;
    int seg[1<<X+1], lzy[1<<X+1];
    void prop(int p) {
        lzy[p<<1]+=lzy[p]; lzy[p<<1|1]+=lzy[p];
        seg[p]+=lzy[p]; lzy[p]=0;
    }
    void segup(int p) {
        seg[p]=min(seg[p<<1]+lzy[p<<1], seg[p<<1|1]+lzy[p<<1|1]);
    }
    void update(int s, int e, int x) {
        int S=s+=1<<X, E=e+=1<<X;
        for (int i=X; i>=1; i--) prop(S>>i), prop(E>>i);
        while (s<=e) {
            if (s&1) lzy[s]+=x; ++s>>=1;
            if (~e&1) lzy[e]+=x; --e>>=1;
        }
        for (int i=1; i<=X; i++) segup(S>>i), segup(E>>i);
    }

    void Update(int s, int e, int x) {
        if (s<=e) update(s, e, x);
        else update(1, e, x), update(s, L, x);
    }

    int Min(int s, int e) {
        int S=s+=1<<X, E=e+=1<<X, r=inf;
        for (int i=X; i>=1; i--) prop(S>>i), prop(E>>i);
        while (s<=e) {
            if (s&1) r=min(r, seg[s]+lzy[s]); ++s>>=1;
            if (~e&1) r=min(r, seg[e]+lzy[e]); --e>>=1;
        }
        return r;
    }
} T[2];

void evsol() {
    for (int i=0; i<st.size(); i++) {
        int l=V[st[i][1]][0], r=V[st[i][1]][1], id=st[i][1];

        T[i%2].Update(l, r, 1); R[id]=i%2;
        for (int j : ct[id]) {
            int l_=V[j][0], r_=V[j][1], id_=V[j][2];
            T[1-i%2].Update(l_, r_, 1); R[id_]=1-i%2;
        }
    }

    if (T[0].Min(1, L)>=1 && T[1].Min(1, L)>=1) {
        for (int j=1; j<=N; j++) cout << R[j];
        return;
    }
    cout << "impossible";
}

void odsol() {
    for (int i=0; i<st.size(); i++) {
        int l=V[st[i][1]][0], r=V[st[i][1]][1], id=V[st[i][1]][2];
        T[i%2].Update(l, r, 1); R[id]=i%2;
        for (int j : ct[id]) {
            int l_=V[j][0], r_=V[j][1], id_=V[j][2];
            T[1-i%2].Update(l_, r_, 1); R[id_]=1-i%2;
        }
    }
    if (T[0].Min(1, L)>=1 && T[1].Min(1, L)>=1) {
        for (int j=1; j<=N; j++) cout << R[j];
        return;
    }

    for (int i=0; i<st.size(); i++) {
        int l=V[st[i][1]][0], r=V[st[i][1]][1], id=V[st[i][1]][2];
        T[i%2].Update(l, r, -1); T[1-i%2].Update(l, r, 1); R[id]=1-i%2;
        for (int j : ct[id]) {
            int l_=V[j][0], r_=V[j][1], id_=V[j][2];
            T[1-i%2].Update(l_, r_, -1); T[i%2].Update(l_, r_, 1); R[id_]=i%2;
        }

        if (T[0].Min(1, L)>=1 && T[1].Min(1, L)>=1) {
            for (int j=1; j<=N; j++) cout << R[j];
            return;
        }
    }

    cout << "impossible";
}

signed main(){
    fastio;

    T[0].tt=0; T[1].tt=1;

    cin >> L >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1], V[i][2]=i;
    sort(V+1, V+N+1, [&](array<int, 3> a, array<int, 3> b){return (a[1]-a[0]+L)%L>(b[1]-b[0]+L)%L;});
    for (int i=1; i<=N; i++) RR[V[i][2]]=i;
    for (int i=1; i<=N; i++) {
        if (V[i][0]==V[i][1]%L+1) S1::update(1, L*2);
        else if (V[i][0]<=V[i][1]) {
            if (S1::Max(1, V[i][0])>=V[i][1]) C[V[i][2]]=1;
            S1::update(V[i][0], V[i][1]);
        }
        else {
            if (S1::Max(1, V[i][0])>=L+V[i][1]) C[V[i][2]]=1;
            S1::update(V[i][0], L+V[i][1]), S1::update(1, V[i][1]);
        }
        if (!C[V[i][2]]) st.push_back({V[i][0], V[i][2]});
    }
    sort(st.begin(), st.end());
    sort(V+1, V+N+1, [&](array<int, 3> a, array<int, 3> b){return a[2]<b[2];});

    for (int i=1; i<=N; i++) if (C[i]) {
        if (V[i][0]<st[0][0]) ct[st.back()[1]].push_back(i);
        else ct[(*prev(lower_bound(st.begin(), st.end(), array<int, 2>{V[i][0], inf})))[1]].push_back(i);
    }

    if (st.size()%2==0) evsol();
    else odsol();


    return 0;
}
