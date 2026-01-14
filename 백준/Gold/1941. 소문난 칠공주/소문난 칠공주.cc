#include <iostream>
#include <queue>

using namespace std;

char map[5][5];
int chk[5][5];
bool vis[5][5];
int ans;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void func(int start, int cnt);
int cor[7];

bool bfs(int r, int c);

int main() {
    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            cin >> map[i][j];
        }
    }

    func(0, 0);

    cout << ans;
}


void func(int start, int cnt) {
    // 7좌표를 모두 선택 완료 하였으면
    if (cnt == 7) {
        fill(chk[0], chk[5], 0);
        fill(vis[0], vis[5], false);
        int r, c;
        for (int idx : cor) {
            chk[idx/5][idx%5] = 1;
            r = idx/5;
            c = idx%5;
        }

        if (bfs(r, c)) ans++;


        return;
    }

    for (int i=start;i<25;i++) {
        cor[cnt] = i;
        func(i+1, cnt + 1);
    }
}


bool bfs(int r, int c) {
    int cntY = 0, cntS = 0;
    if (map[r][c] == 'Y') cntY++;
    else cntS++;

    queue<pair<int, int>> q;
    q.push({r, c});
    vis[r][c] = true;

    while (!q.empty()) {
        auto [nowR, nowC] = q.front();
        q.pop();

        for (int d=0;d<4;d++) {
            int nexR = nowR + dr[d];
            int nexC = nowC + dc[d];

            if (nexR < 0 || nexR >= 5 || nexC < 0 || nexC >= 5) continue;
            if (chk[nexR][nexC] != 1) continue;
            if (vis[nexR][nexC]) continue;

            if (map[nexR][nexC] == 'S') cntS++;
            else cntY++;

            vis[nexR][nexC] = true;
            q.push({nexR, nexC});
        }
    }

    if (cntS + cntY != 7) return false;
    if (cntS < 4) return false;

    return true;
}
