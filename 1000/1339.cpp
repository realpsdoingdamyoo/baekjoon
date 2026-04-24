#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main()
{
	fastio;

    int n; cin >> n;
    vi v(26), vv;
    repeat(n){
        string s; cin >> s;
        ll gop=1;
        while(s.length()){
            v[s[s.length()-1]-'A']+=gop;
            gop*=10;
            s=s.substr(0, s.length()-1);
        }
    }

    for(int i=0; i<26; i++){
        if(v[i]) vv.push_back(v[i]);
    }
    sort(vv.begin(), vv.end());
    ll s=0, k=9;
    while(vv.size()){
        s+=vv[vv.size()-1]*k--;
        vv.pop_back();
    }
    cout << s;
    return 0;
}
