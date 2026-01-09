#include <iostream>

using namespace  std;

int map[128][128];
int ans[2];

void slice(int n, int r, int c) {
    int pre = map[r][c];
    bool isSame = true;

    for (int i=r;i<r+n;i++) {
        for (int j=c;j<c+n;j++) {
            if (map[i][j] != pre) {
                isSame = false;
                break;
            }
        }
    }


    // 한 장의 종이이면
    if (isSame) {
       ans[pre]++;

    } else {
        // 4등분으로 다시 나누기

        // 1사분면
        slice(n / 2, r, c);

        //2사분면
        slice(n / 2, r, c + n/2);

        //3사분면
        slice(n / 2, r + n/2 , c);

        // 4사분면
        slice(n / 2, r+n/2, c+n/2);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> map[i][j];
        }
    }

    slice(n, 0, 0);

    for (int an : ans) {
        cout << an << '\n';
    }
}