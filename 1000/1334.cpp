#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string rvso(string a){
	for(int i=a.size()-2; i>=0; i--) a+=a[i];
	return a;
}
string rvse(string a){
	for(int i=a.size()-1; i>=0; i--) a+=a[i];
	return a;
}

int main(){
	string n, nine="9";
	cin >> n;
	if("9"+n==n+"9"){cout << "1"; for(int i=0; i<n.size()-1; i++) cout << "0"; cout << "1";}
	else{
		if(n.size()%2){
			string nn=n.substr(0,n.size()/2+1);
			if(rvso(nn)>n) cout << rvso(nn);
			else{
				for(int i=nn.size()-1; i>=0; i--){
					if(nn[i]=='9') nn[i]='0';
					else{nn[i]++; break;}
				}
				cout << rvso(nn);
			}
		}
		else{
			string nn=n.substr(0,n.size()/2);
			if(rvse(nn)>n) cout << rvse(nn);
			else{
				for(int i=nn.size()-1; i>=0; i--){
					if(nn[i]=='9') nn[i]='0';
					else{nn[i]++; break;}
				}
				cout << rvse(nn);
			}
		}
	}
    return 0;
}
