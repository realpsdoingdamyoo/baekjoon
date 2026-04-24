#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &v, bool inv) {
    int S = v.size();

    for(int i=1, j=0; i<S; i++) {
        int bit = S/2;

        while(j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if(i < j) swap(v[i], v[j]);
    }

    for(int k=1; k<S; k*=2) {
        double angle = (inv ? PI/k : -PI/k);
        cpx w(cos(angle), sin(angle));

        for(int i=0; i<S; i+=k*2) {
            cpx z(1, 0);

            for(int j=0; j<k; j++) {
                cpx even = v[i+j];
                cpx odd = v[i+j+k];

                v[i+j] = even + z*odd;
                v[i+j+k] = even - z*odd;

                z *= w;
            }
        }
    }

    if(inv) for(int i=0; i<S; i++) v[i] /= S;
}

vector<int> mul(vector<int> &v, vector<int> &u) {
    vector<cpx> vc(v.begin(), v.end());
    vector<cpx> uc(u.begin(), u.end());

    int S = 2;
    while(S < v.size() + u.size()) S *= 2;

    vc.resize(S); FFT(vc, false);
    uc.resize(S); FFT(uc, false);

    for(int i=0; i<S; i++) vc[i] *= uc[i];
    FFT(vc, true);

    vector<int> w(S);
    for(int i=0; i<S; i++) w[i] = round(vc[i].real());

    return w;
}

int n, m;

signed main(){
    fastio;

    cin >> n >> m;
    n++; m++;
    vector<int> v(n), u(m);
    for(int& i : v) cin >> i;
    for(int& i : u) cin >> i;

    vector<int> vx(n), vy(n), vz(n), ux(m), uy(m), uz(m);

    for(int i=0; i<n; i++){
        vx[i]=v[i]/10000;
        vy[i]=v[i]%10000/100;
        vz[i]=v[i]%100;
    }
    for(int i=0; i<m; i++){
        ux[i]=u[i]/10000;
        uy[i]=u[i]%10000/100;
        uz[i]=u[i]%100;
    }

    vector<int> xx=mul(vx, ux);
    vector<int> xy=mul(vx, uy);
    vector<int> yx=mul(vy, ux);
    vector<int> yy=mul(vy, uy);
    vector<int> xz=mul(vx, uz);
    vector<int> zx=mul(vz, ux);
    vector<int> yz=mul(vy, uz);
    vector<int> zy=mul(vz, uy);
    vector<int> zz=mul(vz, uz);
    while(xx.size()<n+m) xx.push_back(0);
    while(xy.size()<n+m) xy.push_back(0);
    while(yx.size()<n+m) yx.push_back(0);
    while(yy.size()<n+m) yy.push_back(0);
    while(xz.size()<n+m) xz.push_back(0);
    while(zx.size()<n+m) zx.push_back(0);
    while(yz.size()<n+m) yz.push_back(0);
    while(zy.size()<n+m) zy.push_back(0);
    while(zz.size()<n+m) zy.push_back(0);

    int ans=0;
    for(int i=0; i<n+m; i++){
        int ret=0;
        ret+=xx[i]*100000000;
        ret+=(xy[i]+yx[i])*1000000;
        ret+=(xz[i]+yy[i]+zx[i])*10000;
        ret+=(yz[i]+zy[i])*100;
        ret+=zz[i];
        ans^=ret;
    }
    cout << ans;

    return 0;
}
