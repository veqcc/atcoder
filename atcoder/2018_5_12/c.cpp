#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int k, length, pointer;
string S, s[100005];

int main()
{
    cin >> S >> k;
    length = S.size();

    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j <= length-i; j++) {
            s[pointer++] = S.substr(j,i);
        }
    }

    sort(s, s+pointer);
    unique(s, s+ pointer);

    cout << s[k-1];
    return 0;
}