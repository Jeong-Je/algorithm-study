#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, idx, ans = INT_MAX;
int arr[50][50];
int dis[50][50];

int ansDis[100][13];
int anss[100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<pair<int ,int>> chicken;

queue<pair<int ,int>> q;

void bfs();

int main() {
    cin >> n >> m;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<int> mask(chicken.size());
    for (int i=1;i<=m;i++) {
        mask[chicken.size()-i] = 1;
    }

    // 각 집에서 각 치킨집으로 거리 구해놓기
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (arr[i][j] == 1) {
                fill(dis[0], dis[n], 0);

                q.push({i, j});
                dis[i][j] = 1;
                bfs();
                idx++;
            }
        }
    }

    // for (int i=0;i<idx;i++) {
    //     for (int j=0;j<chicken.size();j++) {
    //         cout << ansDis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    do {
        for (int i=0;i<idx;i++) anss[i] = INT_MAX;
        int temp = 0;
        for (int i=0;i<mask.size();i++) {
            if (mask[i] == 1) {
                for (int h=0;h<idx;h++) {
                    if (ansDis[h][i] < anss[h]) anss[h] = ansDis[h][i];
                }
            }
        }

        for (int i=0;i<idx;i++) {
            temp += anss[i];
        }

        if (temp < ans) ans = temp;
    }while (next_permutation(mask.begin(), mask.end()));


    cout << ans;
}

void bfs() {
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (arr[r][c] == 2){
            for (int i=0;i<chicken.size();i++) {
                auto [cr, cc] = chicken[i];
                if (r == cr && c == cc) {
                    ansDis[idx][i] = dis[r][c] - 1;
                    break;
                }
            }
        }

        for (int d=0;d<4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (dis[nr][nc]) continue;

            dis[nr][nc] = dis[r][c] + 1;
            q.push({nr, nc});
        }
    }
}