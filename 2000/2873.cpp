#include <bits/stdc++.h>
using namespace std;

int main() {
	int R, C;

	cin >> R >> C;

	int **pleasure = new int*[R];
	for (int i = 0; i < R; i++) {
		pleasure[i] = new int[C];
	}

	pair <int, int> blank;
	int min = 1001; 
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> pleasure[i][j];
			if (min > pleasure[i][j] && (i + j) % 2 == 1) {
				min = pleasure[i][j];
				blank.first = i;
				blank.second = j;
			}
		}
	}


	string move;
	int i, j;
	if (R % 2 == 1) { 
		for (i = 0; i < R; i++) {
			for (j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					move += 'R'; 
				else
					move += 'L'; 
			}
			if (i == R - 1)
				break;
			move += 'D'; 
		}
	}
	else if (C % 2 == 1) { 
		for (i = 0; i < C; i++) {
			for (j = 0; j < R - 1; j++) {
				if (i % 2 == 0)
					move += 'D'; 
				else
					move += 'U'; 
			}
			if (i == C - 1)
				break;
			move += 'R';
		}
	}
	else {
		int r, c;
		if (blank.first % 2 == 1)
			r = blank.first - 1; 
		else
			r = blank.first; 

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					move += 'R';
				else
					move += 'L';
			}
			move += 'D';
		}


		c = blank.second;

		for (int i = 0; i < c; i++) {
			if (i % 2 == 0)
				move += "DR";
			else
				move += "UR";
		}

		for (int i = c; i < C - 1; i++) {
			if (i % 2 == 0)
				move += "RD";
			else
				move += "RU";
		}

		for (int i = r + 2; i < R; i++) {
			move += 'D';
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					move += 'L';
				else
					move += 'R';
			}
		}

	}

	cout << move << endl;

	return 0;
}
