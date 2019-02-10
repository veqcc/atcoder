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

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) {
            return X - Y;
        } else {
            if (Y % 2 == 1) {
                return 2 + brokenCalc(X, (Y+1)/2);
            } else {
                return 1 + brokenCalc(X, Y/2);
            }
        }
    }
};

int main() {
    Solution so;
    int x, y;
    cin >> x >> y;
    cout << so.brokenCalc(x,y) << "\n";
    return 0;
}
