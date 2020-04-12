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
        int n;
        cin >> n;

        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        vector<string> front, middle, back;
        for (int i = 0; i < n; i++) {
            int from = 0;
            for (int j = 0; j < s[i].size(); j++) {
                if (s[i][j] == '*') {
                    if (j > from) {
                        front.push_back(s[i].substr(0, j));
                        from = j;
                    }
                    break;
                }
            }

            int goal = s[i].size() - 1;
            for (int j = s[i].size() - 1; j >= 0; j--) {
                if (s[i][j] == '*') {
                    if (j < goal) {
                        back.push_back(s[i].substr(j + 1, goal - j));
                        goal = j;
                    }
                    break;
                }
            }

            string str = "";
            for (int j = from; j <= goal; j++) {
                if (s[i][j] == '*') {
                    if (str.size() > 0) {
                        middle.push_back(str);
                        str = "";
                    }
                } else {
                    str += s[i][j];
                }
            }
        }

        bool possible = true;

        string start = "";
        int s_len = 0;
        for (string str : front) {
            if (str.size() > s_len) {
                start = str;
                s_len = str.size();
            }
        }
        for (string str : front) {
            for (int j = 0; j < s_len; j++) {
                if (str.size() <= j) break;
                if (str[j] == '*') break;
                if (str[j] != start[j]) possible = false;
            }
        }

        string goal = "";
        int g_len = 0;
        for (string str : back) {
            if (str.size() > g_len) {
                goal = str;
                g_len = str.size();
            }
        }
        for (string str : back) {
            int len = str.size() - 1;
            for (int j = 0; j < g_len; j++) {
                if (str.size() <= j) break;
                if (str[len - j] == '*') break;
                if (str[len - j] != goal[goal.size() - j - 1]) possible = false;
            }
        }

        cout << "Case #" << t << ": ";

        if (possible) {
            cout << start;
            for (string str : middle) cout << str;
            cout << goal;
        } else {
            cout << '*';
        }

        cout << endl;
    }

    return 0;
}