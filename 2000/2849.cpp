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


int main(){
    fastio;

    ll n, q; cin >> n >> q;
    set<tii> s; // 0 : LRLR... , 1 : RLRL...
    PQ<ll> pq, dpq;
    forf(i, 0, n) s.insert({i, i, 0});
    forf(i, 0, n) pq.push(1);
    while(q--){
        if(n==1){cout << "1\n"; continue;}

        ll a; cin >> a; a--;
        auto it=prev(s.lower_bound({a, inf, inf}));
        tii t=*it, f, b;
        if(t[0]==a && t[1]==a){
            if(a!=0){f=*prev(it); s.erase(prev(it)); dpq.push(f[1]-f[0]+1);}
            if(a!=n-1){b=*next(it); s.erase(next(it)); dpq.push(b[1]-b[0]+1);}
            if(a==0){
                s.insert({t[0], b[1], !t[2]});
                pq.push(b[1]-t[0]+1);
            }
            else if(a==n-1){
                s.insert({f[0], t[1], f[2]});
                pq.push(t[1]-f[0]+1);
            }
            else{
                s.insert({f[0], b[1], f[2]});
                pq.push(b[1]-f[0]+1);
            }
            s.erase(it); dpq.push(1);
        }
        else if(t[0]==a){
            if(a==0){
                s.insert({t[0], t[0], !t[2]}); pq.push(1);
                s.insert({t[0]+1, t[1], !t[2]}); pq.push(t[1]-t[0]);
            }
            else{
                f=*prev(it); s.erase(prev(it)); dpq.push(f[1]-f[0]+1);
                s.insert({f[0], t[0], f[2]}); pq.push(t[0]-f[0]+1);
                s.insert({t[0]+1, t[1], !t[2]}); pq.push(t[1]-t[0]);
            }
            s.erase(it); dpq.push(t[1]-t[0]+1);
        }
        else if(t[1]==a){
            if(a==n-1){
                s.insert({t[0], t[1]-1, t[2]}); pq.push(t[1]-t[0]);
                s.insert({t[1], t[1], !((t[2]+t[1]-t[0])%2)}); pq.push(1);
            }
            else{
                b=*next(it); s.erase(next(it)); dpq.push(b[1]-b[0]+1);
                s.insert({t[0], t[1]-1, t[2]}); pq.push(t[1]-t[0]);
                s.insert({t[1], b[1], !b[2]}); pq.push(b[1]-t[1]+1);
            }
            s.erase(it); dpq.push(t[1]-t[0]+1);
        }
        else{
            s.erase(it); dpq.push(t[1]-t[0]+1);
            s.insert({t[0], a-1, t[2]}); pq.push(a-t[0]);
            s.insert({a, a, !((t[2]+a-t[0])%2)}); pq.push(1);
            s.insert({a+1, t[1], !((t[2]+a-t[0])%2)}); pq.push(t[1]-a);
        }

        while(dpq.size() && pq.top()==dpq.top()){
            pq.pop(); dpq.pop();
        }
        cout << pq.top() << "\n";
    }

    return 0;
}
