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

typedef unsigned __int128 u;

const int us=128, sz=24;

struct B{
    u v[sz]={};
};

B one;

bool IDX(B& b, ll idx){
    ll j=idx&127;
    return b.v[idx>>7]>>j&1;
}

void SET(B& b, ll idx, ll val){
    ll j=idx&127;
    if(val) b.v[idx>>7]|=(u)1<<j;
    else b.v[idx>>7]&=~((u)1<<j);
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
    if(s.length()>p.length()) swap(s, p);
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

string LCSDP(string s, string p){
    ll n=s.length(), m=p.length();
    vvi dp(n); forf(i, 0, n) dp[i].resize(m);
    forf(i, 0, n){
        forf(j, 0, m){
            if(i) dp[i][j]=max(dp[i][j], dp[i-1][j]);
            if(j) dp[i][j]=max(dp[i][j], dp[i][j-1]);
            if(s[i]==p[j]) dp[i][j]=max(dp[i][j], (i*j)?(dp[i-1][j-1]+1):1);
        }
    }

    ll x=n-1, y=m-1;


    string ret;
    while(x>=0 && y>=0){
        if(s[x]==p[y]){ret+=s[x]; x--; y--;}
        else if(x>0 && dp[x-1][y]==dp[x][y]) x--;
        else y--;
    }
    reverse(all(ret));

    return ret;
}


void solve(ll t){
    string s; cin >> s;

    ll n=s.length();
    ll len=-1, leni=0;

    if(n==1){
        cout << "Case #" << t << ": 0\n";
        return;
    }

    forf(j, 0, 700){
        ll i=rand()%(n-1)+1;
        ll lcs=LCS(s.substr(0, i), s.substr(i, n-i));
        if(len<lcs){len=lcs; leni=i;}
    }

    for(ll i=max(1, leni-130); i<min(n, leni+130); i++){
        ll lcs=LCS(s.substr(0, i), s.substr(i, n-i));
        if(len<lcs){len=lcs; leni=i;}
    }

    cout << "Case #" << t << ": " << len*2 << "\n";
    if(len){
        string lcs=LCSDP(s.substr(0, leni), s.substr(leni, n-leni));
        cout << lcs << lcs << "\n";
    }

}


void rsolve(ll t){
    string s; cin >> s;

    ll n=s.length();
    ll len=-1, leni=0;

    if(n==1){
        cout << "Case #" << t << ": 0\n";
        return;
    }

    forf(i, 1, n){
        ll lcs=LCS(s.substr(0, i), s.substr(i, n-i));
        if(len<lcs){len=lcs; leni=i;}
    }

    cout << "Case #" << t << ": " << len*2 << "\n";
    if(len){
        string lcs=LCSDP(s.substr(0, leni), s.substr(leni, n-leni));
        cout << lcs << lcs << "\n";
    }

}

int main(){
    fastio;
    srand(time(0));

    ll T=1; cin >> T;
    forf(i, 1, T+1) solve(i);

    return 0;
}
