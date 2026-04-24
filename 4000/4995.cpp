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

typedef array<lf, 2> pff;

V<pff> v;
lf dis(pff a, pff b){
    return sqrt(pow(a[0]-b[0], 2)+pow(a[1]-b[1], 2));
}

ll pcnt(pff o){
    ll ret=0;
    for(pff i : v){
        if(dis(o, i)<=1.0001) ret++;
    }
    return ret;
}

int main() {
    fastio;
    while(1){
        ll n, ans=1; cin >> n;
        if(n==0) break;

        v.resize(n);
        forf(i, 0, n) cin >> v[i][0] >> v[i][1];

        forf(i, 0, n){
            forf(j, i+1, n){
                if(dis(v[i], v[j])>2) continue;

                pff m, o; forf(k, 0, 2) m[k]=(v[i][k]+v[j][k])/2;
                pff gi={(m[1]-v[i][1])/dis(m, v[i]), -(m[0]-v[i][0])/dis(m, v[i])};
                lf mdis=sqrt(1-pow(dis(m, v[i]), 2));

                o={m[0]+gi[0]*mdis, m[1]+gi[1]*mdis};
                ans=max(ans, pcnt(o));

                o={m[0]-gi[0]*mdis, m[0]-gi[1]*mdis};
                ans=max(ans, pcnt(o));
            }
        }

        cout << ans << "\n";
    }

	return 0;
}
