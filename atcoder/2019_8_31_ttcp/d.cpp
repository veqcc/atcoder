#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int grundy = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 7) {
            grundy ^= 3;
        } else if (x == 2) {
            grundy ^= 1;
        } else {
            if (is_prime(x - 2)) {
                grundy ^= 2;
            } else {
                grundy ^= 1;
            }
        }
    }

    if (grundy == 0) {
        cout << "Ai" << "\n";
    } else {
        cout << "An" << "\n";
    }

    return 0;
}