#include <bits/stdc++.h>    
using namespace std;    
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int arr[1005], n, ccc;
vpii ans;

vpii check(){
	vpii points;
	for(int i=1; i<n+2; i++){
		if(abs(arr[i]-arr[i-1])>1){
			points.push_back({i-1, i});
		}
	}
	for(int i=1; i<n+1; i++){
		if(!((arr[i-1]<arr[i] && arr[i]<arr[i+1]) || (arr[i-1]>arr[i] && arr[i]>arr[i+1]))){
			points.push_back({i, i});
		}
	}
	return points;
}

void bt(int dep){
	if(ccc) return;
	vpii cse=check();
	if(cse.size()==0){
		for(int i=0; i<ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
		for(int i=0; i<3-ans.size(); i++) cout << "1 1" << endl;
		ccc++; return;
	}
	if(dep==3) return;
	for(int ii=0; ii<cse.size(); ii++){
		for(int jj=ii+1; jj<cse.size(); jj++){
			int i=cse[ii].second;
			int j=cse[jj].first;
			for(int k=0; k<(j-i)/2+1; k++){
				int t=arr[i+k];
				arr[i+k]=arr[j-k];
				arr[j-k]=t;
			}
			ans.push_back({i, j});
			bt(dep+1);
			for(int k=0; k<(j-i)/2+1; k++){
				int t=arr[i+k];
				arr[i+k]=arr[j-k];
				arr[j-k]=t;
			}
			ans.pop_back();
		}
	}
	
}



int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i]; arr[n+1]=n+1;
	bt(0);
	
    return 0;
}
