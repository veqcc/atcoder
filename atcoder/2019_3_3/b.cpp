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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, k;
    cin >> a >> b >> k;

    int cnt = 0;
    for (int i = 100; i >= 1; i--) {
        if (i > a || i > b) continue;
        if (a % i == 0 && b % i == 0) {
            cnt++;
            if (cnt == k) {
                cout << i << '\n';
                return 0;
            }
        }
    }

    return 0;
}