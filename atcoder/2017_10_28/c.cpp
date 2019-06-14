#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int Slen = S.size(), Tlen = T.size();
    string ans = "";

    for (int i = Slen - Tlen; i >= 0; i--) {
        string Scopy = S;
        bool restorable = true;

        for (int j = 0; j < Tlen; j++) {
            if (Scopy[i+j] == T[j] || Scopy[i+j] == '?') {
                Scopy[i+j] = T[j];
            } else {
                restorable = false;
                break;
            }
        }

        if (restorable) {
            for (int j = 0; j < Slen; j++) {
                if (Scopy[j] == '?') {
                    Scopy[j] = 'a';
                }
            }

            if (ans == "") {
                ans = Scopy;
            } else {
                ans = min(ans, Scopy);
            }
        }
    }

    if (ans == "") {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << ans << "\n";
    }

    return 0;
}