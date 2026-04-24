#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, K;
int X[505], Y[505];
const double pi=3.14159265358979324;
double AX, AY;

signed main() {
    fastio;

    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> X[i] >> Y[i];
    double S=1e-9, E=10000;

    while (E-S>1e-11) {
        double R=(S+E)/2;
        bool flg=false;
        for (int i=1; i<=N; i++) {
            vector<pair<double, int>> vec;
            for (int j=1; j<=N; j++) if (i!=j) {
                double dx=X[j]-X[i], dy=Y[j]-Y[i];
                double a=(dx==0?(dy>0?pi/2:pi*3/2):atan(dy/dx));
                if (a<0) a+=pi;
                if (dx!=0 && dy<0) a+=pi;
                if (dy==0 && dx<0) a=pi;
                double dis=sqrt(dx*dx+dy*dy);
                if (dis>R*2) continue;
                double b=acos(dis/2/R);
                double l=a-b, r=a+b;
                if (l<0) l+=pi*2; if (r>pi*2) r-=pi*2;
                if (r<l) {
                    vec.push_back({0, 1}); vec.push_back({r, -1});
                    vec.push_back({l, 1}); vec.push_back({pi*2, -1});
                }
                else {
                    vec.push_back({l, 1}); vec.push_back({r, -1});
                }
            }

            sort(vec.begin(), vec.end());
            int C=1, M=1;
            for (pair<double, int> j : vec) {
                C+=j.second, M=max(C, M);
                if (C>=K) AX=X[i]+R*cos(j.first), AY=Y[i]+R*sin(j.first);
            }

            if (M>=K) flg=true;
        }
        if (flg) E=R; else S=R;
    }
    cout.precision(12);
    printf("%.5lf\n%.5lf %.5lf", S, AX, AY);

    return 0;
}
