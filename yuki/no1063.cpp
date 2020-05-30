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
    int n;
    cin >> n;

    auto f = prime_factor(n);

    int a = 1, b = 1;
    for (auto itr = f.begin(); itr != f.end(); itr++) {
        for (int j = 1; j < itr->second; j += 2) a *= itr->first;
        if (itr->second % 2) b *= itr->first;
    }

    cout << a << ' ' << b << endl;
    return 0;
}