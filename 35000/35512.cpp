#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int L, N;
char C[30303][110], R[110], RR[110];
int cc[202];

int M, P[30303];
vector<array<int, 3>> g[30303];

signed main() {
    fastio;

    cin >> N >> L;
    for (int i=1; i<=L; i++) for (int j=1; j<=N; j++) cin >> C[i][j];

    M=L;
    for (int l=1, r=N; l<=r; l++, r--) {
        for (int i='A'; i<='z'; i++) cc[i]=0;

        int cnt=0;
        for (int i=1; i<=L; i++) {
            if (C[i][l]!='.') cnt+=1-cc[C[i][l]], cc[C[i][l]]=1;
            if (C[i][r]!='.') cnt+=1-cc[C[i][r]], cc[C[i][r]]=1;
        }

        if (cnt>=3 || (l==r && cnt>=2)) {cout << "IMPOSSIBLE"; return 0;}
        if (cnt<=1 || l==r) continue;

        char x='.', y='.';
        for (int i='A'; i<='z'; i++) if (cc[i]!=0) {
            (x=='.'?x:y)=i;
        }

        ++M;
        for (int i=1; i<=L; i++) {
            if (C[i][l]==x || C[i][r]==y) {
                g[i].push_back({0, M, 0}), g[i].push_back({1, M, 1});
                g[M].push_back({0, i, 0}), g[M].push_back({1, i, 1});
            }
            if (C[i][l]==y || C[i][r]==x) {
                g[i].push_back({0, M, 1}), g[i].push_back({1, M, 0});
                g[M].push_back({0, i, 1}), g[M].push_back({1, i, 0});
            }
        }
    }

    for (int i=1; i<=L; i++) {
        if ('A'<=C[i][1] && C[i][1]<='Z') g[0].push_back({0, i, 1});
        if ('A'<=C[i][N] && C[i][N]<='Z') g[0].push_back({0, i, 0});
        if ('a'<=C[i][1] && C[i][1]<='z') g[0].push_back({0, i, 0});
        if ('a'<=C[i][N] && C[i][N]<='z') g[0].push_back({0, i, 1});
    }

    for (int i=1; i<=M; i++) P[i]=-1;

    vector<int> st={0};
    set<int> mp;
    for (int i=0; i<=M; i++) mp.insert(i);

    while (st.size()) {
        int p=st.back(); st.pop_back(); mp.erase(mp.find(p));
        for (array<int, 3> i : g[p]) if (i[0]==P[p]) {
            if (P[i[1]]==1-i[2]) {cout << "IMPOSSIBLE"; return 0;}
            if (P[i[1]]==-1) P[i[1]]=i[2], st.push_back(i[1]);
        }
    }

    for (int i=1; i<=L; i++) if (P[i]==0) reverse(C[i]+1, C[i]+N+1);
    for (int p=1; p<=N; p++) {
        int cnt=0; char cr='.';
        for (int i=1; i<=L; i++) if (P[i]!=-1 || p*2==N+1)
            if (C[i][p]!='.') cnt+=(C[i][p]!=cr), cr=C[i][p];

        if (cnt>=2) {cout << "IMPOSSIBLE"; return 0;}
        R[p]=cr;
    }

    while (mp.size()) {
        vector<int> U;

        st.push_back(*mp.begin());
        P[st[0]]=0;
        while (st.size()) {
            int p=st.back(); st.pop_back();
            mp.erase(mp.find(p));
            if (p<=L) U.push_back(p);
            for (array<int, 3> i : g[p]) if (i[0]==P[p]) {
                if (P[i[1]]==1-i[2]) {cout << "IMPOSSIBLE"; return 0;}
                if (P[i[1]]==-1) P[i[1]]=i[2], st.push_back(i[1]);
            }
        }

        for (int i : U) if (P[i]==0) reverse(C[i]+1, C[i]+N+1);
        for (int p=1; p<=N; p++) {
            int cnt=0; char cr='.';
            for (int i : U) if (P[i]!=-1 || p*2==N+1)
                if (C[i][p]!='.') cnt+=(C[i][p]!=cr), cr=C[i][p];
            if (cnt>=2) {cout << "IMPOSSIBLE"; return 0;}
            RR[p]=cr;
        }

        for (int i=1, j=N; i<=j; i++, j--) if (RR[i]==RR[j] && RR[i]!='.')
            R[i]=R[j]=RR[i];

        for (int i : U) P[i]=-1;
    }

    for (int i=1; i<=N; i++) cout << R[i];

    return 0;
}
