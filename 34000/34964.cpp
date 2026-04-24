#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int N, P[1010101];
char C[1010101];
array<int, 2> V[1010101];

bool slv(int l, int r, int s, int e) {
    if (l>r) return true;
    if (P[l]==s) {C[l]='E'; return slv(l+1, r, s+1, e);}
    if (P[l]==e) {C[l]='C'; return slv(l+1, r, s, e-1);}
    if (P[r]==s) {C[r]='Q'; return slv(l, r-1, s+1, e);}
    if (P[r]==e) {C[r]='Z'; return slv(l, r-1, s, e-1);}
    return false;
}

array<int, 2> X[1010101];
int NX[4][1010101], CL[4][1010101];

void chain(int t) {
    vector<array<int, 2>> st;
    for (int i=1; i<=N; i++) {
        while (st.size() && st.back()[0]>X[i][0])
            NX[t][st.back()[1]]=X[i][1], st.pop_back();
        st.push_back(X[i]); CL[t][X[i][1]]=st.size();
    }
}

int LC[1010101], RC[1010101];

bool chain2(int t) {
    int LE=0, LP=0, RE=N+1, RP=0;;

    vector<int> st1, st2;
    for (int i=1; i<=N; i++) {
        while (st1.size() && st1.back()<X[i][0]) st1.pop_back();
        while (st2.size() && st2.back()>X[i][0]) st2.pop_back();
        st1.push_back(X[i][0]); st2.push_back(X[i][0]);
        if (st1.size()+st2.size()==i+1) LE=i, LP=X[i][0];
    }
    st1=st2={};
    for (int i=N; i>LE; i--) {
        while (st1.size() && st1.back()<X[i][0]) st1.pop_back();
        while (st2.size() && st2.back()>X[i][0]) st2.pop_back();
        st1.push_back(X[i][0]); st2.push_back(X[i][0]);
        if (st1.size()+st2.size()==N-i+2) RE=i, RP=X[i][0];
    }

    if (RE==LE+1) {
        for (int i=1; i<=LE; i++) {
            if (X[i][0]<=LP) C[X[i][1]]='E';
            else C[X[i][1]]="CQ"[t];
        }
        for (int i=RE; i<=N; i++) {
            if (X[i][0]<=RP) C[X[i][1]]="QC"[t];
            else C[X[i][1]]='Z';
        }
        cout << "YES\n";
        for (int i=1; i<=N; i++) cout << C[i];
        return true;
    }
    return false;
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> P[i];
    if (slv(1, N, 1, N)) {
        cout << "YES\n";
        for (int i=1; i<=N; i++) cout << C[i];
        return 0;
    }

    for (int t=0; t<=1; t++) {
        for (int i=1; i<=N; i++) for (int j=0; j<4; j++) CL[j][i]=NX[j][i]=0;

        for (int i=1; i<=N; i++) X[i]={P[i], i}; chain(0);
        for (int i=1; i<=N; i++) X[P[i]]={N-i+1, i}; chain(1);
        for (int i=1; i<=N; i++) X[N-i+1]={N-P[i]+1, i}; chain(2);
        for (int i=1; i<=N; i++) X[N-P[i]+1]={i, i}; chain(3);

        int RP[4]={}, fl=0;
        for (int i=1; i<=N; i++) {
            int cn=0, nx=i;
            for (int j=0; j<4; j++) RP[j]=nx, cn+=CL[j][nx], nx=NX[j][nx];
            if (cn==N && nx==i) {fl=1; break;}
        }

        if (fl) {
            for (int i=1; i<=N; i++) {
                if (i<=RP[0] && P[i]<=P[RP[0]]) C[i]="EC"[t];
                if (i>=RP[1] && P[i]<=P[RP[1]]) C[i]="QZ"[t];
                if (i>=RP[2] && P[i]>=P[RP[2]]) C[i]="ZQ"[t];
                if (i<=RP[3] && P[i]>=P[RP[3]]) C[i]="CE"[t];
            }

            cout << "YES\n";
            for (int i=1; i<=N; i++) cout << C[i];
            return 0;
        }

        for (int i=1; i<=N; i++) P[i]=N-P[i]+1;
    }

    for (int i=1; i<=N; i++) X[i]={P[i], i}; if (chain2(0)) return 0;
    for (int i=1; i<=N; i++) X[P[i]]={i, i}; if (chain2(1)) return 0;

    cout << "NO";

    return 0;
}
