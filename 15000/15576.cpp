#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int mpw(int a, int x){
    int ret=1;
    while(x){
        if(x&1) ret=ret*a%MOD;
        a=a*a%MOD; x>>=1;
    }
    return ret;
}

void ntt(vector<int>& v, bool b){
    int n=v.size(), j=0;
    vector<int> root(n>>1);

    for(int i=1; i<n; i++){
        int bit=n>>1;
        while(j>=bit){
            j-=bit;
            bit>>=1;
        }
        j+=bit;
        if(i<j) swap(v[i], v[j]);
    }

    int ang=mpw(3, MOD/n);
    if(b) ang=mpw(ang, MOD-2);
    root[0]=1;

    for(int i=1; i<n>>1; i++) root[i]=root[i-1]*ang%MOD;
    for(int i=2; i<=n; i<<=1){
        int step=n/i;
        for(int j=0; j<n; j+=i){
            for(int k=0; k<i>>1; k++){
                int u=v[j|k], r=v[j|k|i>>1]*root[step*k]%MOD;
                v[j|k]=(u+r)%MOD;
                v[j|k|i>>1]=(u-r+MOD)%MOD;
            }
        }
    }
    int t=mpw(n, MOD-2);
    if(b) for(int i=0; i<n; i++) v[i]=v[i]*t%MOD;
}

vector<int> mul(vector<int> a, vector<int> b){
    int n=1;
    while(a.size()+b.size()>n) n<<=1;
    a.resize(n); b.resize(n);

    ntt(a, false); ntt(b, false);
    for(int i=0; i<n; i++) a[i]=a[i]*b[i]%MOD;
    ntt(a, true);
    return a;
}

signed main(){
    fastio;
    string a, b; cin >> a >> b;
    vector<int> v(a.length()), u(b.length());

    for(int i=0; i<a.length(); i++) v[i]=a[a.length()-1-i]-'0';
    for(int i=0; i<b.length(); i++) u[i]=b[b.length()-1-i]-'0';

    vector<int> r=mul(v, u);
    r.push_back(0); r.push_back(0);
    for(int i=0; i<r.size()-1; i++) r[i+1]+=r[i]/10, r[i]%=10;
    while(r.back()==0 && r.size()>=2) r.pop_back();
    for(int i=r.size()-1; i>=0; i--) cout << r[i];

    return 0;
}
