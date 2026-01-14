#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> egg;
int n, ans;

void func(int hand);

int main() {
    cin >> n;

    egg.resize(n);

    for (int i=0;i<n;i++) {
        int s, w; // 내구도와 무게
        cin >> s >> w;

        egg[i] = make_pair(s, w);
    }

    // 1. 왼쪽 계란부터 손에 들어서 내려친다.
    // 2. 가장 오른쪽 계란을 들어서 내려쳤다면
    func(0);

    cout << ans;
}

void func(int hand) {
    // 가장 오른쪽 계란까지 들기 끝 
    if (hand == n) {
        int tmp = 0;
        for (auto[s,w] : egg) {
            if (s <= 0) tmp++;
        }
        if (ans < tmp) ans = tmp;

        return;
    }

    // 손에 든 계란이 깨진 계란이면 다음 계란으로
    if (egg[hand].first <= 0) {
        func(hand + 1);
        return;
    }


    bool hit = false;

    for (int i = 0; i < n; i++) {
        // 손에 든 계란으로 손에 든 계란치기는 금지
        if (i == hand) continue;
        // 쳐야 되는 계란이 이미 깨진 계란이면 패스 
        if (egg[i].first <= 0) continue;

        hit = true;
        
        // 내구도 감소
        egg[hand].first -= egg[i].second;
        egg[i].first -= egg[hand].second;
        
        // 다음 계란 진행 
        func(hand + 1);
    
        // 내구도 복구 
        egg[hand].first += egg[i].second;
        egg[i].first += egg[hand].second;
    }

    // 칠 수 있는 계란이 하나도 없는 경우
    if (!hit)
        func(hand + 1);

}