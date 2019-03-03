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
    bool isValid(string S) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == 'a') a++;
            if (S[i] == 'b') {
                if (a == 0) return false;
                a--; b++;
            }
            if (S[i] == 'c') {
                if (b == 0) return false;
                b--; c++;
            }
        }

        if (a == 0 && b == 0 && c == S.size() / 3) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    return 0;
}