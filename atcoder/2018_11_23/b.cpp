#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    bool p[2*n+1][2*n+1];
    fill(p[0], p[2*n+1], false);

    for (int i = 0; i <= 2*n; i+=2) {
        for (int j = 0; j <= 2*n; j+=2) {
            if (abs(-n+i) + abs(-n+j) <= n) {
                p[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2*n; i+=2) {
        for (int j = 0; j < 2*n; j += 2) {
            if (p[i][j] == true && p[i+2][j] == true && p[i][j+2] == true && p[i+2][j+2] == true) {
                ans++;
            }
        }
    }


    cout << ans << endl;
    return 0;
}