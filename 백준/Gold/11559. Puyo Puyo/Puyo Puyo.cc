#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int ROW = 12;
constexpr int COL = 6;

char arr[ROW][COL];
int vis[ROW][COL];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int ans;

// 파괴할 블록들의 좌표를 기억하는 벡터
vector<pair<int, int>> des;

bool bfs(int, int);

int main() {
    for (int i=0;i<ROW;++i) {
        for (int j=0;j<COL;++j) {
            cin >> arr[i][j];
        }
    }

    while (true) {
        // 방문배열 초기화
        fill(vis[0], vis[ROW], 0);
        
        des.clear();
        bool puYo = false;


        for (int i=0;i<ROW;++i) {
            for (int j=0;j<COL;++j) {
                if (arr[i][j] == '.' || vis[i][j]) continue;

                if (bfs(i, j)) puYo = true;
            }
        }

        // 상쇄 작용 발생 없음 (끝)
        if (puYo == false) break;

        // 1상쇄 시작
        for (auto[r, c] : des) {
            arr[r][c] = '.';
        }

        // 상쇄가 된 후 공중에 떠있는 뿌요들 아래로 떨구기
        for (int c=0;c<COL;c++) {
            for (int r=ROW-2;r>=0;r--) {
                // 현재 칸이 빈칸이면 내릴 필요 X
                if (arr[r][c] == '.') continue;

                // 현재 칸의 바로 아래 칸이 빈칸이면 내리기
                int tempR = r;
                while (tempR+1 < ROW && arr[tempR+1][c] == '.') {
                    arr[tempR+1][c] = arr[tempR][c];
                    arr[tempR][c] = '.';
                    tempR++;
                }
            }
        }

        ++ans;
    }


    cout << ans;
}

bool bfs(int ir, int ic) {
    queue<pair<int ,int>> q;
    q.push(make_pair(ir, ic));
    vis[ir][ic] = 1;
    
    // 연결 횟수 관리 변수 
    int connectCnt = 1;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        des.push_back(make_pair(r, c));

        for (int d=0;d<4;++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;
            if (arr[r][c] != arr[nr][nc]) continue;
            if (vis[nr][nc]) continue;
            
            connectCnt++;
            vis[nr][nc] = vis[r][c] + 1;
            q.push(make_pair(nr, nc));
        }
    }

    // 연결된 개수가 4개미만이면 파괴안됨
    if (connectCnt < 4) {
        while (connectCnt--) {
            des.pop_back();
        }
        return false;
    }

    // 연결된 개수가 4개이상으로 연쇄 발생 예정
    return true;
}
