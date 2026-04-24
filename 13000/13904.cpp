#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool cmp(pii a, pii b){
	if(a.first>b.first) return true;
	if(a.first==b.first && a.second>b.second) return true;
	return false;
}

int main(){
	vector<pii> p;
	int n, sum=0; cin >> n;
	for(int i=0; i<n; i++){
		int d, w; cin >> d >> w;
		p.push_back({d, w});
	} 
	
	sort(p.begin(), p.end(), cmp);
	for(int i=1000; i>0; i--){
		int ind=0, max=0, maxind=0;
		while(p[ind].first>=i){
			if(max<p[ind].second){
				maxind=ind; max=p[ind].second;
			}
			ind++;
		}
		if(max){
			sum+=max;
			p[maxind]={0,0};
			sort(p.begin(), p.end(), cmp);
		}
	}
	cout << sum;
    return 0;
}
