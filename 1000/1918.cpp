#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

string CALC2(V<string> v){
    V<string> u=v;
    forf(i, 0, (ll)v.size()-2){
        if(v[i+1]=="*" || v[i+1]=="/"){
            v[i]+=v[i+2]+v[i+1];
            v.erase(v.begin()+i+1);
            v.erase(v.begin()+i+1);
            return CALC2(v);
        }
    }

    forf(i, 0, (ll)v.size()-2){
        if(v[i+1]=="+" || v[i+1]=="-"){
            v[i]+=v[i+2]+v[i+1];
            v.erase(v.begin()+i+1);
            v.erase(v.begin()+i+1);
            return CALC2(v);
        }
    }

    return v[0];
}

string CALC(string s){
    V<string> v;
    forf(i, 0, s.length()){
        if(s[i]=='('){
            ll c=0;
            forf(j, i, s.length()){
                if(s[j]=='(') c++;
                if(s[j]==')') c--;
                if(c==0){
                    v.pb(CALC(s.substr(i+1, j-i-1)));
                    i=j;
                    break;
                }
            }
        }
        else v.pb(s.substr(i, 1));
    }

    return CALC2(v);
}

int main(){
    fastio;

    string s; cin >> s;

    cout << CALC(s);

    return 0;
}
