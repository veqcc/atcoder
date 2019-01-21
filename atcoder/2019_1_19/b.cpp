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
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, k, r;
    cin >> n >> k >> r;

    int a[n];
    int front = 0;
    int back = n-1;

    ll check = r;
    for (int i = 1; i <= n; i++) {
        if (check < 0 || n - k - i + 1 <= 0) break;
        check -= n - k - i + 1;
    }

    if (check > 0) {
        cout << "No Luck" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (r > 0 && n - k - i + 1 > 0 && r >= n - k - i + 1) {
            a[back] = i;
            back--;
            r -= n - k - i + 1;
        } else {
            a[front] = i;
            front++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}