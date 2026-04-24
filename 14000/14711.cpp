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
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

V<vpii> lnk;
vi vsd;
vi clr;

bool dfs(ll pnt){
    if(vsd[pnt]) return true;
    vsd[pnt]=1;
    bool ret=true;
    for(pii i : lnk[pnt]){
        if(clr[i[0]]!=2 && clr[i[0]]!=clr[pnt]^i[1]) return false;
        clr[i[0]]=clr[pnt]^i[1];
        ret=ret&&dfs(i[0]);
    }
    return ret;
}

int main(){
    fastio;

    ll n; cin >> n;

    V<string> s(n);
    lnk.resize(n+2); vsd.resize(n+2); clr.resize(n+2);
    forf(i, 0, n+2) clr[i]=2;

    forf(i, 0, n){
        if(i==0) cin >> s[i];
        else forf(j, 0, n) s[i]+='-';
        forf(j, 0, n){
            if(s[i][j]=='-') continue;
            ll st=abs(i-j);
            ll en=min(i+j, 2*n-2-i-j);
            lnk[st].pb({en+2, s[i][j]=='#'});
            lnk[en+2].pb({st, s[i][j]=='#'});
        }
    }

    forf(i, 0, n+2){
        if(vsd[i]) continue;
        clr[i]=0;
        if(!dfs(i)){
            cout << "thinking_face\n";
            return 0;
        }
    }
    forf(j, 0, n) cout << (clr[j]!=clr[j+2]?"#":".");
    cout << "\n";


    forf(i, 1, n){
        forf(j, 0, n){
            ll st=abs(i-j);
            ll en=min(i+j, 2*n-2-i-j);
            cout << (clr[st]!=clr[en+2]?"#":".");
        }
        cout << "\n";
    }


    return 0;
}
