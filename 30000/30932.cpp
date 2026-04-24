#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//const int mod=1e9+7, MOD=998244353, inf=2e18;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2")

const int MAXN=24;
bitset<1<<MAXN> bit[MAXN];
int DP[1<<MAXN], OK[MAXN];

int N, M;
int A[7070], B[7070], C[7070];

bool merge(int a, int b, int c, vector<array<int, 2>>& vec) {
    int A=0, B=0;
    for (int i=0; i<vec.size(); i++) {
        if (vec[i][0]&(1<<a)) A=i;
        if (vec[i][0]&(1<<b)) B=i;
    }
    int AON=vec[A][1]&(1<<a); AON=!!AON;
    int BON=vec[B][1]&(1<<b); BON=!!BON;
    if (A==B) return (AON^BON)==c;
    if (AON^BON^c) vec[B][1]^=vec[B][0];
    vec[A][0]|=vec[B][0]; vec[A][1]|=vec[B][1];
    vec.erase(vec.begin()+B);
    return true;
}

bool chk(int p) {
    vector<array<int, 2>> vec;
    for (int i=0; i<N; i++) if (i!=p) vec.push_back({1<<i, 0});
    bool ret=true;
    for (int i=1; i<=M; i++) if (B[i]==p) ret=ret&&merge(A[i], C[i], 1, vec);
    if (vec.size()==N-1) {OK[p]=1; return true;}
    int r=0;
    for (int i=0; i<vec.size(); i++) r|=vec[i][1];
    for (int i=0; i<1<<vec.size(); i++) {
        int j=i?i^i-1:0;
        while (j) {
            int k=j-(j&(j-1)); j&=j-1;
            r^=vec[31-__builtin_clz(k)][0];
        }
        bit[p][r]=true;
    }

    return ret;
}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) cin >> A[i] >> B[i] >> C[i], A[i]--, B[i]--, C[i]--;
    for (int i=0; i<N; i++) if (!chk(i)){cout << "0"; return 0;}

    DP[0]=1;
    for (int i=1; i<1<<N; i++) {
        for (int j=0; j<N; j++) if (i&(1<<j) && (bit[j][i^(1<<j)] || OK[j]))
            DP[i]=(DP[i]+DP[i^(1<<j)])%998244353;
    }
    cout << DP[(1<<N)-1];

    return 0;
}
