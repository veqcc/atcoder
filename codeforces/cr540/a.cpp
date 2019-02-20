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
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        ll n, a, b;
        cin >> n >> a >> b;

        if (2 * a <= b) {
            cout << a * n << "\n";
        } else {
            cout << n / 2 * b + (n % 2) * a << "\n";
        }
    }

    return 0;
}