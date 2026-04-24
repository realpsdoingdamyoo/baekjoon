#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main() {
    fastio;
    ll s=0, n; cin >> n;
    vector<ll> v(n+1); v[n]=0;
    stack<ll> st;

    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++){
        ll k; cin >>k; v[i]-=k;
    }
    for(int i=0; i<=n; i++){
        if(st.empty()) st.push(v[i]);
        else{
            if(st.top()*v[i]<=0){
                s+=abs(st.top());
                while(!st.empty()) st.pop();
                st.push(v[i]);
            }
            else{
                if(abs(st.top())>abs(v[i])){
                    s+=abs(st.top()-v[i]);
                    st.pop();
                }
                while(!st.empty() && abs(st.top())>abs(v[i])){
                    st.pop();
                }
                st.push(v[i]);
            }
        }
    }
    cout << s << "\n";
    return 0;
}
