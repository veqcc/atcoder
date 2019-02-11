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

int main() {
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;

    if (a < x) {
        cout << "NO\n";
        return 0;
    }

    if (a + b < x + y) {
        cout << "NO\n";
        return 0;
    }

    if (a + b + c < x + y + z) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    return 0;
}