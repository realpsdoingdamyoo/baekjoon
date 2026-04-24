#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, a[303030], b[303030];

int even(int k){
    static int a1 = 0, a2 = 0, A = 0;
    int range = n-k;
    int l = range/2, r = (n-range+1) + range/2;
    if(!a1){
        a1 = l; a2 = r;
        for(int i=a1; i<=a2; i++) A = max(A, a[i]);
    }
    while(l < a1) A = max(A, a[--a1]);
    while(a2 < r) A = max(A, a[++a2]);
    return A;
}

int odd(int k){
    static int b1 = 0, b2 = 0, B = 0;
    int range = n-k;
    int l = range/2, r = (n-range) + range/2;
    if(!b1){
        b1 = l; b2 = r;
        for(int i=b1; i<=b2; i++) B = max(B, b[i]);
    }
    while(l < b1) B = max(B, b[--b1]);
    while(b2 < r) B = max(B, b[++b2]);
    return B;
}

inline int f(int k){
    int range = n - k;
    if(range == 1) return *max_element(a+1, a+n+1);
    if(range & 1) return odd(k+1);
    else return even(k);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; for(int i=1; i<=n; i++) cin >> a[i], b[i-1] = min(a[i-1], a[i]);
    for(int i=0; i<n; i++) cout << f(i) << " ";
}
///////////////////////////////////////////////////
