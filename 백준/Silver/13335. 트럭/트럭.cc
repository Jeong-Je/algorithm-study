#include <iostream>
#include <queue>
#include <vector>

using namespace std;


vector<int> truck(1000);

int main() {
    int n, w, l;
    cin >> n >> w >> l;


    for(int i=0;i<n;i++){
        cin >> truck[i];
    }

    queue<int> q;
    int time = 0, total = 0;
    for(int i=0;i<n;i++) {
        while(true){
            // 제일 선두 트럭이 다리 끝에 도달하면
            if(q.size() == w) {
                total -= q.front();
                q.pop();
            }
            if(total + truck[i] <= l) break;
            q.push(0);
            time++;
        }
        q.push(truck[i]);
        total += truck[i];
        time++;
    }

    cout << time + w;
}