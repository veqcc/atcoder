#include <functional>
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
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <double> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    double l = 0, r = 1000;
    while (r - l > 1e-10) {
        double R = (l + r) / 2;

        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double distance = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) / 2;
                if (R < distance) continue;

                double h = sqrt(R * R - distance * distance);
                double x_vector = y[j] - y[i];
                double y_vector = x[i] - x[j];
                double vector_length = sqrt(x_vector * x_vector + y_vector * y_vector);

                for (int dir = 1; dir > -2; dir -= 2) {
                    double X = (x[i] + x[j]) / 2 + dir * x_vector * h / vector_length;
                    double Y = (y[i] + y[j]) / 2 + dir * y_vector * h / vector_length;

                    bool all_in = true;
                    for (int k = 0; k < n; k++) {
                        if ((X - x[k]) * (X - x[k]) + (Y - y[k]) * (Y - y[k]) > R * R + 1e-8) {
                            all_in = false;
                            break;
                        }
                    }

                    if (all_in) {
                        ok = true;
                        break;
                    }
                }

                if (ok) break;
            }

            if (ok) break;
        }

        if (ok) {
            r = R;
        } else {
            l = R;
        }
    }

    cout << fixed << setprecision(10) << l << "\n";
    return 0;
}