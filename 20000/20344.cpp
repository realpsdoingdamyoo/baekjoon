#include <bits/stdc++.h>
#define int long long

using namespace std;
#define forf(i, s, e) for(int i = s; i <= e; i++)
#define endl "\n"

struct Seg{
    int arr[1 << 19], sz = 1 << 18; 
    void edit(int f, int x) {
        f += sz; 
        for(arr[f] = max(arr[f], x); f > 1; f >>= 1) 
            arr[f >> 1] = max(arr[f], arr[f ^ 1]);
    }
    int query(int l, int r) {
        int ret = -1e18;
        for(l += sz, r += sz + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) ret = max(ret, arr[l++]);
            if(r & 1) ret = max(ret, arr[--r]);
        }
        return ret; 
    }
} tree, TR;

int N, A[101010], B[101010];
vector <int> X, arr[101010];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr); 

    cin >> N; 

    forf(i, 1, N) 
        cin >> A[i], X.push_back(A[i]); 

    sort(X.begin(), X.end()); 
    X.erase(unique(X.begin(), X.end()), X.end());

    forf(i, 1, N) {
        int idx = lower_bound(X.begin(), X.end(), A[i]) - X.begin() + 1; 
        arr[idx].push_back(i); TR.edit(i, idx); 
    }

    forf(i, 1, N) {
        cin >> B[i]; 
        int idx = lower_bound(X.begin(), X.end(), B[i]) - X.begin(); 
        if(B[i] > X.back() || X[idx] != B[i]) continue; 
        
        B[i] = ++idx; 

        int l = upper_bound(arr[idx].begin(), arr[idx].end(), i) - arr[idx].begin() - 1; 
        int r = lower_bound(arr[idx].begin(), arr[idx].end(), i) - arr[idx].begin(); 

        int tm1 = -1, tm2 = -1;
        if(l >= 0 && TR.query(arr[idx][l], i) == B[i]) 
            tm1 = tree.query(1, arr[idx][l]) + 1; 
        
        if(r < (int) arr[idx].size() && TR.query(i, arr[idx][r]) == B[i]) 
            tm2 = tree.query(1, arr[idx][r]) + 1; 

        if(tm1 != -1) tree.edit(arr[idx][l], tm1); 
        if(tm2 != -1) tree.edit(arr[idx][r], tm2); 
    }

    cout << tree.query(1, N); 
    return 0; 
}
