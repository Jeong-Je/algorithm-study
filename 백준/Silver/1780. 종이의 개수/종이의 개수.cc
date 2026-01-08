#include <iostream>

using namespace std;

// (3^7) * (3^7)을 모두 담을 수 있도록 크기 적당히 설정
int arr[2200][2200];

int minusCnt = 0;
int zeroCnt = 0;
int oneCnt = 0;

void cnt(int n, int r, int c) {
    int num = arr[r][c];

    if (n == 1) {
        if (num == -1) minusCnt ++;
        if (num == 0) zeroCnt++;
        if (num == 1) {
            oneCnt++;
        }

        return;
    }

    bool isOne = true;
    for (int i=r;i<r+n;i++) {
        for (int j=c;j<c+n;j++) {
            // 다른 종류의 종이가 있는 경우 ( 종이 9등분 분할 필요 )
            if (arr[i][j] != num) {
                isOne = false;
                break;
            }
        }
    }

    if (isOne) {
        if (num == -1) minusCnt++;
        else if (num == 0) zeroCnt++;
        else{
            oneCnt++;
        }
    }

    // 종이 9등분 하기
    else {
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                cnt(n / 3, r + i * (n/3), c + j * (n/3));
            }
        }
    }

}

int main() {
    int n;
    cin >> n;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    cnt(n, 0, 0);

    cout << minusCnt << '\n' << zeroCnt << '\n' <<  oneCnt;
}