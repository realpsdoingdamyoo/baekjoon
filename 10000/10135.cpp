#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int N;
long long X1, Y1, X2, Y2;
long long X[202020], Y[202020];
int C[202020], T[202020];
vector<array<int, 2>> P[202020];

const int S=18;
int seg[1<<S+1];
void update(int p, int x) {
    p+=1<<S;
    while (p) seg[p]+=x, p>>=1;
}
int sum(int s, int e) {
    int r=0;
    for (s+=1<<S, e+=1<<S; s<=e; ++s>>=1, --e>>=1) {
        if (s&1) r+=seg[s]; if (~e&1) r+=seg[e];
    } return r;
}


void dnc(vector<int> v, int s, int e) {
    if (s>=e) {for (int i : v) T[i]=s; return;}
    vector<int> L, R;

    int m=s+e>>1, M=v.size();

    vector<int> cy={0};
    for (int i : v) P[Y[i]].push_back({(int)X[i], i}), cy.push_back(Y[i]);
    sort(cy.begin(), cy.end());

    for (int i=1; i<=M; i++) {
        if (cy[i]==cy[i-1]) continue;
        sort(P[cy[i]].begin(), P[cy[i]].end());
        for (array<int, 2> j : P[cy[i]]) {
            int st=(X1*Y2==Y1*X2?j[0]:1);
            if (sum(st, j[0])>=C[j[1]] || j[1]<=m) L.push_back(j[1]), update(j[0], 1);
            else R.push_back(j[1]), C[j[1]]-=sum(st, j[0]);
        }
    }
    for (int i : v) update(X[i], -sum(X[i], X[i]));
    for (int i=1; i<=M; i++) P[cy[i]].clear();
    dnc(L, s, m); dnc(R, m+1, e);
}

signed main() {
    fastio;

    cin >> N;
    cin >> X1 >> Y1 >> X2 >> Y2;
    if (X1*Y2-Y1*X2<0) swap(X1, X2), swap(Y1, Y2);

    vector<long long> xcp, ycp;
    for (int i=1; i<=N; i++) {
        int x, y; cin >> x >> y;
        if (X1*Y2!=Y1*X2) X[i]=Y2*x-X2*y, Y[i]=X1*y-Y1*x;
        else X[i]=Y1*x-X1*y, Y[i]=X1*x+Y1*y;
        xcp.push_back(X[i]); ycp.push_back(Y[i]);
    }
    for (int i=1; i<=N; i++) cin >> C[i];
    sort(xcp.begin(), xcp.end()); xcp.erase(unique(xcp.begin(), xcp.end()), xcp.end());
    sort(ycp.begin(), ycp.end()); ycp.erase(unique(ycp.begin(), ycp.end()), ycp.end());

    for (int i=1; i<=N; i++) {
        X[i]=lower_bound(xcp.begin(), xcp.end(), X[i])-xcp.begin()+1;
        Y[i]=lower_bound(ycp.begin(), ycp.end(), Y[i])-ycp.begin()+1;
    }

    vector<int> vec;
    for (int i=1; i<=N; i++) vec.push_back(i);
    dnc(vec, 1, N);

    for (int i=1; i<=N; i++) cout << T[i] << " ";

    return 0;
}
