#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N,M,K;
int map[1000][1000];
int dis[1000][1000][11];

int dr[4] = {-1 ,1 ,0 ,0};
int dc[4] = {0, 0, -1, 1};

void bfs(int ir, int ic);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    for (int i=0;i<N;i++) {
        string s;
        cin >> s;
        for (int j=0;j<M;j++) {
            map[i][j] = s[j] - '0';
        }
    }

    bfs(0,0);
}

void bfs(int ir, int ic) {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dis[0][0][0] = 1;

    while (!q.empty()) {
        auto [r, c, nk] = q.front();
        q.pop();

        if (r == N - 1 && c == M - 1) {
            cout << dis[r][c][nk];
            return;
        }

        for (int d=0;d<4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // 다음 칸이 벽이라면
            if (map[nr][nc] == 1) {
                // nk를 다 쓴 상황에서는 진입 불가능
                if (nk == K) continue;

                if (dis[nr][nc][nk+1]) continue;
                dis[nr][nc][nk+1] = dis[r][c][nk] + 1;
                q.push({nr, nc, nk + 1});
            }

            // 다음 칸이 벽이 아니라면
            else {
                if (dis[nr][nc][nk]) continue;
                dis[nr][nc][nk] = dis[r][c][nk] + 1;
                q.push({nr, nc, nk});
            }
        }
    }

    cout << -1;
}