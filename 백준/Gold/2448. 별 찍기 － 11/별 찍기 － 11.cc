#include <iostream>

using namespace std;

char arr[4000][7000];

void star(int i, int j, int n) {
    // 기본 별 찍기
    if (n == 3) {
        arr[i][j] = '*'; // 상단 꼭짓점

        arr[i+1][j-1] = '*';
        arr[i+1][j+1] = '*';

        arr[i+2][j-2] = '*';
        arr[i+2][j-1] = '*';
        arr[i+2][j]  = '*';
        arr[i+2][j+1] = '*';
        arr[i+2][j+2] = '*';
    }
    else {
        star(i, j, n / 2);
        star(i+n/2,j-n/2, n/2);
        star(i+n/2,j+n/2,n/2);
    }
}

int main() {
    int n;
    cin >> n;

    fill(arr[0], arr[4000], ' ');

    star(0, n-1, n);

    for (int i=0;i<n;i++) {
        for (int j=0;j<2*n-1;j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}