#include <iostream>
using namespace std;
 
int main() {
	int N;
	int answer = -1;
	int L;
	int points[50][2];
	cin >> N;
 
	int maxX = -1000;
	int maxY = -1000;
	int minX = 1000;
	int minY = 1000;
 
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		points[i][0] = x;
		points[i][1] = y;
		maxX = max(x, maxX);
		maxY = max(y, maxY);
		minX = min(x, minX);
		minY = min(y, minY);
	}
 
	L = max(maxX-minX,maxY-minY);
 
	if (maxX - minX == maxY - minY) {
		answer = L;
		for (int i = 0; i < N; i++) {
			if (points[i][0] != maxX && points[i][0] != minX && points[i][1] != maxY && points[i][1] != minY) {
				answer = -1;
			}
		}
	}else{
		int maxX_s, maxY_s, minX_s, minY_s;
        for (int i = 0; i <= L; i++) {
			if (maxX - minX > maxY - minY) {
				minY_s = maxY - i;
				maxY_s = minY_s + L;
				minX_s = minX;
				maxX_s = maxX;
			}
			else {
				minX_s = maxX - i;
				maxX_s = minX_s + L;
				minY_s = minY;
				maxY_s = maxY;
			}
 
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				if (points[i][0] == maxX_s || points[i][0] == minX_s || points[i][1] == maxY_s || points[i][1] == minY_s) {
					cnt++;
				}
			}
			if (cnt == N) {
				answer = L;
			}
		}
	}
 
	cout << answer;
	return 0;
}
