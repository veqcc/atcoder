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
    int T, B, N;
    cin >> T >> B;
    for (int i = 0; i < T; i++) {
        cin >> N;
        string ans = "";
        while (true) {
            int p = N / B;
            int q = N % B;
            if (q < 0) {
                p++;
                q -= B;
            }
            ans = to_string(q) + ans;
            if (p == 0) break;
            N = p;
        }
        cout << ans << "\n";
    }

    return 0;
}