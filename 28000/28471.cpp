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
typedef string S;
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
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n, cnt;
V<S> s;
V<V<bool>> vsd;
V<V<bool>> dan;

int main() {
    fastio;

    cin >> n;
    s.resize(n); vsd.resize(n); dan.resize(n);
    queue<pii> q;
    forf(i, 0, n){
        cin >> s[i];
        forf(j, 0, n) if(s[i][j]=='F') q.push({i, j});
    }
    forf(i, 0, n){vsd[i].resize(n); dan[i].resize(n);}
    forf(i, 0, n*n) dan[i/n][i%n]=1;

    while(!q.empty()){
        if(vsd[q.front()[0]][q.front()[1]]){q.pop(); continue;}
        vsd[q.front()[0]][q.front()[1]]=1;
        forf(i, 0, 8){
            ll nx=q.front()[0]+dir8[i][0], ny=q.front()[1]+dir8[i][1];
            if(nx<0 || ny<0 || nx>=n || ny>=n || i==1) continue;
            if(!vsd[nx][ny] && s[nx][ny]=='.'){
                cnt+=dan[nx][ny]; q.push({nx, ny});
                dan[nx][ny]=0;
            }
        }
        q.pop();
    }
    /*forf(i, 0, n){
        forf(j, 0, n) cout << dan[i][j]; cout << "\n";
    }*/

    cout << cnt;

    return 0;
}
