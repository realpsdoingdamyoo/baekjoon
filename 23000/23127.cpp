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
#define cf; cout.flush();

ll n;
V<string> abcset={"BA", "CA", "AB", "CB", "BC", "AC"};

string ABABA_s(ll len, char a, char b){
    string s; s+=a;
    forf(i, 0, len){
        s+=b; s+=a;
    }
    return s;
}

bool ifin(string s, string a){
    forf(i, 0, s.length()){
        if(s[i]!=a[i] && a[i]!='?') return false;
    }
    return true;
}

bool ifin2(string s, string a){
    forf(i, 0, s.length()){
        if(s[i]!=a[i] && a[i]!='?' && s[i]!='?') return false;
    }
    return true;
}

ll ABABA(string a, string b){
    ll ret=1;
    forf(i, 0, b.length()/2+1){
        if(b[i*2]==a[0] || b[i*2]==a[1]) return 0;
        else b[i*2]='B'*3-a[0]-a[1];
    }
    forf(i, 0, b.length()/2){
        if(b[i*2+1]==b[0]) return 0;
        else if(b[i*2+1]=='?') ret=ret*2%MOD;
    }
    //cout << a << " " << b << " " << ret << "\n";
    return ret;
}

string mrg(string a, string b){
    forf(i, 0, a.length()){
        if(a[i]=='?' && b[i]!='?') a[i]=b[i];
    }
    return a;
}

ll ABABC(string a, string b){
    ll ret=0;
    char mid=a[1];
    char fr=(a[1]+2-'A')%3+'A', ba=(a[1]+1-'A')%3+'A';

    forf(i, 0, n+1) if(a[i*2]==mid || b[i*2]==mid) return 0;

    vi njhaf(n+2), njhab(n+2), njhbf(n+2), njhbb(n+2);

    forf(i, 0, n+1){
        njhaf[i+1]=njhaf[i]+(a[i*2]==fr);
        njhab[i+1]=njhab[i]+(a[i*2]==ba);
        njhbf[i+1]=njhbf[i]+(b[i*2]==fr);
        njhbb[i+1]=njhbb[i]+(b[i*2]==ba);
    }

    forf(i, 1, n+1){
        if(njhab[i]-njhab[0]==0 && njhaf[n+1]-njhaf[i]==0 && njhbf[i]-njhbf[0]==0 && njhbb[n+1]-njhbb[i]==0) ret++;
        if(njhaf[i]-njhaf[0]==0 && njhab[n+1]-njhab[i]==0 && njhbb[i]-njhbb[0]==0 && njhbf[n+1]-njhbf[i]==0) ret++;
    }
    return ret;
}

void solve(){
    cin >> n;
    string a, b; cin >> a >> b;
    ll ret=0;

    forf(i, 0, 6){
        if(ifin(ABABA_s(n, abcset[i][0], abcset[i][1]), a))
            ret+=ABABA(ABABA_s(n, abcset[i][0], abcset[i][1]), b);
        if(ifin(ABABA_s(n, abcset[i][0], abcset[i][1]), b))
            ret+=ABABA(ABABA_s(n, abcset[i][0], abcset[i][1]), a);
    }
    forf(i, 0, 3){
        if(ifin(ABABA_s(n, abcset[i*2][0], abcset[i*2][1]), a) && ifin(ABABA_s(n, abcset[i*2+1][0], abcset[i*2+1][1]), b)) ret=(ret+MOD-1)%MOD;
        if(ifin(ABABA_s(n, abcset[i*2][0], abcset[i*2][1]), b) && ifin(ABABA_s(n, abcset[i*2+1][0], abcset[i*2+1][1]), a)) ret=(ret+MOD-1)%MOD;
    }

    forf(i, 0, 3){
        string QAQ=ABABA_s(n, '?', (char)('A'+i));
        if(ifin2(QAQ, a) && ifin2(QAQ, b))
            ret+=ABABC(mrg(QAQ, a), mrg(QAQ, b));
    }

    cout << ret%MOD << "\n";
}

int main() {
    fastio;

    ll t; cin >> t;
    while(t--) solve();

    return 0;
 }
