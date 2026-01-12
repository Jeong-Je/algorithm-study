#include <iostream>

using namespace std;

int arr[20];
bool isUsed[20];
int n, s, tempSum, ans;

void func(int start);

int main() {
    cin >> n >> s;

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    func(0);

    if (s == 0) cout << ans - 1;
    else cout << ans;
}

void func(int start) {
    if (tempSum == s) {
        ans ++;
    }

    for (int i=start;i<n;i++) {
        if (isUsed[i]) continue;

        isUsed[i] = true;
        tempSum += arr[i];

        func(i+1);

        isUsed[i] = false;
        tempSum -= arr[i];
    }
}