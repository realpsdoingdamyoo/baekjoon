#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
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

ll n;
pii o;

ll ccw(pii a, pii b, pii c){
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

ll dist(pii a, pii b){
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}

bool cmp(pii a, pii b){
    ll c=ccw(o, a, b);
    if(c==0) return dist(o, a)<dist(o, b);
    return c>0;
}

bool C(pii a, pii b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}

vpii hull(vpii pnt){
    vpii st;
    sortc(pnt, C);
    o=pnt[0];
    sort(pnt.begin()+1, pnt.end(), cmp);
    if(ccw(pnt[0], pnt[1], pnt.back())==0) return st;
    st.pb(pnt[0]); st.pb(pnt[1]);
    forf(i, 2, pnt.size()){
        while(st.size()>=2 && ccw(pnt[i], st[st.size()-2], st[st.size()-1])<=0)
            st.pop_back();
        st.pb(pnt[i]);
    }
    return st;
}


int main(){
    fastio;

    ll n; cin >> n;

    vpii v(n), fv;
    forf(i, 0, n*2) cin >> v[i/2][i%2];
    fv=v;
    map<pii, ll> mp;

    ll cnt=1;
    while(v.size()>=3){
        vpii H=hull(v);
        vpii nv;
        for(pii i : v){
            bool chk=false;
            for(pii p : H)
                if(i==p) chk=true;
            if(!chk) nv.pb(i);
        }
        for(pii p : H) mp[p]=cnt;
        if(H.size()==0) break;
        v=nv;
        cnt++;
    }

    forf(i, 0, n) cout << mp[fv[i]] << " ";


    return 0;
}
