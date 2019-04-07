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

    int antenna[5], k;
    for (int i = 0; i < 5; i++) cin >> antenna[i];
    cin >> k;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (antenna[j] - antenna[i] > k) {
                cout << ":(\n";
                return 0;
            }
        }
    }

    cout << "Yay!\n";
    return 0;
}