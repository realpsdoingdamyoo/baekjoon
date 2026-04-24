#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef string S;
#define V vector
#define PQ priority_queue
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll vtoi(vi v){
    ll k=0;
    forf(i, 0, 9){
        k=10*k+v[i];
    }
    return k;
}

ll vtoai(vi v){
    ll k=0, s=1;
    forf(i, 0, 9){
        s*=i+1;
        k+=v[i]*s;
    }
    return k;
}

int main(){
    //fastio;

    vi v(9), r(9); ll k=0;
    V<bool> vsd(3737373);
    forf(i, 0, 9){
        cin >> v[i];
        k=k*10+v[i];
    }
    forf(i, 0, 9) r[i]=(i+1)%9;
    queue<pii> q;
    q.push({k, 0});
    while(q.size()){
        k=q.front()[0];
        ll s=q.front()[1];
        q.pop();
        vi u(9);
        forb(i, 9, 0){
            u[i]=k%10; k/=10;
        }
        if(vsd[vtoai(u)]) continue;
        vsd[vtoai(u)]=1;
        if(u==r){
            cout << s;
            return 0;
        }
        ll ind=0;
        forf(i, 0, 9) if(u[i]==0) ind=i;
        if(ind>=3){
            swap(u[ind], u[ind-3]);
            if(!vsd[vtoai(u)]) q.push({vtoi(u), s+1});
            swap(u[ind], u[ind-3]);
        }
        if(ind%3>=1){
            swap(u[ind], u[ind-1]);
            if(!vsd[vtoai(u)]) q.push({vtoi(u), s+1});
            swap(u[ind], u[ind-1]);
        }
        if(ind<6){
            swap(u[ind], u[ind+3]);
            if(!vsd[vtoai(u)]) q.push({vtoi(u), s+1});
            swap(u[ind], u[ind+3]);
        }
        if(ind%3<=1){
            swap(u[ind], u[ind+1]);
            if(!vsd[vtoai(u)]) q.push({vtoi(u), s+1});
            swap(u[ind], u[ind+1]);
        }
    }
    cout << "-1";

    return 0;
}
