#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
vector<int> ans;

void func(int start, int cnt);

int main() {
    cin >> n >> m;
    v.resize(n);

    for (int i=0;i<n;i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    func(0, 0);
}


void func(int start, int cnt) {
    if (cnt == m) {
        for (int a: ans) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=start;i<n;i++) {
        ans.push_back(v[i]);
        func(i, cnt + 1);
        ans.pop_back();
    }
}