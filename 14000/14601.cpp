#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define sortv(v) sort(v.begin(), v.end())
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


ll pan[1000][1000];
ll color=1;

void FILL(ll sz, ll sx, ll sy, ll ex, ll ey, pii mt){
    if(sz==2){
        forf(i, sx, ex+1)
            forf(j, sy, ey+1)
                if(mt[0]!=i || mt[1]!=j) 
                    pan[i][j]=color;
        color++;
        return;
    }
    ll mx=(sx+ex)/2, my=(sy+ey)/2;
    ll c=color++;
    if(sx<=mt[0] && mt[0]<=mx && sy<=mt[1] && mt[1]<=my) FILL(sz/2, sx, sy, mx, my, mt);
    else FILL(sz/2, sx, sy, mx, my, {mx, my});
    
    if(sx<=mt[0] && mt[0]<=mx && my<mt[1] && mt[1]<=ey) FILL(sz/2, sx, my+1, mx, ey, mt);
    else FILL(sz/2, sx, my+1, mx, ey, {mx, my+1});
    
    if(mx<mt[0] && mt[0]<=ex && sy<=mt[1] && mt[1]<=my) FILL(sz/2, mx+1, sy, ex, my, mt);
    else FILL(sz/2, mx+1, sy, ex, my, {mx+1, my});
    
    if(mx<mt[0] && mt[0]<=ex && my<mt[1] && mt[1]<=ey) FILL(sz/2, mx+1, my+1, ex, ey, mt);
    else FILL(sz/2, mx+1, my+1, ex, ey, {mx+1, my+1});
    
    if(!(sx<=mt[0] && mt[0]<=mx && sy<=mt[1] && mt[1]<=my)) pan[mx][my]=c;
    if(!(sx<=mt[0] && mt[0]<=mx && my<mt[1] && mt[1]<=ey)) pan[mx][my+1]=c;
    if(!(mx<mt[0] && mt[0]<=ex && sy<=mt[1] && mt[1]<=my)) pan[mx+1][my]=c;
    if(!(mx<mt[0] && mt[0]<=ex && my<mt[1] && mt[1]<=ey)) pan[mx+1][my+1]=c;
    
    return;
}

int main() {
    fastio;

    ll k; cin >> k;
    pii mt; cin >> mt[0] >> mt[1];
    mt[0]--; mt[1]--;
    pan[mt[0]][mt[1]]=-1;
    FILL(1<<k, 0, 0, (1<<k)-1, (1<<k)-1, mt);
    
    forf(i, 0, 1<<k){
        forf(j, 0, 1<<k) cout << pan[j][(1<<k)-1-i] << " ";
        cout << "\n";
    }
    
    return 0;
}
