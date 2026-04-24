#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e11;

int n;
array<double, 2> v[5050];
double A1=inf, A2;

double dist(array<double, 2> a, array<double, 2> b) {
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

double ccw(array<double, 2> a, array<double, 2> b, array<double, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

double ss(array<double, 2> a, array<double, 2> b, array<double, 2> c) {
    return fabs(ccw(a, b, c))/2.0;
}

bool par(array<double, 2> a, array<double, 2> b, array<double, 2> c, array<double, 2> d) {
    return (a[0]-b[0])*(c[1]-d[1])==(a[1]-b[1])*(c[0]-d[0]);
}

array<double, 2> crs(array<double, 2> a, array<double, 2> b, array<double, 2> c, array<double, 2> d) {
    array<double, 3> x={b[1]-a[1], a[0]-b[0], b[1]*a[0]-a[1]*b[0]};
    array<double, 3> y={d[1]-c[1], c[0]-d[0], d[1]*c[0]-c[1]*d[0]};
    double X=(x[2]*y[1]-y[2]*x[1])/(x[0]*y[1]-y[0]*x[1]);
    double Y=(x[2]*y[0]-y[2]*x[0])/(y[0]*x[1]-x[0]*y[1]);
    return {X, Y};
}

double S;

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];

    for (int i=2; i<n; i++) S+=ss(v[1], v[i], v[i+1]);

    for (int i=1; i<=n; i++) {
        int p=i%n+1; double ns=0;
        while (ns+ss(v[i], v[p], v[p%n+1])<S/2) ns+=ss(v[i], v[p], v[p%n+1]), p=p%n+1;
        double ws=S/2-ns;
        double rt=ws/ss(v[i], v[p], v[p%n+1]);
        array<double, 2> x={v[p][0]*(1-rt)+v[p%n+1][0]*rt, v[p][1]*(1-rt)+v[p%n+1][1]*rt};
        double dis=dist(v[i], x);
        A1=min(A1, dis); A2=max(A2, dis);
    }

    for (int i=1; i<=n; i++){
        double ps=0;
        for (int x=i; x%n+1!=i; x=x%n+1) {
            int j=i-1+(i==1)*n, y=x%n+1;
            if (ccw({v[i][0]-v[j][0], v[i][1]-v[j][1]}, {0, 0}, {v[y][0]-v[x][0], v[y][1]-v[x][1]})>0) break;
            ps+=ss(v[i], v[x-1+(x==1)*n], v[x]);

            if (ps>S/2 || ps+ss(v[i], v[x], v[j])+ss(v[j], v[x], v[y])<S/2) continue;

            double disb=0;

            if (par(v[i], v[j], v[x], v[y])) {
                array<double, 2> IJV={v[j][0]-v[i][0], v[j][1]-v[i][1]};
                double IJD=sqrt(IJV[0]*IJV[0]+IJV[1]*IJV[1]);
                array<double, 2> IJP={v[i][1]-IJV[0]*inf/IJD, v[i][1]-IJV[1]*inf/IJD};
                array<double, 2> XYV={v[y][0]-v[x][0], v[y][1]-v[x][1]};
                double XYD=sqrt(XYV[0]*XYV[0]+XYV[1]*XYV[1]);
                array<double, 2> XYP={v[x][0]-XYV[0]*inf/XYD, v[x][1]-XYV[1]*inf/XYD};
                array<double, 2> RP={(IJP[0]+XYP[0])/2, (IJP[1]+XYP[1])/2};
                disb=dist(RP, v[x])-dist(RP, v[i]);
            }
            else {
                array<double, 2> xp=crs(v[i], v[j], v[x], v[y]);
                disb=dist(xp, v[x])-dist(xp, v[i]);
            }

            // len, len-disb

            double s=max((double)0, disb), e=min(dist(v[i], v[j]), dist(v[x], v[y])+disb);
            if (s>e) continue;

            while (e-s>1e-9) {
                double m=(s+e)/2;
                array<double, 2> IJV={v[j][0]-v[i][0], v[j][1]-v[i][1]};
                double IJD=sqrt(IJV[0]*IJV[0]+IJV[1]*IJV[1]);
                array<double, 2> IJP={v[i][0]+IJV[0]*m/IJD, v[i][1]+IJV[1]*m/IJD};
                array<double, 2> XYV={v[y][0]-v[x][0], v[y][1]-v[x][1]};
                double XYD=sqrt(XYV[0]*XYV[0]+XYV[1]*XYV[1]);
                array<double, 2> XYP={v[x][0]+XYV[0]*(m-disb)/XYD, v[x][1]+XYV[1]*(m-disb)/XYD};
                double RS=ps+ss(v[i], v[x], IJP)+ss(IJP, v[x], XYP);
                if (RS>S/2) e=m; else s=m;
            }
            double m=(s+e)/2;
            array<double, 2> IJV={v[j][0]-v[i][0], v[j][1]-v[i][1]};
            double IJD=sqrt(IJV[0]*IJV[0]+IJV[1]*IJV[1]);
            array<double, 2> IJP={v[i][0]+IJV[0]*m/IJD, v[i][1]+IJV[1]*m/IJD};
            array<double, 2> XYV={v[y][0]-v[x][0], v[y][1]-v[x][1]};
            double XYD=sqrt(XYV[0]*XYV[0]+XYV[1]*XYV[1]);
            array<double, 2> XYP={v[x][0]+XYV[0]*(m-disb)/XYD, v[x][1]+XYV[1]*(m-disb)/XYD};
            double RS=ps+ss(v[i], v[x], IJP)+ss(IJP, v[x], XYP);
            if (abs(RS-S/2)>1e-3) continue;

            A1=min(A1, dist(IJP, XYP));

        }
    }


    cout.precision(10);
    cout << A1 << "\n" << A2 << "\n";


    return 0;
}
