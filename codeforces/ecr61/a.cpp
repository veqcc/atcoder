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
using namespace std;

int main() {
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

    if (c1 != c4 || (c3 > 0 && c1 == 0)) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }

    return 0;
}