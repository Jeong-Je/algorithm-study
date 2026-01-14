#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<int> ans;
vector<bool> isUsed;

void func(int start,int cnt);

int main() {
    cin >> n >> m;

    v.resize(n);
    isUsed.resize(n);

    for (int i=0;i<n;i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    func(0, 0);
}

void func(int start, int cnt) {
    if (cnt == m) {
        for ( int a : ans) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i=start;i<n;i++) {
        if (isUsed[i] == false && temp != v[i]) {
            isUsed[i] = true;
            ans.push_back(v[i]);
            temp = v[i];
            func(i, cnt + 1);
            isUsed[i] = false;
            ans.pop_back();
        }
    }
}