#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    int tmp;
    int ans = 0;
    fill(a, a+n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp > n) {
            ans++;
        } else {
            a[tmp-1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= i+1) {
            ans += a[i] - i -1;
        } else {
            ans += a[i];
        }
    }

    cout << ans << endl;
    return 0;
}