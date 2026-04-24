#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(){
    fastio;
    int n; cin >> n;
    vi v(n), ans(n); si st;
    for(int i=0; i<n; i++) {cin >> v[i]; ans[i]=-1;}
    for(int i=0; i<n; i++){
        while(!st.empty() && v[st.top()]<v[i]){
            ans[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i=0; i<n; i++) cout << ans[i]<<" ";
}
