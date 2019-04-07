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

    int n, m;
    cin >> n >> m;

    int A[n][m], B[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int sm = 0;
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                sm++;
            }
        }

        if (sm % 2 == 1) {
            cout << "No\n";
            return 0;
        }
    }

    for (int j = 0; j < m; j++) {
        int sm = 0;
        for (int i = 0; i < n; i++) {
            if (A[i][j] != B[i][j]) {
                sm++;
            }
        }

        if (sm % 2 == 1) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}