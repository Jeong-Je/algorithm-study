#include <iostream>

using namespace std;

int n, m;
int isUsed[9];

void func(int start, int cnt);

int main() {
    cin >> n >> m;

    func(1, 0);
}

void func(int start, int cnt) {
    if (cnt == m) {
        for (int i=1;i<=n;i++) {
            if (isUsed[i] == true) cout << i << ' ';
        }
        cout << '\n';
    }

    for (int i=start;i<=n;i++) {
        if (isUsed[i] == true) continue;

        isUsed[i] = true;

        func(i+1, cnt + 1);

        isUsed[i] = false;
    }
}