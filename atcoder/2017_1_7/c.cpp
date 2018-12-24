#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    for (int i = 0; i < ty - sy; i++) cout << "U";
    for (int i = 0; i < tx - sx; i++) cout << "R";
    for (int i = 0; i < ty - sy; i++) cout << "D";
    for (int i = 0; i < tx - sx; i++) cout << "L";

    cout << "L";
    for (int i = 0; i <= ty - sy; i++) cout << "U";
    for (int i = 0; i <= tx - sx; i++) cout << "R";
    cout << "DR";
    for (int i = 0; i <= ty - sy; i++) cout << "D";
    for (int i = 0; i <= tx - sx; i++) cout << "L";
    cout << "U";

    return 0;
}