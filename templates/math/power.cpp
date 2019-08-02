#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
void AOJ_NTL_1_B() {
    ll m, n;
    cin >> m >> n;
    cout << pow_mod(m, n, MOD) << "\n";
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_A
void AOJ_DPL_5_A() {
    int n, k;
    cin >> n >> k;
    cout << pow_mod(k, n, MOD) << "\n";
}

int main() {
    // AOJ_NTL_1_B();
    AOJ_DPL_5_A();
    return 0;
}