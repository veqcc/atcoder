#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=2000;

int N;
string s;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> s;

    int f = 0, b = N-1;

    while (f <= b) {
        bool left = false;
        for (int i = 0; f+i <= b-i; i++) { // f+i <= b ???
            if (s[f+i] < s[b-i]) {
                left = true;
                break;
            } else if (s[f+i] > s[b-i]) {
                left = false;
                break;
            }
        }

        if (left) {
            cout << s[f++];
        } else  {
            cout << s[b--];
        }
    }

    return 0;
}