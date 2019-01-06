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

    int a, b;
    cin >> a >> b;

    int color[100][100];
    fill(color[0], color[49]+100, 0); // black
    fill(color[50], color[99]+100, 1); // white

    for (int i = 0; i < a-1; i++) {
        color[i/25*2][i%25*2] = 1;
    }

    for (int i = 0; i < b-1; i++) {
        color[99-i/25*2][i%25*2] = 0;
    }

    cout << "100 100\n";
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (color[i][j] == 0) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << "\n";
    }

    return 0;
}