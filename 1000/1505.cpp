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
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vector<vi> light, lighton;
ll n, m, s;

void lflip1(ll x, ll y){
    if(x>=0 && x<n && y>=0 && y<m) lighton[x][y]^=1;
}

void lighton_flip(ll x, ll y){
    s++;
    lflip1(x, y);
    forf(i, 0, 8){
        lflip1(x+dir8[i][0], y+dir8[i][1]);
    }
}

void lons(ll bit){
    lighton=light;
    forf(i, 0, n) if(bit&(1<<i)) lighton_flip(i, 0);
    forf(i, n, n+m-1) if(bit&(1<<i)) lighton_flip(0, i-n+1);
}

bool zero(){
    ll k=0;
    forf(i, 0, n){
        forf(j, 0, m) k+=lighton[i][j];
    }
    return !k;
}

ll bruteforce(ll bit){
    s=0;
    lons(bit);
    forf(i, 1, n){
        forf(j, 1, m){
            if(lighton[i-1][j-1]) lighton_flip(i, j);
        }
    }
    if(zero()) return s;
    else return linf;
}

int main(void) {
    fastio;
    cin >> n >> m;
    light.resize(n);
    forf(i, 0, n){
        string s; cin >> s;
        forf(j, 0, m) light[i].push_back(s[j]=='.');
    }
    ll mn=linf;
    forf(i, 0, (1<<m+n-1)){
        mn=min(bruteforce(i), mn);
    }
    if(mn==linf) cout << "-1\n";
    else cout << mn <<"\n";

    return 0;
}
