#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    int A[n];
    int mn = 1 << 30;
    int dif = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        mn = min(mn, A[i]);
        if (A[i] - mn > dif) {
            dif = A[i] - mn;
            count = 1;
        } else if (A[i] - mn == dif) {
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}