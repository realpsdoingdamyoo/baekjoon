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

char cflip(char x){
    char f[11]="0123459786";
    return f[x-'0'];
}

string sflip(string s){
    string p;
    forf(i, 0, s.length()) p+=cflip(s[s.length()-i-1]);
    return p;
}

bool cmp(string a, string b){
    return a+b>b+a;
}

bool cmp1(string a, string b){
    if(a.length()-b.length()) return a.length()>b.length();
    return a>b;
}

int main() {

    ll n; cin >> n;
    vector<string> v(n);
    forf(i, 0, n){cin >> v[i]; v[i]=sflip(v[i]);}
    sort(v.begin(), v.end(), cmp);
    string big=v[0];
    forf(i, 0, n){
        big=cmp1(big, v[i])?big:v[i];
    }
    string ans; ll c=0;
    forf(i, 0, n){
        ans+=v[i];
        if(v[i]==big && c==0){
            ans+=big; c++;
        }
    }
    cout << sflip(ans);

    fastio;



    return 0;
}
