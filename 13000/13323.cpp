#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(){
    fastio;
    priority_queue<int> pq;
    int n; cin >> n;
    vi ans(n), arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        pq.push(arr[i]-i); pq.push(arr[i]-i); pq.pop();
        ans[i]=pq.top();
    }
    for(int i=n-2; i>=0; i--) if(ans[i]>ans[i+1]) ans[i]=ans[i+1];
    //for(int i=0; i<n; i++) cout << ans[i]+i << " ";
    ll s=0;
    for(int i=0; i<n; i++) s+=abs(arr[i]-ans[i]-i);
    cout << s << endl;
    return 0;
}
