#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<int> ga;
bool prd;
int n;

bool isok(int lst){
    for(int l=1; l<=lst/2; l++){
        int c=0;
        for(int i=0; i<l; i++){
            if(ga[lst-1-i]!=ga[lst-l-i-1]) {c++; break;}
        }
        if(!c) return false;
    }
    return true;
}

void bdfs(int k){
    if(prd) return;
    if(k==n){
        for(int i=0; i<n; i++) cout << ga[i];
        prd=true;
    }
    for(int i=1; i<=3; i++){
        if(k && i==ga[k-1]) continue;
        ga.push_back(i);
        if(isok(k+1)) bdfs(k+1);
        ga.pop_back();
    }
}

int main(){
    fastio;
    cin >> n;
    bdfs(0);
    return 0;
}
