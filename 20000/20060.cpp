#include "combo.h"
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
//typedef string S;
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


string guess_sequence(int n){
    string A="ABXY", L;
    string ans;

    ll f=!!press("XY");
    ll g=2*f+press(A.substr(f*2+1, 1));
    ans+=A[g];
    forf(i, 0, 4) if(i-g) L+=A[i];

    forf(i, 1, n-1){
        string nw;
        forf(i, 0, 3){
            nw+=ans+L[0]+L[i];
        }
        nw+=ans+L[1];
        ll gt=press(nw);
        if(gt==ans.length()) ans+=L[2];
        else if(gt==ans.length()+1) ans+=L[1];
        else ans+=L[0];
    }
    if(n>1){
        f=press(ans+L[2]);
        if(f==n) return ans+L[2];
        else{
            f=press(ans+L[1]);
            if(f==n) return ans+L[1];
            else return ans+L[0];
        }
    }

    return ans;
}
