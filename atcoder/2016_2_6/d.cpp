#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef long double ld;
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-10;

int main() {
    ll n;
    cin >> n;

    double x[n], y[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    ll obtuse = 0, right = 0;
    for (int i = 0; i < n; i++) {
        vector <double> angs;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            angs.push_back(atan2(y[j] - y[i], x[j] - x[i]));
        }

        sort(angs.begin(), angs.end());
        angs.push_back(1e20L);

        ll r90 = 1, r270 = 1;
        for (int j = 0; j < n-1; j++) {
            while (true) {
                double t = angs[r90] - angs[j] - PI / 2;
                if (abs(t) < EPS) {
                    right++;
                    r90++;
                } else if (t < 0.0) {
                    r90++;
                } else {
                    break;
                }
            }

            while (true) {
                double t = angs[r270] - angs[j] - PI * 3 / 2;
                if (abs(t) < EPS) {
                    right++;
                    obtuse--;
                    r270++;
                } else if (t < 0.0) {
                    r270++;
                } else {
                    break;
                }
            }

            obtuse += r270 - r90;
        }
    }

    ll acute = n * (n - 1) * (n - 2) / 6 - obtuse - right;
    cout << acute << " " << right << " " << obtuse<< "\n";
    return 0;
}