#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> s;
vector<int> ans;

void func(int start, int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> k;
        if (k == 0) break;

        s.resize(k);
        for (int i=0;i<k;i++) cin >> s[i];

        func(0, 0);
        cout << '\n';
    }
}

void func(int start, int cnt) {
    if (cnt == 6) {
        for (int a: ans) cout << a << ' ';
        cout << '\n';

        return;
    }

    for (int i=start; i<k;i++) {
        ans.push_back(s[i]);
        func(i + 1, cnt + 1);
        ans.pop_back();
    }
}