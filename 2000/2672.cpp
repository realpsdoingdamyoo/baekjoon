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

ll n, ans;
V<array<ll, 4>> ps;
vpii segment;

void pressing(vi p){
    sortv(p);
    forf(i, 0, p.size()-1){
        if(p[i]==p[i+1]) continue;
        segment.pb({p[i], p[i+1]-1});
    }
}

const ll X=19;
ll seg[1<<X+1], ssz[1<<X+1], cnt[1<<X+1];
ll prv=-1;

void updatep(ll l, ll r){
    ll s=lower_bound(all(segment), (pii){l, 0})-segment.begin();
    ll e=lower_bound(all(segment), (pii){r+1, 0})-segment.begin()-1;
    s+=1<<X; e+=1<<X;
    ll _s=s>>1, _e=e>>1;

    while(s<=e){
        if(s&1){seg[s]=ssz[s]; cnt[s]++;} s=(s+1)>>1;
        if(~e&1){seg[e]=ssz[e]; cnt[e]++;} e=(e-1)>>1;
    }
    while(_s){
        if(!cnt[_s]) seg[_s]=seg[_s*2]+seg[_s*2+1]; _s>>=1;
        if(!cnt[_e]) seg[_e]=seg[_e*2]+seg[_e*2+1]; _e>>=1;
    }
}
void updatem(ll l, ll r){
    ll s=lower_bound(all(segment), (pii){l, 0})-segment.begin();
    ll e=lower_bound(all(segment), (pii){r+1, 0})-segment.begin()-1;
    s+=1<<X; e+=1<<X;
    ll _s=s>>1, _e=e>>1;

    while(s<=e){
        if(s&1){
            cnt[s]--;
            if(cnt[s]==0){
                if(s>=1<<X) seg[s]=0;
                else seg[s]=seg[s*2]+seg[s*2+1];
            }
        }
        if(~e&1){
            cnt[e]--;
            if(cnt[e]==0){
                if(e>=1<<X) seg[e]=0;
                else seg[e]=seg[e*2]+seg[e*2+1];
            }
        }
        s=(s+1)>>1; e=(e-1)>>1;
    }

    while(_s){
        if(!cnt[_s]) seg[_s]=seg[_s*2]+seg[_s*2+1]; _s>>=1;
        if(!cnt[_e]) seg[_e]=seg[_e*2]+seg[_e*2+1]; _e>>=1;
    }
}

void update(ll y, ll x1, ll x2, ll v){
    ans+=(y-1-prv)*seg[1];
    prv=y-1;
    if(v==1) updatep(x1, x2);
    else updatem(x1, x2);
}

int main(){
    fastio;

    cin >> n;
    vi p;
    forf(i, 0, n){
        lf a, b, c, d;
        cin >> a >> b >> c >> d;

        ll A, B, C, D;
        A=(ll)(a*10); B=(ll)(c*10)+A; C=(ll)(b*10); D=(ll)(d*10)+C;

        ps.pb({C, A, B-1, 1});
        ps.pb({D, A, B-1, -1});
        p.pb(A); p.pb(B);
    }

    sortv(ps);
    pressing(p);

    forf(i, 1<<X, 1<<X+1){
        if(segment.size()<=(i-(1<<X))) break;
        ssz[i]=segment[i-(1<<X)][1]-segment[i-(1<<X)][0]+1;
    }
    forb(i, X, 0) forf(j, 1<<i, 1<<i+1) ssz[j]=ssz[j*2]+ssz[j*2+1];



    for(array<ll, 4> a : ps){
        update(a[0], a[1], a[2], a[3]);
    }
    if(ans%100==0){
        cout << ans/100;
    }
    else{
        printf("%.2f", ans/100.0);
    }


    return 0;
}
