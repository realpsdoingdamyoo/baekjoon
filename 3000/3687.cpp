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
#define sortv(v) sort(v.begin(), v.end())
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

void query_s(ll n){

    if(n==3) cout << "7 ";
    else if(n==4) cout << "4 ";
    else if(n==10) cout << "22 ";
    else{
        if(n%7==1){cout << "10"; n-=8;}
        else if(n%7==2) cout << "1";
        else if(n%7==3) {cout << "200"; n-=17;}
        else if(n%7==4) {cout << "20"; n-=11;}
        else if(n%7==5) cout << "2";
        else if(n%7==6) cout << "6";
        n/=7;
        repeat(n) cout << "8";
        cout << " ";
    }
}

void query_b(ll n){
    if(n%2==1){cout << "7"; n-=3;}
    n/=2;
    repeat(n) cout << "1";
    cout << "\n";
}

int main() {
    fastio;

    ll t; cin >> t;
    repeat(t){
        ll n; cin >> n;
        query_s(n);
        query_b(n);
    }

    return 0;
}
