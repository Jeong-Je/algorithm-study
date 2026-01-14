#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<int> ans;

void func(int cnt);

int main() {
    cin >> n >> m;

    v.resize(n);

    for (int i=0;i<n;i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    func(0);
}

void func(int cnt) {
    if (cnt == m) {
        for ( int a : ans) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i=0;i<n;i++) {
        if (temp != v[i]) {
            ans.push_back(v[i]);
            temp = v[i];
            func(cnt + 1);
            ans.pop_back();
        }
    }
}