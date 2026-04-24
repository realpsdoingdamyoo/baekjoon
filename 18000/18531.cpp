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

string s1, s2, s3;
ll mt=inf;

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



int main() {
    fastio;

    cin >> s1 >> s2 >> s3; s3+=s3;
    ll n=s1.length();
    forf(i, 0, n){
        ll chk=0;
        forf(j, 0, n) chk+=(s1[j]==s2[j]);
        if(!chk){
            string sf;
            forf(j, 0, n) sf+=('A'+'B'+'C')-s1[j]-s2[j];
            vi kp=kmp(s3, sf);
            //cout << s1 << " " << s2 << " ";
            for(ll j : kp){
                ll jp=(n-j)%n; //cout << "(" << j << "_";
                ll tn=min(i, n-i)+min(jp, n-jp); //cout << min(i, n-i)+min(jp, n-jp) << " ";
                tn=min(tn, min(i, n-i)+min(abs(jp-i), n-abs(jp-i))); //cout << min(i, n-i)+min(abs(jp-i), n-abs(jp-i)) << " ";
                tn=min(tn, min(jp, n-jp)+min(abs(jp-i), n-abs(jp-i))); //cout << min(jp, n-jp)+min(abs(jp-i), n-abs(jp-i));
                mt=min(mt, tn);
                //cout << ")";
            }
            //cout << mt << "\n";
        }

        s2=s2[n-1]+s2.substr(0, n-1);
    }
    cout << (mt==inf?-1:mt) << "\n";
    return 0;
}
