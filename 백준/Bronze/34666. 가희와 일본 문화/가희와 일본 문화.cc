#include <iostream>

using namespace std;

int cutLine[6] = {0, 100, 90, 95, 90, 80};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int level, word, read, listen;
        cin >> level >> word >> read >> listen;
        
     
        // 2급 이하 응시 
        if(level > 2) {
            cout << "NO\n";
            continue;
        }
     
        // 청해 50점 미만 
        if(listen < 50) {
            cout << "NO\n";
            continue;
        }
   
        // 3-1 조건
        if(word * 3 < cutLine[level] && read * 3 < cutLine[level]) {
            cout << "YES\n";
            continue;
        }
   
        // 3-2 조건 
        if(word - 19 < 3 || read - 19 < 3) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
        
    }
}