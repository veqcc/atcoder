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
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s;

    int gender[N+1];
    fill(gender, gender+N+1, 0);

    cout << 0 << endl;
    cin >> s;
    if (s == "Male") {
        gender[0] = gender[N] = 1;
    } else if (s == "Female") {
        gender[0] = gender[N] = 2;
    } else {
        return 0;
    }

    int l = N, r = 0;

    while (true) {
        int p = (l + r) / 2;
        cout << p << endl;
        cin >> s;
        if (s == "Male") {
            gender[p] = 1;
        } else if (s == "Female") {
            gender[p] = 2;
        } else {
            return 0;
        }

        if ((p - r) % 2 == 1) {
            if (gender[r] == gender[p]) {
                l = p;
            } else {
                r = p;
            }
        } else {
            if (gender[r] == gender[p]) {
                r = p;
            } else {
                l = p;
            }
        }
    }
}