#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

enum time{
    day,
    night,
};

int N,M,K;
int map[1000][1000];
int dis[1000][1000][11][2];

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
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, day});
    dis[0][0][0][day] = 1;

    while (!q.empty()) {
        auto [r, c, nk, time] = q.front();
        q.pop();
        
        if (r == N - 1 && c == M - 1) {
            cout << dis[r][c][nk][time];
            return;
        }

        for (int d=0;d<4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            int next_time = time == night ? day : night;

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // 다음 칸이 벽이라면
            if (map[nr][nc] == 1) {
                // nk를 다 쓴 상황에서는 진입 불가능
                if (nk == K) continue;

                // 지금이 낮이라면 벽 부수고 이동
                if (time == day) {
                    if (dis[nr][nc][nk+1][next_time]) continue;

                    dis[nr][nc][nk+1][next_time] = dis[r][c][nk][time] + 1;
                    q.push({nr, nc, nk + 1, next_time});
                }
                // 지금이 밤이라면 제자리에서 이동
                else {
                    if (dis[r][c][nk][next_time]) continue;

                    dis[r][c][nk][next_time] = dis[r][c][nk][time] + 1;
                    q.push({r, c, nk, next_time});
                }
            }

            // 다음 칸이 벽이 아니라면
            else {
                if (dis[nr][nc][nk][next_time]) continue;

                dis[nr][nc][nk][next_time] = dis[r][c][nk][time] + 1;
                q.push({nr, nc, nk, next_time});
            }
        }
    }

    cout << -1;
}