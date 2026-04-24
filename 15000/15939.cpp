#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Q;
array<int, 2> V[10101];

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

bool isout(int x, int y) {
    for (int i=1; i<=N; i++) if (ccw(V[i], V[i%N+1], {x, y})<0) return true;
    return false;
}

int NX[3][5050];

void makenxt(int t, int x, int y) {
    for (int i=1, j=1; i<=N; i++) {
        while (ccw(V[i], V[j+1], {x, y})>0) j++;
        NX[t][i]=j;
    }
}

int Si[10101], S1[10101];

int goout(int t) {
    fill(Si, Si+N*2+3, 0); fill(S1, S1+N*2+3, 0);
    for (int i=1, j; i<=N; i++) {
        j=NX[t][i];
        S1[i]+=j-i-1; S1[i+1]-=j-i-1;
        S1[i-1+N]+=N+i-j-2; S1[i+N]-=N+i-j-2;
        S1[j]-=j; S1[i-1+N]+=j;
        Si[j]++; Si[i-1+N]--;
        S1[i+1]+=j; S1[j]-=j;
        Si[i+1]--; Si[j]++;
    }

    for (int i=1; i<=N*2; i++) S1[i]+=S1[i-1], Si[i]+=Si[i-1];
    int R=inf;
    for (int i=1; i<=N; i++) {
        int ret=S1[i]+i*Si[i]+S1[i+N]+(i+N)*Si[i+N];
        R=min(R, ret);
    }
    return R/2+1;
}

int cross(){
    int R=0;
    for (int i=1; i<=N; i++) R+=abs(NX[2][i]-NX[1][i]);
    return R/2;
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1], V[i+N]=V[i];
    cin >> Q;
    for (int i=1; i<=Q; i++) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        bool O1=isout(X1, Y1), O2=isout(X2, Y2);
        if (!O1) makenxt(1, X1, Y1);
        if (!O2) makenxt(2, X2, Y2);
        if (O1 && O2) cout << "0\n";
        else if (!O1 && O2) cout << goout(1) << "\n";
        else if (O1 && !O2) cout << goout(2) << "\n";
        else cout << min(goout(1)+goout(2), cross()) << "\n";
    }

    return 0;
}
