#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int mm=10000000, n;

vector<int> door;

void bdfs(int th, int a, int b, int s){
    if(th==n) {mm=min(mm, s); return;}
    bdfs(th+1, door[th], b, s+abs(door[th]-a));
    bdfs(th+1, a, door[th], s+abs(door[th]-b));
}

int main(){
    fastio;
    int w, l, r;
    cin >> w >> l >> r >> n;
    for(int i=0; i<n; i++){int k; cin >>k; door.push_back(k);}
    bdfs(0, l, r, 0);
    cout << mm;
    return 0;
}
