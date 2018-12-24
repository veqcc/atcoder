#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (abs(x-y) % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }

    int diff = abs(x - y);
    if (x > y) {
        x = x - (diff/2) * 3;
        y = y - diff/2;
    } else if (y > x) {
        x = x - diff/2;
        y = y - (diff/2) * 3;
    }

    if (x >= 0 && y >= 0 && x % 4 == 0 && y % 4 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}