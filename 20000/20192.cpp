#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(){
    fastio;
    int n, top=1, ans=1; cin >> n;
    bool up = true;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (up) {if (top>a){up = false; ans++;}}
        else {if (top<a) {up = true; ans++;}}
        top=a;
    }
    cout << ceil(log2(ans));
    return 0;
}
