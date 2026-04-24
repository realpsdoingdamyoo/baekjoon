#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int cp[10][10], N;
vector<array<int, 2>> mt[2];
int mm[2];

int chk1[30], chk2[30];

void bdfs(int t, int th, int g){
    if(th==mt[t].size()) mm[t]=max(mm[t], g);
    else{
        bdfs(t, th+1, g);
        if(cp[mt[t][th][0]][mt[t][th][1]]==1 && chk1[mt[t][th][0]-mt[t][th][1]+15]==0 &&  chk2[mt[t][th][0]+mt[t][th][1]]==0){
            chk1[mt[t][th][0]-mt[t][th][1]+15]=1;
            chk2[mt[t][th][0]+mt[t][th][1]]=1;
            bdfs(t, th+1, g+1);
            chk1[mt[t][th][0]-mt[t][th][1]+15]=0;
            chk2[mt[t][th][0]+mt[t][th][1]]=0;
        }
    }
}

int n;
array<int, 2> v[303];
int le[303][303];
vector<int> ord[303];
int rord[303][303];

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

double ang(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    double ab=sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
    double bc=sqrt((b[0]-c[0])*(b[0]-c[0])+(b[1]-c[1])*(b[1]-c[1]));
    double ca=sqrt((c[0]-a[0])*(c[0]-a[0])+(c[1]-a[1])*(c[1]-a[1]));
    return acos((ab*ab+bc*bc-ca*ca)/(2*ab*bc));
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

int main(){
    fastio;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {cin >> cp[i][j]; if(cp[i][j]) mt[(i+j)%2].push_back({i, j});}
    }
    bdfs(0, 0, 0); bdfs(1, 0, 0);
    cout << mm[0]+mm[1] << endl;
    
    n=300;
    for (int i=1; i<=n; i++) v[i][0]=rand(), v[i][1]=rand();

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
        vector<int> cw[2];
        for (int k=1; k<=n; k++) if (k!=i && k!=j) {
            if (inp(i, j, k)==0) cw[ccw(v[i], v[j], v[k])>0].push_back(k);
        }
        if (cw[0].size()==0 || cw[1].size()==0) continue;
        int ret=cw[0].size()*cw[1].size();

        vector<double> ij[2], ji[2];

        int jlc=rord[i][j];
        for (int k=(jlc+1)%(n-1); k!=jlc; k=(k+1)%(n-1)) if (inp(i, j, ord[i][k])==0)
            ij[ccw(v[i], v[j], v[ord[i][k]])>0].push_back(ang(v[ord[i][k]], v[i], v[j]));

        int ilc=rord[j][i];
        for (int k=(ilc+1)%(n-1); k!=ilc; k=(k+1)%(n-1))  if (inp(i, j, ord[j][k])==0)
            ji[ccw(v[i], v[j], v[ord[j][k]])>0].push_back(ang(v[ord[j][k]], v[j], v[i]));

        if (ij[0].front()>ij[0].back()) reverse(ij[0].begin(), ij[0].end());
        if (ij[1].front()>ij[1].back()) reverse(ij[1].begin(), ij[1].end());
        if (ji[0].front()>ji[0].back()) reverse(ji[0].begin(), ji[0].end());
        if (ji[1].front()>ji[1].back()) reverse(ji[1].begin(), ji[1].end());

        for (int k=0, p=ij[1].size(); k<ij[0].size(); k++) {
            while (p && ij[1][p-1]+ij[0][k]>acos(-1)) p--;
            ret+=(ij[1].size()-p);
        }
        for (int k=0, p=ji[1].size(); k<ji[0].size(); k++) {
            while (p && ji[1][p-1]+ji[0][k]>acos(-1)) p--;
            ret+=(ji[1].size()-p);
        }

        ans+=ret;
    }
    
    return 0;
}
