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

    int mx_loss = 0;
    int sm = 0;
    for (int i = 0; i < 5; i++) {
        int time;
        cin >> time;
        sm += time + (10 - time % 10) % 10;
        mx_loss = max(mx_loss, (10 - time % 10) % 10);
    }

    cout << sm - mx_loss << "\n";
    return 0;
}