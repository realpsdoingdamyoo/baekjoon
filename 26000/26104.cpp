#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n;
array<int, 2> v[303];
int le[303][303];
vector<int> ord[303];
int rord[303][303];
double pi=acos(-1);

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

double ang(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    double ab=(a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    double bc=(b[0]-c[0])*(b[0]-c[0])+(b[1]-c[1])*(b[1]-c[1]);
    double ca=(c[0]-a[0])*(c[0]-a[0])+(c[1]-a[1])*(c[1]-a[1]);
    return acos((ab+bc-ca)/(2*sqrt(ab*bc)));
}

int Left(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    if (a[1]>b[1] || (a[1]==b[1] && a[0]>b[0])) swap(a, b);
    if (c[1]<a[1] || b[1]<=c[1]) return 0;
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0]>0;
}

int inp(int a, int b, int c) {
    if (!(v[a][1]<v[b][1] || (v[a][1]==v[b][1] && v[a][0]<v[b][0]))) swap(a, b);
    if (!(v[b][1]<v[c][1] || (v[b][1]==v[c][1] && v[b][0]<v[c][0]))) swap(b, c);
    if (!(v[a][1]<v[b][1] || (v[a][1]==v[b][1] && v[a][0]<v[b][0]))) swap(a, b);

    int ret=abs(le[a][b]+le[b][c]-le[a][c]);
    if (Left(v[a], v[b], v[c])) ret--;
    if (Left(v[b], v[c], v[a])) ret--;
    if (Left(v[c], v[a], v[b])) ret--;
    return ret;
}

const array<int, 2> P={-28957, 3487984};
int x;
bool angsrt(int a, int b) {
    int A=ccw(P, v[x], v[a]), B=ccw(P, v[x], v[b]);
    if (A>=0 && B>=0) return ang(P, v[x], v[a])<ang(P, v[x], v[b]);
    if (A<0 && B<0) return ang(P, v[x], v[a])>ang(P, v[x], v[b]);
    return A>B;
}

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];

    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) for (int k=1; k<=n; k++){
        if (k==i || k==j) continue;
        le[i][j]+=Left(v[i], v[j], v[k]);
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) if (j!=i) ord[i].push_back(j);
        x=i; sort(ord[i].begin(), ord[i].end(), angsrt);
        for (int k=0; k<n-1; k++) rord[i][ord[i][k]]=k;
    }

    int ans=0;
    for (int i=1; i<=n; i++)  for (int j=i+1; j<=n; j++) {
        vector<double> ij[2], ji[2];
        int jlc=rord[i][j];
        for (int k=(jlc+1)%(n-1); k!=jlc; k=(k+1)%(n-1)) if (inp(i, j, ord[i][k])==0)
            ij[ccw(v[i], v[j], v[ord[i][k]])>0].push_back(ang(v[ord[i][k]], v[i], v[j]));

        int ilc=rord[j][i];
        for (int k=(ilc+1)%(n-1); k!=ilc; k=(k+1)%(n-1))  if (inp(i, j, ord[j][k])==0)
            ji[ccw(v[i], v[j], v[ord[j][k]])>0].push_back(ang(v[ord[j][k]], v[j], v[i]));

        int ret=ij[0].size()*ij[1].size();
        if (ret==0) continue;

        if (ij[0].front()>ij[0].back()) reverse(ij[0].begin(), ij[0].end());
        if (ij[1].front()>ij[1].back()) reverse(ij[1].begin(), ij[1].end());
        if (ji[0].front()>ji[0].back()) reverse(ji[0].begin(), ji[0].end());
        if (ji[1].front()>ji[1].back()) reverse(ji[1].begin(), ji[1].end());

        for (int k=0, p=ij[1].size(); k<ij[0].size(); k++) {
            while (p && ij[1][p-1]+ij[0][k]>pi) p--;
            ret+=(ij[1].size()-p);
        }
        for (int k=0, p=ji[1].size(); k<ji[0].size(); k++) {
            while (p && ji[1][p-1]+ji[0][k]>pi) p--;
            ret+=(ji[1].size()-p);
        }

        ans+=ret;
    }
    cout << ans/2;

    return 0;
}
