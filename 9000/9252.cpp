#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
    V<u> v;
    B(ll s=sz){
        v.resize(s/us+1, 0);
    }
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
    B ret=a;
    u cry=0;

    forf(i, 0, a.v.size()){
        ret.v[i]=a.v[i]+cry;
        if(a.v[i]>ret.v[i]) cry=1;
        ret.v[i]+=b.v[i];
        if(b.v[i]>ret.v[i]) cry=1;
    }
    return ret;
}

B NOT(B a){
    forf(i, 0, a.v.size()){
        a.v[i]=~a.v[i];
    }
    return a;
}

B MINUS(B a, B b){
    B ret=a;
    u brw=0;

    forf(i, 0, a.v.size()){
        ret.v[i]=a.v[i]-b.v[i]-brw;
        brw=(a.v[i]<b.v[i]+brw)?1:0;
    }
    return ret;
}

B OR(B a, B b){
    forf(i, 0, a.v.size()) a.v[i]|=b.v[i];
    return a;
}

B AND(B a, B b){
    forf(i, 0, a.v.size()) a.v[i]&=b.v[i];
    return a;
}

B SHIFT(B a, ll s){
    B ret=a;
    forf(i, 0, a.v.size()){
        ret.v[i]=a.v[i]<<s;
        if(i) ret.v[i]|=a.v[i-1]>>(us-s);
    }
    return ret;
}

vi arr(string s, string p){
    ll n=s.length(), m=p.length();
    ll L=max(n, m);

    V<B> S(26, B(L));
    forf(i, 0, m) SET(S[p[i]-'A'], i, 1);
    B nwone(L);
    one=nwone;
    SET(one, 0, 1);


    B T(L);

    forf(i, 0, n){
        B X=OR(S[s[i]-'A'], T);
        B Y=OR(SHIFT(T, 1), one);
        T=AND(X, NOT(MINUS(X, Y)));
    }

    vi ret(p.length()+1);

    forf(i, 1, p.length()+1) ret[i]=ret[i-1]+IDX(T, i-1);

    return ret;
}

string hir(string s, string p){
    if(p.length()*s.length()==0) return "";
    if(p.length()==1 || s.length()==1){
        for(char a : s){
            for(char b : p){
                string ret; ret+=a;
                if(a==b) return ret;
            }
        }
        return "";
    }

    string s1, s2;
    ll n=s.length(), m=p.length();
    s1=s.substr(0, n/2);
    s2=s.substr(n/2, n-n/2);

    vi c1, c2;
    c1=arr(s1, p);
    reverse(all(p)); reverse(all(s2));
    c2=arr(s2, p); reverse(all(c2)); reverse(all(p));

    ll mx=0;
    forf(i, 0, m+1) mx=max(mx, c1[i]+c2[i]);
    forf(i, 0, m+1){
        if(c1[i]+c2[i]==mx){
            return hir(s.substr(0, n/2), p.substr(0, i))+hir(s.substr(n/2, n-n/2), p.substr(i, m-i));
        }
    }
}


int main(){
    fastio;

    string s, p;
    cin >> s >> p;

    string r=hir(s, p);
    cout << r.size() << "\n" << r;

    return 0;
}
