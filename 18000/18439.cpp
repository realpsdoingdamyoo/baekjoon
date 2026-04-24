#define private public
#include <bitset>
#undef private

#include <bits/stdc++.h>
#include <x86intrin.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
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

template<size_t _Nw> void _M_do_sub(_Base_bitset<_Nw>& A, const _Base_bitset<_Nw>& B) {
	for (int i = 0, c = 0; i < _Nw; i++) c = _subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*) & A._M_w[i]);
}
template<> void _M_do_sub(_Base_bitset<1>& A, const _Base_bitset<1>& B) { A._M_w -= B._M_w; }
template<size_t _Nb> bitset<_Nb>& operator-=(bitset<_Nb>& A, const bitset<_Nb>& B) { return _M_do_sub(A, B), A; }
template<size_t _Nb> inline bitset<_Nb> operator-(const bitset<_Nb>& A, const bitset<_Nb>& B) { bitset<_Nb> C(A); return C -= B; }

template<size_t sz = 50'000>
int LCS(const string& a, const string& b) {
    bitset<sz> D, x, S[26];
    for (int i = 0; i < b.size(); i++) S[b[i] - 'A'][i] = 1;
    for (int i = 0; i < a.size(); i++) {
        x = S[a[i] - 'A'] | D; D <<= 1, D[0] = 1;
        D = x & (x ^ (x - D));
    }
    return D.count();
}

const ll sz=50000;
typedef bitset<sz> B;

ll lcs(string s, string p){
    ll n=s.size(), m=p.size();
    B T, X, Y, S[26];
    forf(i, 0, m) S[p[i]-'A'][i]=1;
    forf(i, 0, n){
        X=S[s[i]-'A']|T;
        Y=(T<<1); Y[0]=1;
        T=X&~(X-Y);
    }
    ll ans=0;
    forf(i, 0, m) ans+=T[i];
    return ans;
}

int main() {
    fastio;
    string a, b; cin >> a >> b;
    cout << LCS(a, b);
}
