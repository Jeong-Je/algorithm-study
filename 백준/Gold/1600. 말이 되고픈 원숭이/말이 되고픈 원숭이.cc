#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;
int map[200][200];
int dis[200][200][31];

// 말의 이동방법
int h_dr[8] = {-2, -2, -1 , 1, 2, 2, 1, -1};
int h_dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

// 원숭이의 이동방법
int m_dr[4] = {-1, 1, 0, 0};
int m_dc[4] = {0, 0, -1, 1};

void bfs(int fr, int fc);

int main() {
    cin >> K >> M >> N;

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }

    bfs(0, 0);
}

void bfs(int fr, int fc) {
    queue<tuple<int, int, int>> q;
    q.push({fr, fc, 0});

    dis[0][0][0] = 1;

    while (!q.empty()) {
        auto [r, c, nk] = q.front();
        q.pop();

        // 도착지점 도착
        if (r == N -1 && c == M - 1) {
            cout << dis[N-1][M-1][nk] - 1;
            return;
        }

        // 말 이동 방법을 쓸 수 있는 경우 ( nk < K )
        if (nk < K) {
            for (int d=0;d<8;d++) {
                int nr = r + h_dr[d];
                int nc = c + h_dc[d];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                if (dis[nr][nc][nk+1] || map[nr][nc]) continue;

                dis[nr][nc][nk+1] = dis[r][c][nk] + 1;
                q.push({nr, nc, nk + 1});
            }
        }

        // 원숭이 이동 방법
        for (int d=0;d<4;d++) {
            int nr = r + m_dr[d];
            int nc = c + m_dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (dis[nr][nc][nk] || map[nr][nc]) continue;

            dis[nr][nc][nk] = dis[r][c][nk] + 1;
            q.push({nr, nc, nk});
        }
    }

    // 도착지점에 도착 못 한 경우
    cout << -1;
}