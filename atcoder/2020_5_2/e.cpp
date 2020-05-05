#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int left = n / 2 / 2;
    int right = n / 2 + (n / 2 / 2);

    int l = 1, r = 2;
    if ((n / 2) % 2 == 1 && n % 2 == 1) {
        l = 2, r = 1;
        right++;
    }

    for (; l <= m; l += 2) {
        cout << left << ' ' << left + l << '\n';
        left--;
    }

    for (; r <= m; r += 2) {
        cout << right << ' ' << right + r << '\n';
        right--;
    }

    return 0;
}