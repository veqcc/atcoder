#include <iostream>
using namespace std;

// 1~nまでの自然数のうち、nと互いに素なものの個数
// O(√n)
int euler_totient(int n) {
    int ret = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
void AOJ_NTL_1_D() {
    int n;
    cin >> n;
    cout << euler_totient(n) << "\n";
}

int main() {
    AOJ_NTL_1_D();
    return 0;
}