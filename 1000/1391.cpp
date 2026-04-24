#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(){
    int t; cin >> t;
    while(t--){
        vector<array<int, 2>> link[2];
        int n, prev, nw;
        cin >> n; cin >> prev;
        for(int i=1; i<n; i++){
            cin >> nw;
            link[i%2].push_back({min(prev, nw), max(prev, nw)});
            prev=nw;
        }
        sort(link[0].begin(), link[0].end());
        sort(link[1].begin(), link[1].end());
        int ch=0;
        for(int j=0; j<2; j++){
            stack<array<int, 2>> st;
            for(int i=0; i<link[j].size(); i++){
                if(st.empty()){st.push(link[j][i]); continue;}

                if(st.top()[1]<link[j][i][0]){
                    while(!st.empty()) st.pop();
                    st.push(link[j][i]);
                }
                else{
                    if(st.top()[1]<link[j][i][1]) ch++;
                    st.push(link[j][i]);
                }
            }
        }
        cout << (!ch?"YES\n":"NO\n");
    }
    return 0;
}
