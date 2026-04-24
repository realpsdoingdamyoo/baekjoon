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

ll dir;

bool iut(ll a, ll b, ll sts){
    if(abs(a-b)==1 || abs(a-b)==sts-1){
        if((a+1)%sts==b) swap(a, b);
        if(b%2==dir) return true;
    }
    return false;
}

int main(){
    fastio;

    ll n; cin >> n;
    vpii v(n); forf(i, 0, n*2) cin >> v[i/2][i%2];
    vpii st;

    forf(i, 0, n)
        if(v[i][0]==v[(i+1)%n][0] && v[i][1]*v[(i+1)%n][1]<0){
            st.pb({v[i][0], st.size()});
            if(st.size()==1) dir=(v[i][1]>0);
        }
    sortv(st);


    ll ans2=0;
    forf(i, 0, st.size()-1){
        if(iut(st[i][1], st[i+1][1], st.size())){
            ans2++;
        }
    }

    ll ans1=0;
    vi stk;
    for(pii p : st){
        if(stk.size()==0){
            stk.pb(p[1]);
        }
        else if(iut(stk.back(), p[1], st.size())){
            stk.pop_back();
        }
        else{
            stk.pb(p[1]);
        }
        ans1+=(stk.size()==0);

    }
    cout << ans1 << " " << ans2;

    return 0;
}
