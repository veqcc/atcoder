#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n;
    bool is_all_even = true;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 1) {
            is_all_even = false;
        }
    }

    if (is_all_even) {
        cout << "second" << endl;
    } else {
        cout << "first" << endl;
    }

    return 0;
}