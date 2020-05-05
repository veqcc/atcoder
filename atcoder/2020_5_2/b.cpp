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

int main() {
    ll x;
    cin >> x;
    ll cur = 100;
    for (int i = 1; i < 4000; i++) {
        cur *= 1.01;
        if (cur >= x) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}