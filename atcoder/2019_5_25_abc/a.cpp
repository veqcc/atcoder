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
    int a,b;
    cin >> a >> b;

    if (a >= 13) {
        cout << b << '\n';
    } else if (a >= 6) {
        cout << b / 2 << '\n';
    } else {
        cout << 0 << "\n";
    }

    return 0;
}