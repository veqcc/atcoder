#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);
    cout << a[n-1] << " ";

    int half = lower_bound(a, a+n, a[n-1]/2) - a;

    if (a[min(half, n-2)] - a[n-1]/2 <= a[n-1]/2 - a[max(0, half-1)]) {
        cout << a[min(half, n-2)] <<  endl;
    } else {
        cout << a[max(0, half-1)] << endl;
    }

    return 0;
}