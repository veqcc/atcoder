#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n, greater<long>());

    vector<long> sides;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            sides.push_back(a[i]);
            i++;
        }
    }

    if (sides.size() < 2) {
        cout << 0 << endl;
    } else {
        cout << sides[0] * sides[1] << endl;
    }

    return 0;
}