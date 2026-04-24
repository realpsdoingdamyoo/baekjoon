#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define pb push_back
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll inf=2147483647, linf=9223372036854775807/10;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vi getpi(vi p){
    int m=p.size(), j=0;
    vi pi(m);
    for(int i=1; i<m; i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

vi kmp(vi s, vi p){
    int n=s.size(), m=p.size(), j=0;
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

int main() {
    int n; cin >> n;
    vi s(n), p(n), s1(2*n), p1(n);
    forf(i, 0, n) cin >> s[i];
    sort(s.begin(), s.end());
    forf(i, 0, n){
        s1[i+n]=s1[i]=(s[i]-s[(i+n-1)%n]+360000)%360000;
    }
    forf(i, 0, n) cin >> p[i];
    sort(p.begin(), p.end());
    forf(i, 0, n){
        p1[i]=(p[i]-p[(i+n-1)%n]+360000)%360000;
    }
    vi ans=kmp(s1, p1);
    cout << (ans.size()?"":"im") << "possible";
    return 0;
}
