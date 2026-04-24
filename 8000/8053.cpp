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
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


vi getpi(string p){
    int m=p.length(), j=0;
    vi pi(m);
    for(int i=1; i<m; i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

vi kmp(string s, string p){
    int n=s.length(), m=p.length(), j=0;
    vi pi=getpi(p);
    vi ans;
    for(int i=0; i<n; i++){
        while(j>0 && s[i]!=p[j]) j=pi[j-1];
        if(s[i]==p[j]){
            if(j==m-1) {ans.push_back(i-j); j=pi[j];}
            else j++;
        }
    }
    return ans;
}

vector<string> v;
ll n;

bool isok(ll len){
    string p;
    bool ret=false;
    forf(i, 0, v[0].length()-len+1){
        p=v[0].substr(i, len);
        bool flag=true;
        forf(j, 1, n){
            flag=flag&&kmp(v[j], p).size();
        }
        ret=ret||flag;
    }
    return ret;
}

ll YT(){
    ll ch[26]={};
    forf(i, 0, n){
        forf(j, 0, v[i].length()) ch[v[i][j]-'a']|=(1<<i);
    }
    bool flag=false;
    forf(i, 0, 26) flag=flag||(ch[i]==(1<<n)-1);
    if(!flag) return 0;

    ll s=1, e=v[0].length();

    while(s<=e){
        ll m=(s+e)/2;
        if(isok(m)) s=m+1;
        else e=m-1;
    }

    return e;
}


int main() {
    fastio;

    cin >> n;
    v.resize(n); vcin;

    cout << YT();

    return 0;
}
