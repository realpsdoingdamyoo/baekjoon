#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, N, M;
char s[2][50][50];
int xc[2][50][50];
int dp[2][50][50][50][50];
bool cal[2][50][50][50][50];

bool allx(int t, int xs, int ys, int xe, int ye) {
    int a=xc[t][xe][ye];
    int b=(xs>0)?xc[t][xs-1][ye]:0;
    int c=(ys>0)?xc[t][xe][ys-1]:0;
    int d=((xs>0 && ys>0)?xc[t][xs-1][ys-1]:0);
    return a-b-c+d==(xe-xs+1)*(ye-ys+1);
}

int sb(int t, int xs, int ys, int xe, int ye) {
    if (xs>xe || ys>ye || ye<0 || xe<0) return 0;
    if (cal[t][xs][ys][xe][ye]) return dp[t][xs][ys][xe][ye];
    cal[t][xs][ys][xe][ye]=true;
    if (allx(t, xs, ys, xs, ye)) return dp[t][xs][ys][xe][ye]=sb(t, xs+1, ys, xe, ye);
    if (allx(t, xe, ys, xe, ye)) return dp[t][xs][ys][xe][ye]=sb(t, xs, ys, xe-1, ye);
    if (allx(t, xs, ys, xe, ys)) return dp[t][xs][ys][xe][ye]=sb(t, xs, ys+1, xe, ye);
    if (allx(t, xs, ye, xe, ye)) return dp[t][xs][ys][xe][ye]=sb(t, xs, ys, xe, ye-1);

    priority_queue<int, vector<int>, greater<int>> pq; pq.push(inf);

    for (int i=xs; i<=xe; i++) for (int j=ys; j<=ye; j++) {
        if (s[t][i][j]=='L') pq.push(sb(t, xs, ys, i-1, ye)^sb(t, i+1, ys, xe, ye));
        else if (s[t][i][j]=='R') pq.push(sb(t, xs, ys, xe, j-1)^sb(t, xs, j+1, xe, ye));
        else if (s[t][i][j]=='X') pq.push(sb(t, xs, ys, i-1, j-1)^sb(t, xs, j+1, i-1, ye)^sb(t, i+1, ys, xe, j-1)^sb(t, i+1, j+1, xe, ye));
    }

    int pv=-1;
    while (pq.size()) {
        if (pv+1<pq.top()) return dp[t][xs][ys][xe][ye]=pv+1;
        pv=max(pv, pq.top()); pq.pop();
    }
}

signed main() {
    fastio;

    cin >> N >> M; n=(N+M)/2+2;

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) s[0][i][j]=s[1][i][j]='K';

    for (int i=0; i<N; i++) {
        string p; cin >> p;
        for (int j=0; j<M; j++) {
            s[(i+j)%2][(i+j)/2][(i-j+M)/2]=p[j];
        }
    }

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) for (int t : {0, 1}) xc[t][i][j]=(s[t][i][j]=='K');
    for (int i=1; i<n; i++) for (int j=0; j<n; j++) for (int t : {0, 1}) xc[t][i][j]+=xc[t][i-1][j];
    for (int i=0; i<n; i++) for (int j=1; j<n; j++) for (int t : {0, 1}) xc[t][i][j]+=xc[t][i][j-1];


    int p0=sb(0, 0, 0, n-1, n-1);
    int p1=sb(1, 0, 0, n-1, n-1);

    if (p0^p1) cout << "koosaga";
    else cout << "cubelover";

    return 0;
}
