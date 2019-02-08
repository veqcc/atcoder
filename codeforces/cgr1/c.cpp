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

int largest_divisor(int n) {
    vector <int> vec;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            vec.push_back(i);
            if (i != n / i) {
                vec.push_back(n / i);
            }
        }
    }
    sort(vec.begin(), vec.end());
    return vec[vec.size()-2];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    int ans[q];
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;

        bool f = false;
        int j;
        for (j = 28; j > 0; j--) {
            if (a < 1 << j) continue; // j+1個目のbitが立っていない
            if (__builtin_popcount(a) == j + 1) f = true;
            break;
        }

        if (f) { // 全てのbitが立っている
            ans[i] = largest_divisor(a);
        } else {
            ans[i] = (1 << (j+1)) - 1;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}