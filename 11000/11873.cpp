#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

const int MAX=1001;

int n, m, pan[MAX+3][MAX+3];

int histo(int bd){
	stack<int> st;
	int maxx=0;
	st.push(0);
	for(int i=1; i<=MAX; i++){
		while(!st.empty() && pan[bd][st.top()]>pan[bd][i]){
			ll hei=pan[bd][st.top()]; st.pop();
			ll wid=i-st.top()-1;

			ll ret=hei*wid;
			maxx=maxx>ret?maxx:ret;
		}
		st.push(i);
	}
	return maxx;
}

int main() {
    while(1){
        cin >> n >> m;
        if((n||m)==0) break;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> pan[i][j];
            }
        }
        for(int i=MAX-1; i>0; i--){
            for(int j=MAX; j>0; j--){
                pan[i][j]*=pan[i+1][j]+1;
            }
        }
        /*for(int i=1; i<=10; i++){
            for(int j=1; j<=10; j++){
                printf("%2d ", pan[i][j]);
            }
            cout << endl;
        }*/
        int maxx=0;
        //for(int i=1; i<=MAX; i++) cout << histo(i) << " ";
        for(int i=1; i<=MAX; i++) maxx=max(maxx, histo(i));
        cout << maxx << endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                pan[i][j]=0;
            }
        }
    }
    return 0;
}
