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

    ll n; cin >> n;

    if(n%2==0) cout << n*n-1 << "\n";
    else cout << n*n-n << "\n";

    cout << "1 1\n";

    for(ll i=1; i<=n-1; i++){
        for(ll j=1; j<=n; j++){
            cout << n << " ";

            if(i%2==1){
                if(j%2==1){
                    for(ll k=2; k<=n+1-j; k++) cout << i << " " << k << " ";
                    for(ll k=n+1-j; k<=n; k++) cout << i+1 << " " << k << " ";
                }
                else{
                    for(ll k=n-1; k>=n+1-j; k--) cout << i+1 << " " << k << " ";
                    for(ll k=n+1-j; k>=1; k--) cout << i << " " << k << " ";
                }
            }
            else{
                if(j%2==1){
                    for(ll k=n-1; k>=j; k--) cout << i << " " << k << " ";
                    for(ll k=j; k>=1; k--) cout << i+1 << " " << k << " ";
                }
                else{
                    for(ll k=2; k<=j; k++) cout << i+1 << " " << k << " ";
                    for(ll k=j; k<=n; k++) cout << i << " " << k << " ";
                }
            }
            cout << "\n";
        }

        if(n%2==0){
            cout << n << " ";

            if(i%2==1){
                for(ll k=1; k<=n; k++) cout << i+1 << " " << k << " ";
            }
            else{
                for(ll k=1; k<=n; k++) cout << i+1 << " " << n+1-k << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
