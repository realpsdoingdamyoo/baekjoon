#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<vi> ans[10];
vector<int> v;
int n, m;

void making(int ind){
    if(ind<=1){
        if(ind<=0) return;
        vi apv;
        apv.push_back(v[0]);
        ans[1].push_back(apv);
        return;
    }

    making(ind-1);
    for(int i=0; i<ans[ind-1].size(); i++){
        if(i%2==1){
            for(int j=0; j<ind; j++){
                vi apv=ans[ind-1][i];
                apv.insert(apv.begin()+j, v[ind-1]);
                ans[ind].push_back(apv);
            }
        }
        else{
            for(int j=ind-1; j>=0; j--){
                vi apv=ans[ind-1][i];
                apv.insert(apv.begin()+j, v[ind-1]);
                ans[ind].push_back(apv);
            }
        }
    }
}

void printing(int ii){
    /*for(int j=0; j<s; j++){
        if(ans[s][i][j]==s) cout << "#";
        else cout << ans[s][i][j];
    }*/
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i%2==0){
                if(ans[n*m][ii][i*m+j]==n*m) cout <<"#";
                else cout << ans[n*m][ii][i*m+j];
            }
            else{
                if(ans[n*m][ii][i*m+m-j-1]==n*m) cout << "#";
                else cout << ans[n*m][ii][i*m+m-j-1];
            }
        }
        cout << "\n";
    }
}

int main() {
    fastio;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i%2==0) v.push_back(i*m+j+1);
            else v.push_back(i*m+m-j);
        }
    }
    //for(int i=0; i<n*m; i++) cout << v[i] << " "; cout << "\n\n\n";

    making(n*m);
    for(int i=0; i<ans[n*m].size(); i++) printing(i);
    return 0;
}
