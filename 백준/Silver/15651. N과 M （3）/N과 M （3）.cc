#include <iostream>
#include <vector>

using namespace std;

int n, m;

void func(int cnt);

vector<int> ans;

int main() {
    cin >> n >> m;

    func(0);
}


void func(int cnt) {
    if (cnt == m) {
        for (int a : ans) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        ans.push_back(i);
        func(cnt + 1);
        ans.pop_back();
    }
}