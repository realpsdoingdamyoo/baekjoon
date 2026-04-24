#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
typedef string S;
#define V vector
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}



int main() {
    fastio;

    ll n, a, b; cin >> n >> a >> b;
    vi v(n);
    v[a-1]|=2LL; v[b-1]|=1LL;
    queue<ll> qa, qb;
    ll mv=1, t=0;
    while(mv<n){
        forf(i, 0, n){
            if(v[i]==3){cout << t << "\n"; return 0;}
            if(v[i]&2LL) qa.push(i);
            if(v[i]&1LL) qb.push(i);
            v[i]=0;
        }
        ll qas=qa.size();
        while(qas--){
            if(0<=qa.front()+mv && qa.front()+mv<n) qa.push(qa.front()+mv);
            if(0<=qa.front()-mv && qa.front()-mv<n) qa.push(qa.front()-mv);
            qa.pop();
        }
        ll qbs=qb.size();
        while(qbs--){
            if(0<=qb.front()+mv && qb.front()+mv<n) qb.push(qb.front()+mv);
            if(0<=qb.front()-mv && qb.front()-mv<n) qb.push(qb.front()-mv);
            qb.pop();
        }


        qas=qa.size();
        while(qas--){
            v[qa.front()]|=2;
            qa.push(qa.front()); qa.pop();
        }
        qbs=qb.size();
        while(qbs--){
            v[qb.front()]|=1;
            qb.push(qb.front()); qb.pop();
        }

        mv<<=1; t++;
    }
    cout << "-1\n";
    return 0;
}
