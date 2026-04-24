#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<vi> vvi;
#define forf(i, s, e) for(ll i=s; i<e; i++)

const ll X=20;
ll seg[1<<X+1];

void update(ll p, ll x){
    p+=1<<X;
    seg[p]=x;
    p>>=1;
    while(p){
        seg[p]=seg[p<<1]&seg[p<<1|1];
        p>>=1;
    }
}

ll And(ll s, ll e){
    ll ret=2147483647;
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) ret&=seg[s];
        if(~e&1) ret&=seg[e];
        s=s+1>>1; e=e-1>>1;
    }
    return ret;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, c=0; cin >> n;
    vi v(n);
    forf(i, 0, n) cin >> v[i];

    forf(i, 0, n) if(v[i]==0) c++;
    if(c){cout << n-c; return 0;}

    ll ret=2045678919;
    forf(i, 0, n){
        update(i, v[i]);
        ll s=0, e=i;

        while(s<=e){
            ll m=s+e>>1;
            if(And(m, i)) e=m-1;
            else s=m+1;
        }
        if(e==-1) continue;
        else ret=min(ret, i-e);
    }
    if(And(0, n-1)) cout << "-1";
    else cout<< ret+n-1;




    return 0;
}
