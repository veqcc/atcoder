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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 9; i > 0; i--) {
        if (n % i == 0 && n / i > 1) {
            cout << n / i << "\n";
            for (int j = 0; j < n / i; j++) {
                cout << i << " ";
            }
            return 0;
        }
    }

    cout << 1 << "\n" << n << "\n";
    return 0;
}