#include <algorithm>
#include <iostream>
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

    int n;
    cin >> n;
    int a=0, b=0, c=0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p == 1) a++;
        if (p == 2) b++;
        if (p == 3) c++;
    }

    double dp[a+1][b+1][c+1];
    fill(dp[0][0], dp[a][b]+c+1, 0.0);

    cout << n << "\n";
    return 0;
}