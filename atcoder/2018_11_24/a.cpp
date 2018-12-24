#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int ave = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ave += a[i];
    }

    int min = 1000000000;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (abs(a[i]*n - ave) < min) {
            min = abs(a[i]*n - ave);
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}