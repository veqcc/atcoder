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

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        ll X, Y;
        cin >> X >> Y;

        bool possible = true;

        ll x = abs(X);
        ll y = abs(Y);

        vector <char> ans;
        for (int i = 0; i < 32; i++) {
            ll bit = 1LL << i;
            if (x & bit) {
                if (y & bit) {
                    possible = false;
                } else {
                    ll nxt_bit = 1LL << (i + 1);
                    if (y & nxt_bit) {
                        if ((x + bit) & nxt_bit) {
                            x -= bit;
                            ans.push_back('E');
                        } else {
                            x += bit;
                            ans.push_back('W');
                        }
                    } else {
                        if ((x + bit) & nxt_bit) {
                            if (x - bit == 0 && y == 0) {
                                ans.push_back('E');
                                break;
                            }
                            x += bit;
                            ans.push_back('W');
                        } else {
                            x -= bit;
                            ans.push_back('E');
                        }
                    }
                }
            } else {
                if (y & bit) {
                    ll nxt_bit = 1LL << (i + 1);
                    if (x & nxt_bit) {
                        if ((y + bit) & nxt_bit) {
                            y -= bit;
                            ans.push_back('N');
                        } else {
                            y += bit;
                            ans.push_back('S');
                        }
                    } else {
                        if ((y + bit) & nxt_bit) {
                            if (x == 0 && y - bit == 0) {
                                ans.push_back('N');
                                break;
                            }
                            y += bit;
                            ans.push_back('S');
                        } else {
                            y -= bit;
                            ans.push_back('N');
                        }
                    }
                } else {
                    possible = false;
                }
            }
        }

        cout << "Case #" << t << ": ";

        if (possible) {
            for (char c : ans) {
                if (X < 0 && c == 'E') c = 'W';
                else if (X < 0 && c == 'W') c = 'E';
                else if (Y < 0 && c == 'N') c = 'S';
                else if (Y < 0 && c == 'S') c = 'N';

                cout << c;
            }
            cout << '\n';
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}