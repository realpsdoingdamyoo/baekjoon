#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int fi[3030][3030];

signed main(){
    fastio;

    int n, m; cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++)
            fi[i][j]=(s[j]=='R');
    }

    for(int i=1; i<n; i++) for(int j=0; j<m; j++)
        fi[i][j]*=fi[i-1][j]+1;

    int ret=0;
    for(int i=0; i<n; i++){
        vector<array<int, 2>> st; st.push_back({0, 0});
        for(int j=0; j<=m; j++){
            array<int, 2> p={fi[i][j], 1};
            if(st.back()[0]<=p[0]){
                st.push_back(p);
            }
            else{
                while(st.back()[0]>p[0]){
                    int s=st.size();
                    if(st[s-2][0]<p[0]){
                        ret+=(st[s-1][0]-p[0])*st[s-1][1]*(st[s-1][1]+1)/2;
                        p[1]+=st[s-1][1];
                        st.pop_back();
                    }
                    else{
                        ret+=(st[s-1][0]-st[s-2][0])*st[s-1][1]*(st[s-1][1]+1)/2;
                        st[s-2][1]+=st[s-1][1];
                        st.pop_back();
                    }
                }
                st.push_back(p);
            }
        }
    }
    cout << ret;



    return 0;
}
