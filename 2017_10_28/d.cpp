#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include<iomanip>
typedef long long ll;
using namespace std;

double t[105], v[105], sum[105];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i+1];
        sum[i+1] = sum[i] + t[i+1];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i+1];
    }

    double ans=0, p=0;
    int f = 0;

    for (double i = 0.5; i <= sum[n]; i+=0.5) {
        if (i > sum[f]) f++;
        double now = v[f];
        for (int j = 0; j <= n+1; j++) {
            double c = now;
            if (j < f) {
                c = v[j] + i - sum[j];
            } else if (j > f) {
                c = v[j] + sum[j-1] - i;
            }
            now = min(now, c);
        }
        ans += (p+now)/4.0;
        p = now;
    }

    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}