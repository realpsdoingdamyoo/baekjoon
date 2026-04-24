#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
typedef int ll;
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

string a, b;
ll n, m;
string ans;

void H(ll as, ll ae, ll bs, ll be){
    //cout << a.substr(as, ae-as+1) << "\n";
    //cout << b.substr(bs, be-bs+1) << "\n\n";

    if(as==ae || bs==be){
        forf(i, as, ae+1) forf(j, bs, be+1){
            if(a[i]==b[j]) {ans+=a[i]; return;}
        }
        return;
    }

    ll am=(as+ae)/2;
    vvi sm_dp(2); forf(i, 0, 2) sm_dp[i].resize(be-bs+1);
    forf(i, as, am+1){
        forf(j, bs, be+1){
            if(i+j==as+bs) sm_dp[1][j-bs]=(a[i]==b[j]);
            else if(i==as) sm_dp[1][j-bs]=max((ll)(a[i]==b[j]), sm_dp[1][j-bs-1]);
            else if(j==bs) sm_dp[1][j-bs]=max((ll)(a[i]==b[j]), sm_dp[0][j-bs]);
            else{
                sm_dp[1][j-bs]=max(sm_dp[0][j-bs], sm_dp[1][j-bs-1]);
                sm_dp[1][j-bs]=max(sm_dp[1][j-bs], sm_dp[0][j-bs-1]+(a[i]==b[j]));
            }
        }
        sm_dp[0]=sm_dp[1];
    }
    vvi em_dp(2); forf(i, 0, 2) em_dp[i].resize(be-bs+1);
    forb(i, ae+1, am+1){
        forb(j, be+1, bs){
            if(i==ae && j==be) em_dp[1][j-bs]=(a[i]==b[j]);
            else if(i==ae) em_dp[1][j-bs]=max((ll)(a[i]==b[j]), em_dp[1][j-bs+1]);
            else if(j==be) em_dp[1][j-bs]=max((ll)(a[i]==b[j]), em_dp[0][j-bs]);
            else{
                em_dp[1][j-bs]=max(em_dp[0][j-bs], em_dp[1][j-bs+1]);
                em_dp[1][j-bs]=max(em_dp[1][j-bs], em_dp[0][j-bs+1]+(a[i]==b[j]));
            }
        }
        em_dp[0]=em_dp[1];
    }
    //forf(i, bs, be+1) cout << sm_dp[1][i-bs] << " "; cout << "\n";
    //forf(i, bs, be+1) cout << em_dp[1][i-bs] << " "; cout << "\n";

    vi sm_, em_;
    sm_.pb(0); for(ll i : sm_dp[1]) sm_.pb(i); sm_.pb(0);
    em_.pb(0); for(ll i : em_dp[1]) em_.pb(i); em_.pb(0);

    //for(ll i : sm_) cout << i << " "; cout <<"\n";
    //for(ll i : em_) cout << i << " "; cout <<"\n";
    //cout << "\n\n";
    ll smx=0, I=0;
    forf(i, 0, sm_.size()-1) if(smx<sm_[i]+em_[i+1]){I=i; smx=sm_[i]+em_[i+1];}
    sm_dp.clear(); em_dp.clear(); sm_.clear(); em_.clear();

    H(as, am, bs, bs+I-1);
    H(am+1, ae, bs+I, be);
}

int main() {
    fastio;

    cin >> a >> b;
    n=a.length(); m=b.length();

    H(0, n-1, 0, m-1);

    cout << ans.length() << "\n" << ans;


    return 0;
}
