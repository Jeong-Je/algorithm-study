#include <iostream>

using namespace std;

int calc(int n, int r, int c) {
    if (n==0) return 0;

    // 한 변의 절반 길이
    int half = 1 << (n-1);

    // 좌표가 1사분면에 위치
    if (r < half && c < half) {
        return calc(n-1, r, c);
    }
    // 좌표가 2사분면에 위치
    else if (r < half && c >= half) {
        return half*half + calc(n-1, r, c-half);
    }
    // 좌표가 3사분면에 위치
    else if (r >= half && c < half) {
        return 2*half*half + calc(n-1, r-half, c);
    }
    // 좌표가 4사분면에 위치
    else {
        return 3*half*half + calc(n-1, r-half, c-half);
    }
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    cout << calc(n, r, c);
}