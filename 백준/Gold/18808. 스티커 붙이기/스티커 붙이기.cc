#include <iostream>
using namespace std;

int n, m, k;
int r, c;
int board[40][40];
int sticker[10][10];
int temp[10][10];

void rotateSticker() {
    // 시계 방향 90도 회전
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            temp[i][j] = sticker[r - 1 - j][i];
        }
    }

    // r, c 교환
    int t = r;
    r = c;
    c = t;

    // temp → sticker 복사
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sticker[i][j] = temp[i][j];
        }
    }
}

int main() {

    cin >> n >> m >> k;

    while (k--) {
        cin >> r >> c;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> sticker[i][j];

        bool placed = false;

        // 최대 4번 회전
        for (int rot = 0; rot < 4 && !placed; rot++) {

            for (int i = 0; i <= n - r && !placed; i++) {
                for (int j = 0; j <= m - c && !placed; j++) {

                    bool canAttach = true;

                    // 붙일 수 있는지 검사
                    for (int ii = 0; ii < r && canAttach; ii++) {
                        for (int jj = 0; jj < c; jj++) {
                            if (sticker[ii][jj] == 1 && board[i + ii][j + jj] == 1) {
                                canAttach = false;
                                break;
                            }
                        }
                    }

                    // 붙이기
                    if (canAttach) {
                        for (int ii = 0; ii < r; ii++) {
                            for (int jj = 0; jj < c; jj++) {
                                if (sticker[ii][jj] == 1)
                                    board[i + ii][j + jj] = 1;
                            }
                        }
                        placed = true;
                    }
                }
            }

            if (!placed)
                rotateSticker();
        }
    }

    // 결과 계산
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 1)
                ans++;

    cout << ans << '\n';
    return 0;
}
