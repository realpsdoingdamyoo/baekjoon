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

ll n, k, q;
vpii query;
vi v;
vi push;
ll _stt=0;

pii qrvs(pii p){
    if(p[0]==1) p[1]=(k*100000-p[1])%k;
    else p[1]=(n*100000-p[1])%n;
    return p;
}

void pushpp(ll s, ll e){
    if(e<=k){
        push[s]++;
        if(e<k) push[e]--;
    }
    else{
        push[s]++; push[0]++;
        push[e%k]--;
    }
}

void Q(pii qr){
    if(qr[0]==1){
        _stt=(_stt-qr[1]+n)%n;
        pushpp(_stt%k, _stt%k+qr[1]);
    }
    else{
        _stt=(_stt-qr[1]+n)%n;
    }
}
void print(){
    forf(i, 0, n){
        cout << v[(_stt+i+push[(i+_stt)%k]*k)%n] << " ";
    }
}

int main() {
    cin >> n >> k >> q;
    v.resize(n); push.resize(k);
	forf(i, 0, q){
        ll a, b; cin >> a >> b;
        query.pb(qrvs({a, b}));
	}
	reverse(all(query));
	forf(i, 0, n) cin >> v[i];
    forf(i, 0, q) Q(query[i]);
    //forf(i, 0, q) cout << query[i][0] << " " << query[i][1] << "\n";

    //cout << _stt << "\n";
    forf(i, 1, k) push[i]+=push[i-1];
    //forf(i, 0, k) cout << push[i] << " "; cout << "\n";

	print();
	return 0;
}

/*
4 2 1
2 1
3 2 1 0

*/
