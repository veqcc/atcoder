#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const double pi = acos(-1.0);

int main() {
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        vector<double> ang;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ang.push_back(atan2(y[j] - y[i], x[j] - x[i]));
            }
        }

        sort(ang.begin(), ang.end());

        double mx = 0.0;
        for (int j = 0; j < n-2; j++) {
            mx = max(mx, ang[j+1] - ang[j]);
        }
        mx = max(mx, ang[0] + 2 * pi - ang[n-2]);

        double res = (mx > pi ? (mx - pi) / (2 * pi) : 0.0);
        cout << res << endl;
    }

    return 0;
}