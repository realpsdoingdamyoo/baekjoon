#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll __int128
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

mt19937_64 rd(6974);

void print(vector<int> V) {
    cout << V.size() << "\n";
    for (int i : V) cout << i << " ";
}

vector<int> ONE(int N) {
    int sq=(int)sqrt(N);
    if (sq*sq==N) return {sq};
    return {};
}

struct pollard_rho {
    int pw(ll a, ll b, ll m) {
        ll r=1;
        while (b) {if (b&1) r=r*a%m; a=a*a%m; b>>=1;}
        return r;
    }

    bool miller_rabin(ll N, ll p) {
        ll K=N-1;
        while (K%2==0) {
            ll d=pw(p, K, N);
            if (d==N-1) return true;
            K>>=1;
        }
        ll t=pw(p, K, N);
        return (t==1 || t==N-1);
    }

    vector<int> prs={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<ll> pr={2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    bool isp(ll N) {
        if (N==1) return false;
        for (int i : prs) {
            if (N==i) return true;
            if (N%i==0) return false;
        }
        for (ll i : pr) {
            if (i%N!=0 && !miller_rabin(N, i)) return false;
        }
        return true;
    }

    int pol(int N) {
        if (N%2==0) return 2;
        if (isp(N)) return N;
        ll X=rd()%(N-2)+2, Y=X, C=rd()%10+1, g=1;

        while (g==1) {
            X=(X*X+C)%N;
            Y=(Y*Y+C)%N; Y=(Y*Y+C)%N;
            g=gcd(abs(X-Y), N);
            if (g==N) return pol(N);
        }

        if (isp(g)) return g;
        return pol(g);
    }

    vector<int> prp(int N) {
        vector<int> ret;
        while (N>1) {
            ll D=pol(N);
            ret.push_back(D); N/=D;
        }
        return ret;
    }
} P;

struct TSC {
    ll pw(ll a, ll b, ll m) {
        ll r=1;
        while (b) {if (b&1) r=r*a%m; a=a*a%m; b>>=1;}
        return r;
    }

    ll tor(ll n, ll p) {
        ll Q=p-1, S=0;
        while (Q%2==0) Q/=2, S++;

        if (S==1) {
            ll r=pw(n, (p+1)/4, p);
            if (r*r%p==p-1) return r;
            return 1;
        }

        ll z=1;
        while (pw(z, (p-1)/2, p)!=p-1) z++;

        ll M=S, c=pw(z, Q, p), t=pw(n, Q, p), R=pw(n, (Q+1)/2, p);
        while (t!=1) {
            ll i=0, tt=t;
            while (tt!=1) {
                tt=tt*tt%p, i++;
                if (i==M) return 1;
            }

            ll b=pw(c, pw(2, M-i-1, p-1), p), b2=b*b%p;

            M=i;
            c=b2;
            t=t*b2%p;
            R=R*b%p;
        }
        if (R*R%p==n) return R;
        return 1;
    }

    array<int, 2> sol(int N) {
        if (N==2) return {1, 1};
        ll R0=tor(N-1, N);
        if (R0*2>N) R0=N-R0;
        ll R1=N%R0;

        while (R1*R1>=N) R0=R0%R1, swap(R0, R1);
        return {(int)R1, (int)sqrt(N-R1*R1)};
    }
} F;

vector<int> TWO(int N) {
    map<int, int> mp;
    vector<int> pr=P.prp(N);
    for (int i : pr) mp[i]++;

    for (pair<int, int> i : mp) if (i.first%4==3 && i.second%2==1) return {};

    vector<int> ret={1, 0};
    for (pair<int, int> i : mp) {
        int p=i.first, x=i.second;
        while (x>=2) {ret[0]*=p; ret[1]*=p; x-=2;}
        if (x==1) {
            array<int, 2> y=F.sol(p);
            ret={ret[0]*y[0]+ret[1]*y[1], abs(ret[0]*y[1]-ret[1]*y[0])};
        }
    }
    return ret;
}

vector<int> THREE(int N) {
    map<int, int> mp;
    vector<int> pr=P.prp(N);
    for (int i : pr) mp[i]++;
    ll g=1, M=1;
    for (pair<int, int> i : mp) {
        int p=i.first, x=i.second;
        while (x>=2) g*=p, x-=2;
        if (x==1) M*=p;
    }

    for (int i=1; i*i<=M; i++) {
        vector<int> V=TWO(M-i*i);
        if (V.size()==2) {
            for (int& j : V) j*=g;
            V.push_back(g*i); return V;
        }
    }
}

vector<int> FOUR(int N) {
    int g=1;
    while (N%4==0) g*=2, N/=4;
    if (N%8!=7) return {};

    vector<int> V=THREE(N-1);
    for (int& i : V) i*=g; V.push_back(g);
    return V;
}

signed main() {
    fastio;

    int N; cin >> N;
    vector<int> V;
    V=ONE(N); if (V.size()==1) {print(V); return 0;}
    V=FOUR(N); if (V.size()==4) {print(V); return 0;}
    V=TWO(N); if (V.size()==2) {print(V); return 0;}
    V=THREE(N); if (V.size()==3) {print(V); return 0;}

    return 0;
}
