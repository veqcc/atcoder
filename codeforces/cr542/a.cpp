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
    int n;
    cin >> n;

    int a[n];
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) pos++;
        if (a[i] < 0) neg++;
    }

    int m = n / 2 + n % 2;

    if (pos >= m) {
        cout << 1 << "\n";
    } else if (neg >= m) {
        cout << -1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}