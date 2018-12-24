#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n, tmp, sm=0, mn=101;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sm += tmp;
        if (tmp % 10 != 0) {
            mn = min(mn, tmp);
        }
    }

    if (sm % 10 == 0) {
        if (mn == 101) {
            cout << 0 << endl;
        } else {
            cout << sm - mn << endl;
        }
    } else {
        cout << sm << endl;
    }

    return 0;
}