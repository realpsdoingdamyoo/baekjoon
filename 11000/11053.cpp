#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> arr, lis; int liss;

int lisbs(int f) {
	int s=0, e=liss;
    while (s < e) {
        int m = (s + e) / 2;
        if (lis[m] < f)
            s = m + 1;
        else
            e = m;
    }
    return s;
}

int main(){
	int n, k; cin >> n;
	for(int i=0; i<n; i++){cin >> k; arr.push_back(k);}
	lis.push_back(arr[0]);
	for(int i=0; i<n; i++){
		if(lis[liss]<arr[i]) {lis.push_back(arr[i]); liss++;}
		else{
			int s=lisbs(arr[i]);
			lis[s]=arr[i];
		}
	}
	cout << liss+1;
    return 0;
}
