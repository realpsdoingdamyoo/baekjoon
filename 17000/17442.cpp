#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, Q;
int rX[101010], X[101010], Y[101010];
int U[202020], V[202020];
int A[202020], B[202020];
vector<int> cmp;

vector<int> lnk[101010];
int E[505050];
map<int, int> mp;
int NX[404040], VIS[404040];
array<int, 2> ED[404040];
int IN[202020];

const int XX=20;
int seg[1<<XX+1];
void update(int p, int x) {
    p+=1<<XX;
    while (p) seg[p]+=x, p>>=1;
}
int sum(int s, int e) {
    s+=1<<XX; e+=1<<XX; int r=0;
    while (s<=e) {
        if (s&1) r+=seg[s];
        if (~e&1) r+=seg[e];
        ++s>>=1; --e>>=1;
    } return r;
}

signed main() {
    fastio;

    cin >> N >> M >> Q;
    for (int i=1; i<=N; i++) cin >> rX[i] >> Y[i], cmp.push_back(rX[i]);
    for (int i=1; i<=M; i++) cin >> U[i] >> V[i];
    for (int i=1; i<=Q; i++) cin >> A[i] >> B[i], cmp.push_back(A[i]), cmp.push_back(B[i]);
    sort(cmp.begin(), cmp.end()); cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for (int i=1; i<=N; i++) X[i]=lower_bound(cmp.begin(), cmp.end(), rX[i])-cmp.begin()+1;
    for (int i=1; i<=Q; i++) A[i]=lower_bound(cmp.begin(), cmp.end(), A[i])-cmp.begin()+1;
    for (int i=1; i<=Q; i++) B[i]=lower_bound(cmp.begin(), cmp.end(), B[i])-cmp.begin()+1;

    for (int i=1; i<=M; i++) {
        int a=U[i], b=V[i];
        lnk[a].push_back(b); lnk[b].push_back(a);
        E[min(X[a], X[b])]++, E[max(X[a], X[b])]--;
        mp[a*mod+b]=i*2-1; mp[b*mod+a]=i*2;
        ED[i*2-1]={a, b}; ED[i*2]={b, a};
    }

    for (int i=1; i<=502000; i++) E[i]+=E[i-1];

    for (int i=1; i<=N; i++) {
        sort(lnk[i].begin(), lnk[i].end(), [&](int a, int b) {
            double aa=atan2(Y[a]-Y[i], rX[a]-rX[i]);
            double ba=atan2(Y[b]-Y[i], rX[b]-rX[i]);
            return aa<ba;
        });
        for (int j=0; j<lnk[i].size(); j++) {
            int x=lnk[i][j], y=lnk[i][(j+1)%lnk[i].size()];
            NX[mp[x*mod+i]]=mp[i*mod+y];
        }
    }

    vector<array<int, 3>> swp;
    for (int i=1; i<=Q; i++) swp.push_back({A[i], B[i], i});

    vector<int> fl, fr; int fc=0;
    for (int i=1; i<=M*2; i++) if (!VIS[i]++) {
        int p=NX[i], LX=min(X[ED[i][0]], X[ED[i][1]]), RX=max(X[ED[i][0]], X[ED[i][1]]);
        while (p!=i) {
            VIS[p]=1;
            LX=min(LX, X[ED[p][0]]); RX=max(RX, X[ED[p][0]]);
            LX=min(LX, X[ED[p][1]]); RX=max(RX, X[ED[p][1]]);
            p=NX[p];
        }
        fl.push_back(LX); fr.push_back(RX); fc++;
        swp.push_back({LX, RX, 0});
    }

    sort(fl.begin(), fl.end()); sort(fr.begin(), fr.end());
    for (array<int, 3>& i : swp) if (i[0]==fl.front() && i[1]==fr.back()) {
        swap(i, swp.back()); swp.pop_back(); break;
    }
    fl.erase(fl.begin()); fr.erase(fr.end()-1);
    sort(swp.begin(), swp.end()); reverse(swp.begin(), swp.end());

    for (array<int, 3> i : swp) {
        if (!i[2]) update(i[1], 1);
        else IN[i[2]]=sum(i[0], i[1]);
    }

    for (int i=1; i<=Q; i++) {
        int v=E[A[i]]*2+E[B[i]]*2;
        int e=E[A[i]]+E[B[i]];
        int f=fc-1-IN[i];
        f-=fc-(lower_bound(fl.begin(), fl.end(), B[i])-fl.begin())-1;
        f-=lower_bound(fr.begin(), fr.end(), A[i])-fr.begin();
        //cout << v << " " << e << " " << f << "\n";
        cout << 1+v-e-f << "\n";
    }

    return 0;
}
