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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;

    if ((A + B) % 2 == 0) {
        cout << (A + B) / 2 << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}