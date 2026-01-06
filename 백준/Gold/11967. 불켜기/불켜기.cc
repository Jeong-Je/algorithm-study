#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans = 0;

// vis 배열 설명
// { 0: 불이 안켜지고 올 수 있는 루트가 안 열림, 1: 불은 안 켜졌으나 올 수 있는 루트가 존재함,
//   2: 불도 켜지고 방문도 하였음,            3: 아직 안 갔지만 불 켜져 있음 }
int vis[101][101];

vector<pair<int,int>> sw[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int ir, int ic);

int main() {
    cin >> N >> M;

    for (int i=0;i<M;i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        // (x,y)에서 킬 수 있는 스위치의 방 좌표들 기록
        sw[x][y].push_back({a, b});
    }

    // 탐색 시작
    bfs(1, 1);

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (vis[i][j] == 2 || vis[i][j] == 3) ans++;
        }
    }

    cout << ans;
}

void bfs(int ir, int ic) {
    queue<pair<int, int>> q;
    q.push({ir, ic});
    vis[ir][ic] = 2;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d=0;d<4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if (vis[nr][nc] == 0) vis[nr][nc] = 1;

            else if (vis[nr][nc] == 3) {
                vis[nr][nc] = 2;
                q.push({nr, nc});
            }
        }

        for (auto[jr, jc] : sw[r][c]) {
            if (vis[jr][jc] == 1) {
                vis[jr][jc] = 2;
                q.push({jr, jc});
            } else if (vis[jr][jc] == 0) {
                vis[jr][jc] = 3;
            }
        }
    }
}