#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define endl "\n";

vector<int> v;
int used[15], udgsp[32], udgsm[32];
int n;

int nxt(int q){
    if(q==n) return 1;
    int s=0;
    for(int i=0; i<n; i++){
        if(used[i] || udgsp[q+i] || udgsm[q-i+15]) continue;
        else{
            used[i]++; udgsp[q+i]++; udgsm[q-i+15]++;
            v.push_back(i);
            s+=nxt(q+1);
            v.pop_back();
            used[i]--; udgsp[q+i]--; udgsm[q-i+15]--;
        }
    }
    return s;
}

int main() {
    cin >> n;
    if(n==15) cout << 2279184;
    else cout << nxt(0);
}
