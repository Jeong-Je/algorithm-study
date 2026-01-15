#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[50][50]; // 0은 호수, 1은 배양액을 뿌릴 수 없는 땅, 2는 배양액을 뿌릴 수 있는 땅
int vis[50][50];
vector<pair<int, int>> oilyLand;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int n, m, g, r, ans;
queue<pair<int, int>> q;
void bfs();
int main() {
	cin >> n >> m >> g >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				oilyLand.push_back({ i ,j });
			}
		}
	}

	vector<int> mask(oilyLand.size(), 0);
	int cR = r, cG = g;
	for (int i = mask.size()-1; i >= 0; i--) {
		if (cR > 0) { mask[i] = 2; cR--; }
		else if (cG > 0) { mask[i] = 1; cG--; }
	}

	do {
		for (int i = 0; i < mask.size(); i++) {
			if (mask[i] == 1) {
				auto [r, c] = oilyLand[i];
				map[r][c] = 3;
				vis[r][c] = 1;
				q.push({ r, c });
			}
			else if (mask[i] == 2) {
				auto [r, c] = oilyLand[i];
				map[r][c] = 4;
				vis[r][c] = 1;
				q.push({ r, c });
			}
		}
		 bfs();

		 fill(vis[0], vis[50], 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) map[i][j] = 1;
			}
		}
		for (auto [i, j] : oilyLand) map[i][j] = 2;

	} while (next_permutation(mask.begin(), mask.end()));

	cout << ans;
}

void bfs() {
	int cnt = 0;
	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();
		if (map[r][c] == 5) continue;
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			// 다음 칸이 호수이거나 꽃이면 이동 불가
			if (map[nr][nc] == 0 || map[nr][nc] == 5) continue;

			// 다음 칸이 배양액이 이미 뿌려진 칸
			if (map[nr][nc] == 3 || map[nr][nc] == 4) {
				// 다음 칸의 색이 지금 내 색이랑 다르면
				if (map[nr][nc] != map[r][c]) {
					// 방문 시간이 같다면 꽃 개화 
					if (vis[nr][nc] == vis[r][c] + 1) {
						map[nr][nc] = 5;  // 꽃
						cnt++;
					}
				}
				continue;
			}

			// 배양액이 없는 땅인 경우 
			map[nr][nc] = map[r][c];
			vis[nr][nc] = vis[r][c] + 1;
			q.push({ nr, nc });
		}
	}

	if (ans < cnt) ans = cnt;
}