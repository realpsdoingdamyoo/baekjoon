#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int N, M;
const int W=100005;
array<int, 2> V[101010];
vector<int> FX[101010], FY[101010];
vector<int> lnk[101010];
bool VIS[101010];

vector<int> P[101010];
int R[101010];

void dfs(int p, int c) {
    VIS[p]=true; R[p]=c; P[c].push_back(p);
    for (int i : lnk[p]) if (!VIS[i]) dfs(i, c);
}

const int X=18;
struct msg {
    set<array<int, 2>> seg[1<<X+1];
    void update(int s, int e, int x, int y) {
        for (s+=1<<X, e+=1<<X; s<=e; ++s>>=1, --e>>=1) {
            if (s&1) seg[s].insert({x, y});
            if (~e&1) seg[e].insert({x, y});
        }
    }
    array<int, 2> qry(int p, int x) {
        array<int, 2> ret={inf, -1};
        for (p+=1<<X; p; p>>=1) {
            set<array<int, 2>>::iterator it=seg[p].lower_bound({x, -1});
            if (it!=seg[p].end()) ret=min(ret, *it);
        }
        return ret;
    }
    void erase(int s, int e, int x, int y) {
        for (s+=1<<X, e+=1<<X; s<=e; ++s>>=1, --e>>=1) {
            if (s&1) seg[s].erase(seg[s].find({x, y}));
            if (~e&1) seg[e].erase(seg[e].find({x, y}));
        }
    }
} XN, YN, XP;

int C[101010];
int MC[101010];
vector<array<int, 4>> st;
vector<array<int, 4>> rc;

void link(int p, int x) {
    for (int i=0; i<P[p].size(); i++) {
        int a=P[p][i], b=P[p][(i+1)%P[p].size()];
        int X1=V[a][0], Y1=V[a][1], X2=V[b][0], Y2=V[b][1];
        if (X1>X2) swap(X1, X2); if (Y1>Y2) swap(Y1, Y2);
        if (X1==X2) YN.erase(Y1, Y2, X1, p);
        if (Y1==Y2) XN.erase(X1, X2, Y1, p);

        if (V[a][x]!=V[b][x]) continue;
        MC[a]=b; MC[b]=a;
        st.push_back({X1, X2, Y1, Y2});
        rc.push_back({X1, X2, Y1, Y2});
    }
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> V[i][0] >> V[i][1];
        FX[V[i][0]].push_back(i);
        FY[V[i][1]].push_back(i);
    }

    for (int i=1; i<=W; i++) {
        if (FX[i].size()==2) lnk[FX[i][0]].push_back(FX[i][1]), lnk[FX[i][1]].push_back(FX[i][0]);
        if (FY[i].size()==2) lnk[FY[i][0]].push_back(FY[i][1]), lnk[FY[i][1]].push_back(FY[i][0]);
    }

    for (int i=1; i<=N; i++) if (!VIS[i] && lnk[i].size()==1) dfs(i, ++M);
    for (int i=1; i<=N; i++) if (!VIS[i]) dfs(i, ++M);

    for (int i=1; i<=M; i++) {
        if (P[i].size()%2==1) {cout << "NE\n"; return 0;}
        if (P[i].size()==2 || (V[P[i][0]][0]!=V[P[i][P[i].size()-1]][0] && V[P[i][0]][1]!=V[P[i][P[i].size()-1]][1])) {
            for (int j : P[i]) C[j]=(V[P[i][0]][0]==V[P[i][1]][0]?1:2);
            for (int j=0; j<P[i].size(); j+=2) {
                int sx=V[P[i][j]][0], ex=V[P[i][j+1]][0]; if (sx>ex) swap(sx, ex);
                int sy=V[P[i][j]][1], ey=V[P[i][j+1]][1]; if (sy>ey) swap(sy, ey);
                st.push_back({sx, ex, sy, ey}); rc.push_back({sx, ex, sy, ey});
                MC[P[i][j]]=P[i][j+1]; MC[P[i][j+1]]=P[i][j];
            }
        }
        else {
            for (int j=0; j<P[i].size(); j++) {
                int sx=V[P[i][j]][0], ex=V[P[i][(j+1)%P[i].size()]][0];
                int sy=V[P[i][j]][1], ey=V[P[i][(j+1)%P[i].size()]][1];
                if (sx==ex) YN.update(min(sy, ey), max(sy, ey), sx, i);
                if (sy==ey) XN.update(min(sx, ex), max(sx, ex), sy, i);
            }
        }
    }

    while (st.size()) {
        array<int, 4> cp=st.back(); st.pop_back();
        if (cp[0]==cp[1]) {
            while (1) {
                array<int, 2> p=XN.qry(cp[0], cp[2]);
                if (p[1]==-1 || p[0]>cp[3]) break;
                link(p[1], 0);
            }
        }
        else {
            while (1) {
                array<int, 2> p=YN.qry(cp[2], cp[0]);
                if (p[1]==-1 || p[0]>cp[1]) break;
                link(p[1], 1);
            }
        }
    }

    for (int i=1; i<=N; i++) if (!MC[i]) {
        for (int j : lnk[i]) if (V[i][0]==V[j][0]) MC[i]=j;
    }

    sort(rc.begin(), rc.end(), [&](array<int, 4> a, array<int, 4> b) {return (a[0]==a[1])<(b[0]==b[1]);});
    for (array<int, 4> i : rc) {
        if (i[0]!=i[1]) XP.update(i[0], i[1], i[2], 0);
        else if (XP.qry(i[0], i[2])[0]<i[3]) {cout << "NE\n"; return 0;}
    }

    cout << "DA\n";
    for (int i=1; i<=N; i++) if (MC[i]>i) cout << i << " " << MC[i] << "\n";

    return 0;
}
