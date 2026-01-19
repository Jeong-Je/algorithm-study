#include <iostream>
#include <cstring>

using namespace std;

int arr[20][20];
int n, ans;

void func(int);
void move(int, int);

int main() {
    cin >> n;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr[i][j];
            if (arr[i][j] > ans) ans = arr[i][j];
        }
    }

    func(0);

    cout << ans;
}


void func(int cnt) {
    if (cnt == 5) return;

    int backup[20][20];
    memcpy(backup, arr, sizeof(arr));

    for (int d = 1; d <= 4; d++) {
        move(d, cnt + 1);
        func(cnt + 1);
        memcpy(arr, backup, sizeof(arr));
    }
}


void move(int dir,int cnt) {
    // cout<< "before move \n";
    // for (int i=0;i<n;i++) {
    //     for (int j=0;j<n;j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }


    // 오른쪽으로 붙이기
    if (dir == 1) {
        for (int i=0;i<n;i++) {
            int end = n - 1;
            bool merge = true;
            for (int j=n-1;j>=0;j--) {
                if (arr[i][j] == 0) continue;

                if (merge && end + 1 < n && arr[i][end+1] == arr[i][j]) {
                    arr[i][end+1] += arr[i][j];
                    arr[i][j] = 0;
                    merge = false;
                } else {
                    arr[i][end] = arr[i][j];
                    if (end != j) arr[i][j] = 0;
                    merge = true;
                    end--;
                }
            }
        }
    }
    // 왼쪽으로 붙이기
    else if (dir == 2) {
        for (int i=0;i<n;i++) {
            int end = 0;
            bool merge = true;
            for (int j=0;j<n;j++) {
                if (arr[i][j] == 0) continue;

                if (merge && end - 1 >= 0 && arr[i][end-1] == arr[i][j]) {
                    arr[i][end-1] += arr[i][j];
                    arr[i][j] = 0;
                    merge = false;
                } else {
                    arr[i][end] = arr[i][j];
                    if (end != j) arr[i][j] = 0;
                    end++;
                    merge = true;
                }
            }
        }
    }
    // 아래쪽으로 붙이기
    else if (dir == 3) {
        for (int j=0;j<n;j++) {
            int end = n-1;
            bool merge = true;
            for (int i=n-1;i>=0;i--) {
                if (arr[i][j] == 0) continue;

                if (merge && end + 1 < n &&arr[end+1][j] == arr[i][j]) {
                    arr[end+1][j] += arr[i][j];
                    arr[i][j] = 0;
                    merge = false;
                } else {
                    arr[end][j] = arr[i][j];
                    if (end != i) arr[i][j] = 0;
                    end--;
                    merge = true;
                }
            }
        }
    }
    // 위쪽으로 붙이기
    else if (dir == 4) {
        for (int j=0;j<n;j++) {
            int end = 0;
            bool merge = true;
            for (int i=0;i<n;i++) {
                if (arr[i][j] == 0) continue;

                if (merge && end - 1 >= 0 && arr[end-1][j] == arr[i][j]) {
                    arr[end-1][j] += arr[i][j];
                    arr[i][j] = 0;
                    merge = false;
                } else {
                    arr[end][j] = arr[i][j];
                    if (end != i) arr[i][j] = 0;
                    end++;
                    merge = true;
                }
            }
        }
    }


    // 최대값 계산
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (arr[i][j] > ans) ans = arr[i][j];
        }
    }

    //
    // cout<< "after move " << dir << " " << cnt << endl;
    // for (int i=0;i<n;i++) {
    //     for (int j=0;j<n;j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "\n";
}