#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 計算量は O(NloglogN) らしい
vector<bool> sieve(int n) { // sieve : ふるい
    vector <bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp
void AOJ_ALDS_1_C() {
    int n;
    cin >> n;
    auto is_prime = sieve(100000005);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        ans += is_prime[m];
    }
    cout << ans << "\n";
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2018Day1/problems/C
void ACPC_2019_9_19_C() {
    int n;
    cin >> n;
    vector <bool> is_prime = sieve(n+2);
    int ans = 0;
    for (int i = 3; i <= n; i++) {
        ans += is_prime[i] & is_prime[i + 2];
    }
    cout << ans * 2 << "\n";
}


// verified
//   https://yukicoder.me/problems/no/843
void yuki843() {
    int n;
    cin >> n;
    vector <bool> is_prime = sieve(n+2);
    int ans = 0;
    if (n >= 2) ans++;
    for (int i = 3; i <= n; i++) {
        if (!is_prime[i]) continue;
        int sum = 2 + i;
        int s = sqrt(sum);
        if (s * s == sum && is_prime[s]) ans += 2;
    }
    cout << ans << "\n";
}

int main() {
    AOJ_ALDS_1_C();
    // ACPC_2019_9_19_C();
    // yuki843();
    return 0;
}