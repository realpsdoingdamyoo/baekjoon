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
#define cf cout.flush()

int main(){
    fastio;

    ll n, x; cin >> n >> x;
    vi v(n); vcin;
    vi u=v, mx(n);

    PQ<ll, vi, greater<ll>> pq1, dpq1;

    forf(i, 0, x) pq1.push(v[i]);
    forf(i, x, n+1){
        mx[i-x]=pq1.top();
        if(i==n) break;
        pq1.push(v[i]);
        dpq1.push(v[i-x]);
        while(dpq1.size() && pq1.top()==dpq1.top())
            pq1.pop(), dpq1.pop();
    }

    PQ<ll> pq2, dpq2;
    forf(i, 0, x){
        pq2.push(mx[i]);
        u[i]=pq2.top();
    }

    forf(i, x, n){
        pq2.push(mx[i]);
        dpq2.push(mx[i-x]);
        while(dpq2.size() && pq2.top()==dpq2.top())
            pq2.pop(), dpq2.pop();
        u[i]=pq2.top();
    }

    ll ret=0, cnt=0;
    forf(i, 0, n) ret+=v[i]-u[i];

    vi mns(n+x);
    PQ<ll> pq3, dpq3, ddpq3;
    forf(i, 0, n){
        if(mns[i]) dpq3.push(mns[i]);
        while(dpq3.size() && ddpq3.size() && dpq3.top()==ddpq3.top())
            dpq3.pop(), ddpq3.pop();

        while(dpq3.size() && pq3.top()==dpq3.top())
            pq3.pop(), dpq3.pop();

        while(pq3.size() && pq3.top()>u[i]){
            ddpq3.push(pq3.top());
            pq3.pop();
        }


        if(pq3.size()==0 || pq3.top()<u[i]){
            pq3.push(u[i]);
            mns[i+x]=u[i];
            cnt++;
        }
    }

    cout << ret << "\n" << cnt;


    return 0;
}
