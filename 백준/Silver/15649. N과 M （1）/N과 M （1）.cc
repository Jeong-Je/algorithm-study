#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
int N, M;
bool chk[9];

void bt(int start, int cnt);

int main() {
    cin >> N >> M;

    bt(1, 0);
}


void bt(int start, int cnt) {
    if (cnt == M) {
        for (int i=0;i<M;i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    for (int i=1;i<=N;i++) {
        if (chk[i]) continue;

        ans.push_back(i);
        chk[i] = true;

        bt(i, cnt + 1);

        ans.pop_back();
        chk[i] = false;
    }
}