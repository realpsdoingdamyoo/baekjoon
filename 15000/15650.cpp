#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pql;
typedef map<ll, ll> mii;
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


vi v(8), vsd(8);
ll n, m;
vi tp;

void BT(){
    if(tp.size()==m){
        forf(i, 0, m) cout << tp[i] << " ";
        cout << "\n";
        return;
    }
    else{
        forf(i, 0, n){
            if(vsd[i]==0 && (tp.size()==0 || tp[tp.size()-1]<v[i])){
                vsd[i]=1; tp.pb(v[i]);
                BT();
                vsd[i]=0; tp.pop_back();
            }
        }
    }
}

int main() {
	fastio;

	cin >> n >> m;
	forf(i, 0, n) v[i]=i+1;
	BT();

	return 0;
}
