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
    int a, b;
    cin >> a >> b;
    if (a != b) {
        cout << 2 * min(a, b) << endl;
    } else {
        cout << 2 * a - 1 << endl;
    }
    return 0;
}