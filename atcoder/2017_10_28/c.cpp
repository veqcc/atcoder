#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int s_len=S.size(), t_len=T.size();
    string s_copy;

    for (int i = s_len-t_len; i >= 0; i--) {
        s_copy = S;
        bool f = true;

        for (int j = 0; j < t_len; j++) {
            if (s_copy.at(i+j) == T.at(j) || s_copy.at(i+j) == '?') {
                s_copy.at(i+j) = T.at(j);
            } else {
                f = false;
                break;
            }
        }

        if (f) {
            for (int j = 0; j < s_len; j++) {
                if (s_copy.at(j) == '?') {
                    s_copy.at(j) = 'a';
                }
            }

            cout << s_copy << endl;
            return 0;
        }
    }

    cout << "UNRESTORABLE" << endl;
    return 0;
}