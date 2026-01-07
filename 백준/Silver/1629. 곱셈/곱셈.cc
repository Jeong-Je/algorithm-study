#include <iostream>

using namespace std;
using ll = long long;

ll pow(ll A, ll B, ll C) {
    if (B == 1) return A % C;

    ll val = pow(A, B / 2, C);
    val = val * val % C;

    if (B % 2 == 0) return val;
    else return (val * A % C);
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    cout << pow(A, B, C);
}