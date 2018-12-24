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
    int n, m;
    cin >> n >> m;

    int s[n];
    fill(s, s+n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        s[a-1]++;
        s[b-1]++;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}