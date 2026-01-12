#include <iostream>

using namespace std;

int n, ans;
int isused1[30];
int isused2[30];
int isused3[30];

void func(int cnt);

int main() {
    cin >> n;

    func(0);

    cout << ans;
}

void func(int cnt) {
    if (cnt == n) {
        ans++;
        return;
    }

    for (int i=0;i<n;i++) {
        if (isused1[i] || isused2[i+cnt] || isused3[cnt - i + n-1]) continue;

        isused1[i] = true;
        isused2[i + cnt] = true;
        isused3[cnt - i + n-1] = true;

        func(cnt + 1);

        isused1[i] = false;
        isused2[i + cnt] = false;
        isused3[cnt - i + n-1] = false;
    }
}