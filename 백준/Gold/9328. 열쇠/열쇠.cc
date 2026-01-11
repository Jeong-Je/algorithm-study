#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, ans;
queue<pair<int, int>> q;

char map[100][100];
int vis[100][100]; // {0: 방문X}, {1: 방문O}, {2: 방문 가능하나 열쇠 없어서 못 감}
vector<pair<int, int>> door[26]; // 문 좌표들 기록하는 벡터

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;


        // 초기화
        fill(vis[0], vis[100], 0);
        for (int i=0;i<26;i++) {
            door[i].clear();
        }
        ans = 0;
        string key;
        // 빌딩 정보 입력 받기
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cin >> map[i][j];
                // 문 좌표들 기록하기
                if (map[i][j] >= 'A' && map[i][j] <= 'Z') door[map[i][j] - 'A'].push_back({i, j});
                // 가장자리 인 것들 중에서 벽이랑 문 빼고 큐에 넣기
                if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if (map[i][j] == '*') continue;
                    vis[i][j] = 2;
                    if (map[i][j] >= 'A' && map[i][j] <= 'Z') continue;

                    // 문서인 경우
                    if (map[i][j] == '$') ans++;
                    // 열쇠인 경우
                    if (map[i][j] >= 'a' && map[i][j] <= 'z') {
                        key += map[i][j];
                    }

                    vis[i][j] = 1;
                    q.push({i, j});

                }
            }
        }

        // 내가 가지고 있는 열쇠 입력 받기
        string s;
        cin >> s;
        key += s;
        if (key != "0") {
            for (int k=0;k<key.length();k++) {
                for (auto[r, c] : door[key[k]-'a']) {
                    // 키로 열 수 있는 문 미리 다 열어놓기
                    map[r][c] = '.';
                    // 문이 가장 자리였다면 큐에 넣기
                    if (r == 0 || r == n-1 || c == 0 || c == m-1) {
                        vis[r][c] = 1;
                        q.push({r,c});
                    }
                }
            }
        }

        bfs();

        cout << ans << '\n';
    }
}

void bfs() {
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        //cout << r << " " << c << " " << map[r][c] <<  endl;
        for (int d=0;d<4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (vis[nr][nc] != 0 || map[nr][nc] == '*') continue;

            // 다음 칸이 빈칸인 경우
            if (map[nr][nc] == '.') {
                // 계속 진행
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
            // 다음 칸이 문서인 경우
            else if (map[nr][nc] == '$') {
                map[nr][nc] = '.';
                vis[nr][nc] = 1;
                //cout << nr << ' ' << nc << endl;
                ans++;
                q.push({nr,nc});
            }
            // 다음 칸이 열쇠인 경우
            else if (map[nr][nc] >= 'a' && map[nr][nc] <= 'z') {
                //cout << "key " <<  nr <<" " << nc << " " << map[nr][nc] << endl;

                for (auto[r, c] : door[map[nr][nc] -'a']) {
                    // 열쇠로 문 전부 열기
                    map[r][c] = '.';

                    // 해당 문이 방문 가능했던 곳이었다면 큐에 넣기
                    if (vis[r][c] == 2) {
                        vis[r][c] = 1;
                        q.push({r, c});
                    }
                }
                map[nr][nc] = '.';
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
            // 다음 칸이 문인 경우
            else if (map[nr][nc] >= 'A' && map[nr][nc] <= 'Z') {
                vis[nr][nc] = 2;
                door[map[nr][nc] - 'A'].push_back({nr, nc});
            }
        }
    }

}
