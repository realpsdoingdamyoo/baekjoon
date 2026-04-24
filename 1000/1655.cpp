#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

priority_queue<int> b, s;

int main() {
    fastio;
	int n; cin >> n;
	for(int i=0; i<n; i++){
        int k; cin >> k;
        if(i==0) s.push(k);
        else if(i%2==0){
            if(k<-b.top()){
                s.push(k);
            }
            else{
                s.push(-b.top());
                b.pop();
                b.push(-k);
            }
        }
        else{
            if(k>s.top()){
                b.push(-k);
            }
            else{
                b.push(-s.top());
                s.pop();
                s.push(k);
            }
        }
        cout << s.top() << "\n";
	}
}
