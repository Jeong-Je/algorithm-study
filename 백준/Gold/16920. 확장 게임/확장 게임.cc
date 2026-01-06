#include <iostream>
#include <queue>

using namespace std;

int N, M, P;
int map[1000][1000];
int dis[1000][1000];

// 한 번에 갈 수 있는 거리를 담은 배열
int s[10];
// 현재 시작점에서 얼만큼 왔는지 저장하는 배열
int p[10];

int ans[10];

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

bool bfs(int bnd);

int main()
{
	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) cin >> s[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == '.') map[i][j] = 0;
			else if(c == '#') {
				map[i][j] = -1;
			}
			else {
				map[i][j] = c - '0';
				dis[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 10; i++) p[i] = 1;

	bool find = false;
	for (int nPlayer = 1; nPlayer <= P; nPlayer++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == nPlayer && dis[i][j] == p[nPlayer]) {
					q.push({ i, j });
				}
			}
		}
		if (!q.empty()) {
			if (bfs(p[nPlayer] + s[nPlayer])) {
				find = true;
			}
		}
		if(find) p[nPlayer] += s[nPlayer];

		// 마지막 순서에 도달
		if (nPlayer == P) {
			// 아무도 진전을 못했다면 
			if (find == false) break;

			find = false;
			nPlayer = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '#' || map[i][j] == '.') continue;

			ans[map[i][j]]++;
		}
	}

	for (int i = 1; i <= P; i++) {
		cout << ans[i] << ' ';
	}
}

bool bfs(int bnd)
{
	bool find = false;

	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();

		if (dis[r][c] >= bnd) continue;

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			// 경계 넘어서면 continue
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			// 빈 칸이 아니면 continue
			if (map[nr][nc] != 0) continue;


			map[nr][nc] = map[r][c];
			dis[nr][nc] = dis[r][c] + 1;

			find = true;

			q.push({ nr, nc, });
		}
	}

	return find;
}