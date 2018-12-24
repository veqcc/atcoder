#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int ans = n;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            a[i] = 0;
            ans -= 2;
        }
    }

    cout << ans << endl;
    return 0;
}