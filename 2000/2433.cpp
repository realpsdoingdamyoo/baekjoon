#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pql;

#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
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


int main(){
    fastio;

	ll n, m, c; cin >> n >> m >> c;
	vi v(n), ans; vcin;
	pql pqi, dpqi;
	pql pqd, dpqd;

	forf(i, 0, m) pqi.push(v[i]);
	forf(i, 0, m) pqd.push(-v[i]);

	ll s=0, e=m-1;

    forf(i, 0, n-m+1){
        if(pqi.top()+pqd.top()<=c) ans.push_back(i);
        pqi.push(v[e+1]); pqd.push(-v[e+1]);
        dpqi.push(v[s]); dpqd.push(-v[s]);
        e++; s++;

        while(dpqi.size() && pqi.top()==dpqi.top()){pqi.pop(); dpqi.pop();}
        while(dpqd.size() && pqd.top()==dpqd.top()){pqd.pop(); dpqd.pop();}

    }
    forf(i, 0, ans.size()) cout << ans[i]+1 << "\n";
    if(ans.empty()) cout << "NONE";

	return 0;
}
