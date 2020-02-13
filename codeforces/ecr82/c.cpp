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

struct S {
    int next, back;
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;

        bool possible = true;
        vector <S> alphabet(26, S{-1, -1});
        for (int i = 0; i < s.size() - 1; i++) {
            int a = s[i] - 'a';
            int b = s[i + 1] - 'a';

            if (alphabet[a].next == b) {
            } else if (alphabet[b].next == a) {
            } else if (alphabet[a].next == -1 && alphabet[b].back == -1) {
                alphabet[a].next = b;
                alphabet[b].back = a;
            } else if (alphabet[a].back == -1 && alphabet[b].next == -1) {
                alphabet[a].back = b;
                alphabet[b].next = a;
            } else {
                possible = false;
                break;
            }
        }

        if (s.size() == 1) {
            cout << "YES\n";
            cout << "abcdefghijklmnopqrstuvwxyz\n";
            continue;
        }

        if (!possible) {
            cout << "NO\n";
            continue;
        }

        int cur = -1;
        for (int i = 0; i < 26; i++) {
            if (alphabet[i].back == -1 && alphabet[i].next != -1) {
                cur = i;
                break;
            }
        }

        if (cur == -1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        while (cur != -1) {
            cout << char('a' + cur);
            cur = alphabet[cur].next;
        }

        for (int i = 0; i < 26; i++) {
            if (alphabet[i].back == -1 && alphabet[i].next == -1) {
                cout << char('a' + i);
            }
        }

        cout << '\n';
    }
    ;
    return 0;
}