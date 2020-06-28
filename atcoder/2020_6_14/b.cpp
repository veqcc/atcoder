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
    int x, y;
    cin >> x >> y;
    cout << (2 * x <= y && 4 * x >= y && y % 2 == 0 ? "Yes" : "No") << endl;
    return 0;
}