#include <iostream>

using namespace std;

int arr[64][64];

void cps(int n, int r ,int c);

int main(){
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             scanf("%1d", &arr[i][j]);
        }
    }
    
    cps(n, 0, 0);
}

void cps(int n, int r ,int c)
{
    int pre = arr[r][c];
    bool isSame = true;
    
    for(int i=r;i<r+n;i++){
        for(int j=c;j<c+n;j++){
            if(pre != arr[i][j]) {
                isSame = false;
                break;
            }
        }
    }
    
    if(isSame) {
        cout << pre;
        
    } else {
        cout << "(";
        // 4분할 해서 다시 압축
        // 1사분면
        cps(n / 2, r, c);
 
        // 2사분면
        cps(n / 2, r, c + n / 2);
   
        // 3사분면
        cps(n / 2, r + n / 2, c);
      
        // 4사분면
        cps(n / 2, r + n / 2, c + n / 2);
     
        cout << ")";
    }
    

}