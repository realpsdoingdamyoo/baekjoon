#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


array<ll, 2> most_left={1000000001, 0};

bool cmp(array<ll, 2> a, array<ll, 2> b){
    return (a[0]-most_left[0])*(b[1]-most_left[1])>(b[0]-most_left[0])*(a[1]-most_left[1]);
}

bool cmp_1(array<ll, 2> a, array<ll, 2> b){
    return abs(a[0]-most_left[0])+abs(a[1]-most_left[1])<abs(b[0]-most_left[0])+abs(b[1]-most_left[1]);
}

bool cmp_2(array<ll, 2> a, array<ll, 2> b){
    return abs(a[0]-most_left[0])+abs(a[1]-most_left[1])>abs(b[0]-most_left[0])+abs(b[1]-most_left[1]);
}


bool scc_zero(array<ll, 2> a, array<ll, 2> b, array<ll, 2> c){
    return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])==0;
}


bool scc(array<ll, 2> a, array<ll, 2> b, array<ll, 2> c){
    return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])<=0;
}

int main() {
    fastio;
    ll t; cin >> t;
    repeat(t){
        most_left={1000000001, 0};
        ll n, nn; cin >> n; nn=n;
        if(n==1){cout << "0\n"; return 0;}
        vpii v, boloc;
        for(ll i=0; i<n; i++){
            array<ll, 2> ar;
            cin >> ar[0] >> ar[1];
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
        sort(v.begin(), v.begin()+i, cmp_1);

        ll j=v.size()-1;
        while(j>0 && scc_zero(most_left, v[v.size()-1], v[j-1])) j--;
        sort(v.begin()+j, v.end(), cmp_2);


        //for(ll i=0; i<v.size(); i++) cout <<v[i][0] << " " << v[i][1] << endl;
        boloc.push_back(most_left);
        for(ll i=0; i<n; i++){
            //cout <<"//" << v[i][0] << " " << v[i][1] << endl;
            if(boloc.size()<=2) boloc.push_back(v[i]);
            else{
                while(boloc.size()>=2){
                    if(!scc(boloc[boloc.size()-2], boloc[boloc.size()-1], v[i])) break;
                    boloc.pop_back();
                }
                boloc.push_back(v[i]);
            }
        }
        if(scc_zero(boloc[boloc.size()-2], boloc[boloc.size()-1], boloc[0])) boloc.pop_back();

        reverse(boloc.begin(), boloc.end());
        cout << boloc.size() << "\n";

        ll mxi=0;
        forf(i, 0, boloc.size()){
            if(boloc[i][1]>boloc[mxi][1]) mxi=i;
            else if(boloc[i][1]==boloc[mxi][1] && boloc[i][0]<boloc[mxi][0]) mxi=i;
        }

        forf(i, mxi, boloc.size()+mxi){
            cout << boloc[i%boloc.size()][0] << " " << boloc[i%boloc.size()][1] << "\n";
        }

    }
    return 0;
}
