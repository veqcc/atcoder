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
    vector<int> x(5);
    for (int i = 0; i < 5; i++) {
        cin >> x[i];
        if (x[i] == 0) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}