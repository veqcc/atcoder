#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count[n];
    fill(count, count+n, 0);

    for (int i = 0; i < n; i++) {
        count[a[i]-1]++;
    }

    sort(count, count+n);

    int ans = 0;
    for (int i = 0; i < n-k; i++) {
        ans += count[i];
    }

    cout << ans << endl;
    return 0;
}