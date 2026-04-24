#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
#define vcout; for(int i=0; i<v.size(); i++) cout << v[i] << " ";
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


array<ll, 3> most_left={1000000001, 0, 0};

bool cmp(array<ll, 3> a, array<ll, 3> b){
    return (a[0]-most_left[0])*(b[1]-most_left[1])>(b[0]-most_left[0])*(a[1]-most_left[1]);
}

bool cmp_1(array<ll, 3> a, array<ll, 3> b){
    return abs(a[0]-most_left[0])+abs(a[1]-most_left[1])<abs(b[0]-most_left[0])+abs(b[1]-most_left[1]);
}

bool cmp_2(array<ll, 3> a, array<ll, 3> b){
    return abs(a[0]-most_left[0])+abs(a[1]-most_left[1])>abs(b[0]-most_left[0])+abs(b[1]-most_left[1]);
}


bool scc_zero(array<ll, 3> a, array<ll, 3> b, array<ll, 3> c){
    return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])==0;
}


int main() {
    fastio;
    int t; cin >> t;
    while(t--){
        most_left={1000000001, 0, 0};
        ll n, nn; cin >> n; nn=n;
        if(n==1){cout << "0\n"; return 0;}
        vector<array<ll, 3>> v, boloc;
        for(ll i=0; i<n; i++){
            array<ll, 3> ar;
            cin >> ar[0] >> ar[1]; ar[2]=i;
            if(most_left[0]>ar[0]) most_left=ar;
            else if(most_left[0]==ar[0] && most_left[1]>ar[1]) most_left=ar;
            v.push_back(ar);
        }
        for(ll i=0; i<n; i++){
            if(v[i]==most_left) v.erase(v.begin()+i);
        } n--;
        sort(v.begin(), v.end(), cmp);
        ll i=0;
        while(i < v.size()-1 && scc_zero(most_left, v[0], v[i+1])) i++;
        sort(v.begin(), v.begin()+i+1, cmp_1);

        ll j=v.size()-1;
        while(j>0 && scc_zero(most_left, v[v.size()-1], v[j-1])) j--;
        sort(v.begin()+j, v.end(), cmp_2);

        cout << most_left[2] << " ";
        for(int i=0; i<n; i++) cout <<  v[i][2] << " ";
        cout << "\n";
    }
    return 0;
}
