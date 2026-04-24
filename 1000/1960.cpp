#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];

bool cmp(array<int, 2> a, array<int, 2> b){
    return a[0]>b[0];
}

int pan[501][501];

int main(){
    fastio;
    int n; cin >> n;
    vi v(n); vcin;
    vector<array<int, 2>> h(n);
    for(int i=0; i<n; i++) {cin >> h[i][0]; h[i][1]=i;}
    for(int i=0; i<n; i++){
        sort(h.begin(), h.end(), cmp);
        for(int j=0; j<v[i]; j++){
            pan[i][h[j][1]]=1;
            h[j][0]--;
            if(h[j][0]<0){
                cout << "-1";
                return 0;
            }
        }
    }
    sort(h.begin(), h.end(), cmp);
    if(h[0][0]>0){
        cout << "-1";
        return 0;
    }

    cout << "1\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << pan[i][j];
        cout << "\n";
    }
    return 0;
}
