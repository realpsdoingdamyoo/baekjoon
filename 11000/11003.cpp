#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    cin.tie(0);

    cout.tie(0);

    ios_base::sync_with_stdio(false);

    int n, l, k; cin >> n >> l;

    priority_queue<int> pq1, pq2;

    vector<int> v(n);

    

    for(int i=0; i<n; i++) cin >> v[i];

    

    for(int i=0; i<n; i++){

         pq1.push(-v[i]);

         if(i>=l) pq2.push(-v[i-l]);

         while(!pq2.empty() && pq1.top()==pq2.top()){

             pq1.pop(); pq2.pop();

         }

         cout << -pq1.top() << " ";

    }

    

    return 0;

}
