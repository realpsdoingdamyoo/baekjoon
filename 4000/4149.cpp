#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pql;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll ll_mul(ll a, ll b, ll modular){ // a*b%modular
    ll res=0;
    while(b){
        if(b%2) res=(res+a)%modular;
        b/=2; a=2*a%modular;
    }
    return res;
}
ll powmod(ll a, ll b, ll modular){ // a^b%modular
    ll res=1;
    while(b){
        if(b%2) res=ll_mul(res, a, modular);
        a=ll_mul(a, a, modular); b/=2;
    }
    return res;
}
bool miller_rabin(ll num, ll pr){
    ll k=num-1;
    while(k%2==0){
        ll d=powmod(pr, k, num);
        if(d==num-1) return true;
        k/=2;
    }
    ll t=powmod(pr, k, num);
    return (t==1 || t==num-1);
}
bool MRP(ll num){
    if(num==1) return false;
    ll primes[11]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    forf(i, 0, 11){
        if(num==primes[i]) return true;
        if(num%primes[i]==0) return false;
        if(!miller_rabin(num, primes[i])) return false;
    }
    return true;
}


ll pollard_rho(ll num){
    if(num%2==0) return 2;
    if(MRP(num)) return num;
    ll x=rand()%(num-2)+2, y=x, c=rand()%10+1, g=1;

    while(g==1){
        x=(ll_mul(x, x, num)+c)%num;
        y=(ll_mul(y, y, num)+c)%num;
        y=(ll_mul(y, y, num)+c)%num;
        g=gcd((x>y?x-y:y-x), num);
        if(g==num) return pollard_rho(num);
    }

    if(MRP(g)) return g;
    else return pollard_rho(g);
}

vi PRP(ll num){
    vi prp;
    while(num>1){
        ll div=pollard_rho(num);
        prp.pb(div);
        num/=div;
    }
    return prp;
}


int main() {
	fastio;

	ll n; cin >> n;
	vi v=PRP(n);

	sortv(v);
	forf(i, 0, v.size()) cout << v[i] << "\n";

	return 0;
}
