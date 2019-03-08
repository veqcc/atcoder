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
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h1, m1, h2, m2;
    char c1, c2;
    cin >> h1 >> c1 >> m1 >> h2 >> c2 >> m2;

    int mid = (60 * h1 + m1 + 60 * h2 + m2) / 2;

    cout << setw(2) << setfill('0') << mid / 60 << ':';
    cout << setw(2) << setfill('0') << mid % 60 << '\n';

    return 0;
}