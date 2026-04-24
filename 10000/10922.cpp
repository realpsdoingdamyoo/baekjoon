//#include "horses.h"
#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

struct ll{
    long long p;
    bool lrg;

    void pl(ll x){
        p+=x.p;
        if(p>=mod || lrg || x.lrg){
            lrg=true;
            p%=mod;
        }
    }
    void mul(ll x){
        p*=x.p;
        if(p>=mod || lrg || x.lrg){
            lrg=true;
            p%=mod;
        }
    }

    bool operator <(const int& x) const{
        return !lrg && p<x;
    }
    void operator =(const int& x){
        lrg=false; p=x;
    }

    ll() = default;
    ll(int x) : lrg(x>=mod), p(x%mod) {}
};

ll max(ll y, int x){
    ll _x=x;
    if(y<x) return _x;
    else return y;
}

int n;
vector<int> x, y;
set<int> st;

const int X=20;
ll xsg[1<<X+1];

void update(int p, int q){
    p+=1<<X; xsg[p]=q; p>>=1;
    while(p){
        xsg[p]=1;
        xsg[p].mul(xsg[p<<1]);
        xsg[p].mul(xsg[p<<1|1]);
        p>>=1;
    }
}
ll mul(int s, int e){
    ll ret=1;
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) ret.mul(xsg[s]);
        if(~e&1) ret.mul(xsg[e]);
        ++s>>=1; --e>>=1;
    }
    return ret;
}

int ysg[1<<X+1];

void ypdate(int p, int q){
    p+=1<<X; ysg[p]=q; p>>=1;
    while(p) ysg[p]=max(ysg[p<<1], ysg[p<<1|1]), p>>=1;
}
int yax(int s, int e){
    int ret=0;
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) ret=max(ret, ysg[s]);
        if(~e&1) ret=max(ret, ysg[e]);
        ++s>>=1; --e>>=1;
    }
    return ret;
}

int solve(){
    ll pr=1;
    int pe=n-1;
    for(auto it=prev(st.end());; it=prev(it)){
        if(pr<yax(*it, pe)) pr=yax(*it, pe);
        pr.mul(x[*it]); pe=*it-1;
        if(pr.lrg || it==st.begin()){
            pr.mul(mul(0, *it-1));
            break;
        }
    }
    return pr.p;
}

int init(int N, int X[], int Y[]){
    n=N;
    for(int i=0; i<n; i++) x.push_back(X[i]);
    for(int i=0; i<n; i++) y.push_back(Y[i]);
	for(int i=0; i<n; i++){
        if(x[i]>1) st.insert(i);
        update(i, x[i]);
	}
	st.insert(0);
	for(int i=0; i<n; i++) ypdate(i, y[i]);
	return solve();
}

int updateX(int b, int c){
    if(st.find(b)!=st.end()) st.erase(st.find(b));
    x[b]=c;
    update(b, c);
    if(c>1) st.insert(b);
    st.insert(0);
	return solve();
}

int updateY(int b, int c){
    ypdate(b, c);
	return solve();
}

int _X[505050], _Y[505050], NNN;

signed main(){
	fastio;

	cin >> NNN;
	for(int i=0; i<NNN; i++) cin >> _X[i];
	for(int i=0; i<NNN; i++) cin >> _Y[i];

	cout << init(NNN, _X, _Y) << "\n";
	int m; cin >> m;
	while(m--){
        int a, b, c; cin >> a >> b >> c;
        if(a==1) cout << updateX(b, c) << "\n";
        else cout << updateY(b, c) << "\n";
	}


    return 0;
}
