#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vi a(102), b(102), a_(102), b_(102);

ll query(){
    ll i=101, j=101;

    a_=a;
    forf(i, 0, 102) b_[i]=b[101-i];
    ll mx=0;
    while(i && j){
        if(a_[i]==b_[j]){
            if(a_[i] && b_[j]) mx=max(mx, i+(101-j));
            i--; j--;
        }
        else if(a_[i]>b_[j]){
            if(a_[i] && b_[j]) mx=max(mx, i+(101-j));
            a_[i]-=b_[j];
            j--;
        }
        else{
            if(a_[i] && b_[j]) mx=max(mx, i+(101-j));
            b_[j]-=a_[i];
            i--;
        }
    }
    return mx;
}

int main() {
    fastio;
    ll n; cin >> n;
    repeat(n){
        ll x, y; cin >> x >> y;
        a[x]++; b[y]++;
        cout << query() << "\n";
    }
    return 0;
}
