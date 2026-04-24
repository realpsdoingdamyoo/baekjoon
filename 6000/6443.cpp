#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
    	cin >> s;
    	sort(s.begin(), s.end());
    
    	do {
    		cout << s << "\n";
    	} while (next_permutation(s.begin(), s.end()));
    }
	return 0;
}
