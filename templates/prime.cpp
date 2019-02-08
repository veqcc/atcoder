#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

// O(√n) で素数判定
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return n != 1;
}

// 約数のvectorを返す
vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) {
                ret.push_back(n / i);
            }
        }
    }

    return ret;
}

// 素因数分解
map<int, int> prime_factor(int n) {
    map<int, int> ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }

    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> vec = divisor(n);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";

    map<int, int> :: iterator itr;
    map<int, int> m = prime_factor(n);
    for (itr = m.begin(); itr != m.end(); itr++) {
        cout << itr->first << " : " << itr->second << "\n";
    }

    return 0;
}