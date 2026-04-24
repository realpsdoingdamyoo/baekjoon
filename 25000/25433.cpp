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

typedef uint64_t u;

const int us=64, sz=800;

struct B{
    u v[sz]={};
};

B one;

bool IDX(B& b, ll idx){
    ll j=idx%us;
    return b.v[idx/us]>>j&1;
}

void SET(B& b, ll idx, ll val){
    ll j=idx%us;
    if(val) b.v[idx/us]|=1LL<<j;
    else b.v[idx/us]&=~1LL<<j;
}

B PLUS(B a, B b){
    B ret;
    u cry=0;

    forf(i, 0, sz){
        ret.v[i]=a.v[i]+cry;
        if(a.v[i]>ret.v[i]) cry=1;
        ret.v[i]+=b.v[i];
        if(b.v[i]>ret.v[i]) cry=1;
    }
    return ret;
}

B NOT(B a){
    forf(i, 0, sz){
        a.v[i]=~a.v[i];
    }
    return a;
}

B MINUS(B a, B b){
    B ret;
    u brw=0;

    forf(i, 0, sz){
        ret.v[i]=a.v[i]-b.v[i]-brw;
        brw=(a.v[i]<b.v[i]+brw)?1:0;
    }
    return ret;
}

B OR(B a, B b){
    forf(i, 0, sz) a.v[i]|=b.v[i];
    return a;
}

B AND(B a, B b){
    forf(i, 0, sz) a.v[i]&=b.v[i];
    return a;
}

B SHIFT(B a, ll s){
    B ret;
    forf(i, 0, sz){
        ret.v[i]=a.v[i]<<s;
        if(i) ret.v[i]|=a.v[i-1]>>(us-s);
    }
    return ret;
}

ll LCS(string s, string p){
    ll n=s.length(), m=p.length();

    B S[26];
    forf(i, 0, m) SET(S[p[i]-'a'], i, 1);
    SET(one, 0, 1);

    B T;

    forf(i, 0, n){
        B X=OR(S[s[i]-'a'], T);
        B Y=OR(SHIFT(T, 1), one);
        T=AND(X, NOT(MINUS(X, Y)));
    }

    ll ans=0;
    forf(i, 0, m) ans+=IDX(T, i);
    return ans;
}

int main(){
    //fastio;
    string s, p; cin >> s >> p;
    char a, b; cin >> a >> b;

    string ns1, ns2, np1, np2;
    ll chk=0;
    for(char c : s){
        if(c==a) chk=1;
        if(c==b || c==a) continue;
        if(chk) ns1+=c;
        else ns2+=c;
    }
    chk=0;
    for(char c : p){
        if(c==a) chk=1;
        if(c==b || c==a) continue;
        if(chk) np1+=c;
        else np2+=c;
    }

    ll len=LCS(ns1, np1)+1+LCS(ns2, np2);

    while(1){
        if(len<2){
            len=-1;
            break;
        }
        ll cc=0;
        forf(i, 2, 300){
            if(len!=i && len%i==0){len--; break;}
            if(i==299){cc++; break;}
        }
        if(cc) break;
    }

    cout << len;

    return 0;
}
