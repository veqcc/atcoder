class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();

        map <int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[A[i]]++;
            if (A[i] != B[i]) mp[B[i]]++;
        }

        int num = -1;
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            if (itr->second == n) num = itr->first;
        }

        if (num == -1) return -1;

        int Acnt = 0, Bcnt = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != num) Acnt++;
            if (B[i] != num) Bcnt++;
        }

        return min(Acnt, Bcnt);
    }
};