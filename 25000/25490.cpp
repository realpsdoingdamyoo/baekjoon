#include <bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
typedef vector<ll> vi;
#define V vector
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
const ll mod=1e9+7;

ll solve(vi v){
    ll n=v.size();
    if(n==0) return 0;
    if(n==1) return v[0]*v[0];

    ll m=(n-1)/2, ret=0;

    vi mn(n), mx(n);
    vi mns(n), mxs(n), mps(n);

    mn[m+1]=mx[m+1]=v[m+1];
    for(ll i=m+2; i<n; i++){
        mx[i]=max(mx[i-1], v[i]);
        mn[i]=min(mn[i-1], v[i]);
    }

    for(ll i=1; i<n; i++){
        mxs[i]=mx[i]+mxs[i-1];
        mns[i]=mn[i]+mns[i-1];
        mps[i]=mx[i]*mn[i]+mps[i-1];
    }

    ll mnp=m, mxp=m;

    ll mxv=v[m], mnv=v[m];
    for(ll i=m; i>=0; i--){
        mxv=max(mxv, v[i]);
        mnv=min(mnv, v[i]);

        while(mxp+1<n && mx[mxp+1]<mxv) mxp++;
        while(mnp+1<n && mn[mnp+1]>mnv) mnp++;

        if(mxp<mnp){
            ret+=mnv*mxv*(mxp-m);
            ret+=mnv*(mxs[mnp]-mxs[mxp]);
            ret+=mps[n-1]-mps[mnp];
        }
        else{
            ret+=mnv*mxv*(mnp-m);
            ret+=mxv*(mns[mxp]-mns[mnp]);
            ret+=mps[n-1]-mps[mxp];
        }
    }
    vi L, R;
    for(ll i=0; i<=m; i++) L.pb(v[i]);
    for(ll i=m+1; i<n; i++) R.pb(v[i]);
    ret+=solve(L)+solve(R);


    return ret%mod;
}

int main(){
    fastio;
    long long n; cin >> n;
    vi v(n);
    for(int i=0; i<n; i++){
        long long a; cin >> a;
        v[i]=a;
    }

    long long ans=solve(v)%mod;
    cout << ans;

    return 0;
}
