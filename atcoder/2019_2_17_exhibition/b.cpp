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
    int n;
    cin >> n;

    int ans = 1;
    while (ans * ans <= n) {
        ans++;
    }

    cout << ans - 1 << "\n";
    return 0;
}