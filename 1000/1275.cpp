#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vi segtree(5000000);
ll sz=1, szsz=0;

ll rtn(ll a, ll b){
    return a+b; //
}

void q1(ll node, ll val){
    segtree[node]=val; node/=2;
    while(node){
        segtree[node]=rtn(segtree[2*node], segtree[2*node+1]);
        node/=2;
    }
}

ll q2(ll s, ll e, ll t){ //at first t=sz
    if(s==e) return segtree[s];
    ll result; //
    while(t>=1){
        if((s&t)==(e&t)) t/=2;
        else{
            if(e-s==t*2-1) return segtree[s/t/2];
            else return rtn(q2(s, e/t*t-1, t), q2(e/t*t, e, t));
        }
    }
    return segtree[s];
}

int main() {
    fastio;
    ll n, q; cin >> n >> q;
    ll ssz; while(sz<n) {sz*=2; szsz++;} ssz=sz/2;
    for(ll i=sz; i<sz+n; i++) cin >> segtree[i];
    for(ll i=sz+n; i<2*sz; i++) segtree[i]=0; //
    while(ssz){
        for(ll i=ssz; i<2*ssz; i++){
            segtree[i]=rtn(segtree[2*i], segtree[2*i+1]);
        }
        ssz/=2;
    }
    for(ll i=0; i<q; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << q2(sz+min(a, b)-1, sz+max(a, b)-1, sz) << "\n";
        q1(sz+c-1, d);

        ssz=sz/2;
    }
    return 0;
}
