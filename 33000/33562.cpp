#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef __float128 lf;
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
#define cf cout.flush()

typedef V<string> sp;

void print(sp s){
    forf(i, 0, s.size()){
        cout << s[i];
        if(i!=s.size()-1) cout <<":";
    }
    if(s.size()==0) cout << "None";
    cout <<"\n";
}

V<sp> r(100);

sp down(sp s){
    sp ret;
    forf(i, 0, s.size())
        if(s[i]!="--------") ret.pb(s[i]);
    return ret;
}

ll Xor(string a, string b){
    ll r=0;
    forf(i, 0, 8) r+=!(a[i]=='-' || b[i]=='-');
    return r;
}

ll Xor2(sp a, sp b){
    ll r=0;
    forf(i, 0, min(a.size(), b.size())){
        r+=Xor(a[i], b[i]);
    }
    return r;
}

string mrg(string a, string b){
    string ret;
    forf(i, 0, 8){
        if(a[i]!='-') ret+=a[i];
        else ret+=b[i];
    }
    return ret;
}

sp mrg2(sp a, sp b){
    sp ret;
    forf(i, 0, max(a.size(), b.size())){
        if(a.size()<=i) ret.pb(b[i]);
        else if(b.size()<=i) ret.pb(a[i]);
        else ret.pb(mrg(a[i], b[i]));
    }
    return ret;
}

sp down2(sp s, sp d){
    sp ret;
    forf(i, 0, 4) d.insert(d.begin(), "--------");

    ll idx=s.size()-1;
    while(Xor2(s, d)==0){
        ret=mrg2(s, d);
        if(d[0]!="--------") break;
        d.erase(d.begin());
    }
    while(ret.size()>4) ret.pop_back();

    return ret;
}

array<sp, 2> CUT(sp s){
    array<sp, 2> ret;
    forf(i, 0, s.size()){
        ret[0].pb("----"+s[i].substr(4, 4));
        ret[1].pb(s[i].substr(0, 4)+"----");
    }

    return {down(ret[0]), down(ret[1])};
}

void Q1(ll I, ll J, ll K){
    sp C=r[I];
    r[J].clear(); r[K].clear();
    array<sp, 2> ret=CUT(C);
    r[J]=ret[0]; r[K]=ret[1];
}

sp spin(sp s, ll a){
    sp ret=s;
    forf(i, 0, s.size()){
        forf(j, 0, 8) ret[i][j]=s[i][(j+8-a*2)%8];
    }
    return ret;
}

void Q2(ll I, ll J, ll K){
    sp C=r[I];
    r[J]=spin(C, K);
}

void Q3(ll I, ll J, ll K){
    sp C=r[I], D=r[J];
    r[K].clear();
    if(C.size()==0 || D.size()==0) return;
    sp ret=down2(C, D);

    while(ret.size()>4) ret.pop_back();
    r[K]=ret;
}

void Q4(ll I, ll J, char K){
    sp C=r[I];
    r[J].clear();
    if(C.size()==0) return;
    sp ret=C;
    forf(i, 0, ret.size()){
        forf(j, 0, 4)
            if(ret[i][j*2]!='-') ret[i][j*2+1]=K;
    }
    r[J]=ret;
}


int main(){
    fastio;

    ll n, m; cin >> n >> m;
    forf(i, 0, n){
        string ip; cin >> ip;
        forf(j, 0, (ip.length()+1)/9)
            r[i].pb(ip.substr(j*9, 8));
    }

    while(m--){
        ll a;
        cin >> a;
        ll b, c, d; char e;
        if(a==4){
            cin >> b >> c >> e;
            b--; c--;
            Q4(b, c, e);
        }
        else{
            cin >> b >> c >> d;
            b--; c--; d--;
            if(a==1) Q1(b, c, d);
            else if(a==2) Q2(b, c, d+1);
            else if(a==3) Q3(b, c, d);
        }

    }

    print(r[99]);

    return 0;
}
