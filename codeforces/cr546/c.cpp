#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> A[n+m-1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            A[i+j].push_back(x);
        }
    }

    vector <int> B[n+m-1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            B[i+j].push_back(x);
        }
    }

    bool possible = true;
    for (int i = 0; i < n+m-1; i++) {
        sort(A[i].begin(), A[i].end());
        sort(B[i].begin(), B[i].end());
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] != B[i][j]) possible = false;
        }
    }

    if (possible) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}