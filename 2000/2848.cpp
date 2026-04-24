#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef string S;
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
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

void solve(){
    ll n, c=0; cin >> n;
    vi as(26), ae[26], ap(26);
    V<string> v(n);
    forf(i, 0, n){
        cin >> v[i];
        for(char p : v[i]){c+=!ap[p-'a']; ap[p-'a']=1;}
    }
    forf(i, 0, n-1){
        forf(j, 0, min(v[i].length(), v[i+1].length())){
            if(v[i][j]!=v[i+1][j]){
                as[v[i][j]-'a']++;
                ae[v[i+1][j]-'a'].pb(v[i][j]-'a');
                break;
            }
            if(j==v[i+1].length()-1 && v[i].length()>v[i+1].length()){
                cout << "!\n";
                return;
            }
        }
    }
    ll chk=0;
    string seq;
    queue<ll> q;
    forf(i, 0, 26) if(ap[i] && as[i]==0) q.push(i);

    while(q.size()){
        if(q.size()>=2) chk=1;
        ll t=q.front(); q.pop();
        seq+=(char)('a'+t);
        for(ll i : ae[t]){
            as[i]--;
            if(as[i]==0) q.push(i);
        }

    }
    if(seq.size()!=c) cout << "!\n";
    else if(chk==1) cout << "?\n";
    else{
        reverse(all(seq));
        cout << seq << "\n";
    }
}


int main(){
    fastio;

    solve();

    return 0;
}
