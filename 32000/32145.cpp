#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

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
    return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])<0;
}

int main() {
    fastio;

    ll n, nn; cin >> n; nn=n;
    if(n==1){cout << "0\n"; return 0;}
    vector<array<ll, 2>> v, boloc;
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
    if(j==0){
        cout << nn-1 << "\n";
        return 0;
    }


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
    //for(ll i=0; i<boloc.size(); i++) cout <<boloc[i][0] << " " << boloc[i][1] << endl;
    //cout << boloc.size() << "\n";
    cout << nn+(nn*2-boloc.size()-2)-1 << "\n";


    return 0;
}
