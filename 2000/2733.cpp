#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define V vector
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
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}



int main() {
    fastio;

    ll t; cin >> t;
    forf(q, 1, t+1){
        vi v(32768);
        forf(i, 0, 32768) v[i]=0;
        ll poi=0, x=0;
        string s, ans;
        while(1){
            string p; getline(cin, p);
            if(p=="end") break;
            forf(i, 0, p.length()){
                if(p[i]=='%'){
                    p=p.substr(0, i);
                    break;
                }
            }
            s+=p;
        }
        map<ll, ll> par;
        stack<ll> st;
        forf(i, 0, s.length()){
            if(s[i]=='[') st.push(i);
            if(s[i]==']'){
                if(st.empty()) x++;
                else{
                    par[st.top()]=i;
                    par[i]=st.top();
                    st.pop();
                }
            }
        }
        cout << "PROGRAM #" << q << ":\n";
        if(st.size() || x) cout << "COMPILE ERROR\n";
        else{
            forf(i, 0, s.length()){
                if(s[i]=='>') poi=(poi+1)%32768;
                if(s[i]=='<') poi=(poi+32767)%32768;
                if(s[i]=='+') v[poi]=(v[poi]+1)%256;
                if(s[i]=='-') v[poi]=(v[poi]+255)%256;
                if(s[i]=='.') ans+=(char)v[poi];
                if(s[i]=='[' && v[poi]==0) i=par[i];
                if(s[i]==']' && v[poi]!=0) i=par[i];
            }
            cout << ans <<"\n";
        }
    }
    return 0;
}
