#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n; string s, ans;

bool two(ll len){
    ll H[2]={};
    ll M[2]={mod, MOD};
    ll pw[2]={1, 1};
    map<ll, ll> hh;
    
    forf(i, 0, len){
        forf(j, 0, 2){H[j]=(H[j]*26+s[i])%M[j]; pw[j]=pw[j]*26%M[j];}
    }
    hh[H[0]<<30|H[1]]++;
    //cout << (H[0]<<30|H[1]) << " ";
    
    forf(i, len, n){
        forf(j, 0, 2) H[j]=(H[j]*26+s[i]-s[i-len]*pw[j]%M[j]+M[j])%M[j];
        hh[H[0]<<30|H[1]]++;
        //cout << (H[0]<<30|H[1]) << " ";
    }
    
    H[0]=H[1]=0; pw[0]=pw[1]=1;
    
    forf(i, 0, len){
        forf(j, 0, 2){H[j]=(H[j]*26+s[i])%M[j]; pw[j]=pw[j]*26%M[j];}
    }
    if(hh[H[0]<<30|H[1]]==1){ans=s.substr(0, len); return true;}
    
    forf(i, len, n){
        forf(j, 0, 2) H[j]=(H[j]*26+s[i]-s[i-len]*pw[j]%M[j]+M[j])%M[j];
        if(hh[H[0]<<30|H[1]]==1){ans=s.substr(i-len+1, len); return true;}
    }
    
    return false;
}

int main() {
    fastio;
    cin >> s;
    n=s.length();
    
    ll S=1, E=n;
    while(S<=E){
        ll M=(S+E)/2;
        if(two(M)) E=M-1;
        else S=M+1;
        //cout << M << " " << two(M) << "\n\n";
    }
    two(E-1);
    cout << ans;

    return 0;
}
