#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int A[n], B[n], C[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) cin >> C[i];

    sort(A, A+n);
    sort(C, C+n);

    long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (lower_bound(A, A+n, B[i]) - A) * (C + n - upper_bound(C, C + n, B[i]));
    }

    cout << ans << endl;
    return 0;
}