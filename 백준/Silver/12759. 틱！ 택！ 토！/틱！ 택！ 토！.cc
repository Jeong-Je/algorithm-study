#include <iostream>

using namespace std;

int arr[4][4];

int main() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			arr[i][j] = -1 * (i * j);
		}
	}
	int p;
	cin >> p;

	// 0(false)는 1번 플레이어 1(true)는 2번 플레이어 
	bool now_p = (p == 1 ? 0 : 1);
	int winner = 0;
	for (int t = 0; t < 9; t++) {
		int r, c;
		cin >> r >> c;

		if (winner) continue;


		if (now_p) arr[r][c] = 2;
		else arr[r][c] = 1;

		// 가로 3줄 검사
		for (int i = 1; i <= 3; i++) {
			if (arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3]) {
				winner = now_p + 1;
				break;
			}
		}

		// 세로 3줄 검사
		for (int i = 1; i <= 3; i++) {
			if (arr[1][i] == arr[2][i] && arr[2][i] == arr[3][i]) {
				winner = now_p + 1;
				break;
			}
		}

		if (winner) continue;

		// 대각선 2줄 검사
		if (arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3]) {
			winner = now_p + 1;
			continue;
		}
		if (arr[1][3] == arr[2][2] && arr[2][2] == arr[3][1]) {
			winner = now_p + 1;
		}

		now_p = !now_p; // 플레이어 교대
		
	}


	cout << winner;
}