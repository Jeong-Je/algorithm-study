#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> a;

void func(int start,int cnt);

int main() {
    cin >> n >> m;

    func(1, 0);
}


void func(int start,int cnt) {
    if (cnt == m) {
        for (int i : a) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }


    for (int i=start;i<=n;i++) {
        a.push_back(i);
        func(i, cnt + 1);
        a.pop_back();
    }
}