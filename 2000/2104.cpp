#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

ll n;
ll h[100002], mx;
ll njh[100002];
stack<ll> st;

int main() {
    fastio;
    cin >> n;
    for(int i=1; i<=n; i++){cin >> h[i]; njh[i]=njh[i-1]+h[i];}
    st.push(0);
    for(int i=1; i<=n+1; i++){
        while(!st.empty() && h[st.top()]>h[i]){
            ll hei=h[st.top()]; st.pop();
            ll wid=njh[i-1]-njh[st.top()];

            ll ret=hei*wid;
            mx=mx>ret?mx:ret;
        }
        st.push(i);
    }
    cout << mx << endl;
    return 0;
}
