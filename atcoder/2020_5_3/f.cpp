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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    if (a + b + c == 0) {
        cout << "No" << endl;
        return 0;
    }

    vector <char> ans(n);

    bool possible = true;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == "AB") {
            if (a == 0 && b == 0) {
                possible = false;
                break;
            }

            if (s[i] == "AB") {
                if (a == 0) {
                    ans[i - 1] = 'A';
                    a++; b--;
                } else {
                    ans[i - 1] = 'B';
                    a--; b++;
                }
            } else if (s[i] == "BC") {
                if (a == 0) {
                    ans[i - 1] = 'A';
                    a++; b--;
                } else {
                    ans[i - 1] = 'B';
                    a--; b++;
                }
            } else {
                if (b == 0) {
                    ans[i - 1] = 'B';
                    a--; b++;
                } else {
                    ans[i - 1] = 'A';
                    a++; b--;
                }
            }
        } else if (s[i - 1] == "BC") {
            if (c == 0 && b == 0) {
                possible = false;
                break;
            }

            if (s[i] == "BC") {
                if (b == 0) {
                    ans[i - 1] = 'B';
                    b++; c--;
                } else {
                    ans[i - 1] = 'C';
                    b--; c++;
                }
            } else if (s[i] == "AB") {
                if (c == 0) {
                    ans[i - 1] = 'C';
                    b--; c++;
                } else {
                    ans[i - 1] = 'B';
                    b++; c--;
                }
            } else {
                if (b == 0) {
                    ans[i - 1] = 'B';
                    b++; c--;
                } else {
                    ans[i - 1] = 'C';
                    b--; c++;
                }
            }
        } else {
            if (a == 0 && c == 0) {
                possible = false;
                break;
            }

            if (s[i] == "AC") {
                if (a == 0) {
                    ans[i - 1] = 'A';
                    a++; c--;
                } else {
                    ans[i - 1] = 'C';
                    a--; c++;
                }
            } else if (s[i] == "BC") {
                if (a == 0) {
                    ans[i - 1] = 'A';
                    a++; c--;
                } else {
                    ans[i - 1] = 'C';
                    a--; c++;
                }
            } else {
                if (c == 0) {
                    ans[i - 1] = 'C';
                    a--; c++;
                } else {
                    ans[i - 1] = 'A';
                    a++; c--;
                }
            }
        }
    }

    if (s[n - 1] == "AB") {
        if (a == 0) {
            if (b == 0) possible = false;
            ans[n - 1] = 'A';
        } else {
            ans[n - 1] = 'B';
        }
    } else if (s[n - 1] == "BC") {
        if (b == 0) {
            if (c == 0) possible = false;
            ans[n - 1] = 'B';
        } else {
            ans[n - 1] = 'C';
        }
    } else {
        if (c == 0) {
            if (a == 0) possible = false;
            ans[n - 1] = 'C';
        } else {
            ans[n - 1] = 'A';
        }
    }

    if (!possible) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (char x : ans) cout << x << '\n';
    return 0;

    cout << n << "\n";
    return 0;
}