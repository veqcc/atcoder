#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// TrieNode
//   count: このnode以下にいくつ単語が格納されているか
//   accept: このnodeでぴったりのものindexの集合

// Trie
//   プレフィックス木とも。ルートには空文字が対応

// add(s, str_i, node_i, id)
//   sをTrieに追加する
//   計算量は O(|S|)

// query(s, fun, str_i, node_i)
//   sをi文字目から読んでいき、それに沿ってTrie木をたどる。
//   たどるNodeごとに、関数funを適用する。
//   計算量は O(|S|)

template <int char_size>
struct TrieNode {
    int count;
    vector <int> nxt, accept;
    TrieNode() : count(0) {
        nxt.assign(char_size + 1, -1);
    }
};

template <int char_size, int base>
class Trie {
    using Node = TrieNode <char_size>;

    vector <Node> nodes;

    void add(const string &s, int str_i, int node_i, int id) {
        if (str_i == s.size()) {
            nodes[node_i].accept.push_back(id);
        } else {
            const int c = s[str_i] - base;
            if (nodes[node_i].nxt[c] == -1) {
                nodes[node_i].nxt[c] = nodes.size();
                nodes.push_back(Node());
            }
            add(s, str_i + 1, nodes[node_i].nxt[c], id);
            nodes[node_i].count++;
        }
    }

public:
    Trie() { nodes.push_back(Node()); }

    void add(const string &s) {
        add(s, 0, 0, nodes[0].count);
    }

    void query(const string &s, const function<void(int)> &f, int str_i, int node_i) {
        for (auto &idx : nodes[node_i].accept) f(idx);
        if (str_i < s.size()) {
            const int c = s[str_i] - base;
            if (nodes[node_i].nxt[c] >= 0) {
                query(s, f, str_i + 1, nodes[node_i].nxt[c]);
            }
        }
    }
};


// verified
//   https://tenka1-2016-final-open.contest.atcoder.jp/tasks/tenka1_2016_final_c

void AtCoder_2016_9_10_C() {
    string s;
    int m;
    cin >> s >> m;
    Trie<26, 'a'> trie;
    string p[5005];
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        trie.add(p[i]);
    }
    int w[5005];
    for (int i = 0; i < m; i++) cin >> w[i];
    int sz = s.size();
    vector <int> dp(sz + 1);
    for (int i = 0; i < sz; i++) {
        auto update = [&](int idx) {
            dp[i + p[idx].size()] = max(dp[i + p[idx].size()], dp[i] + w[idx]);
        };
        trie.query(s, update, i, 0);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    cout << dp.back() << "\n";
}


// verified
//   https://yukicoder.me/problems/no/430

void yuki_430() {
    string s;
    int m;
    cin >> s >> m;
    Trie<26, 'A'> trie;
    string c[5005];
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        trie.add(c[i]);
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        auto update = [&](int idx) { ans++; };
        trie.query(s, update, i, 0);
    }
    cout << ans << '\n';
}

int main() {
    // AtCoder_2016_9_10_C();
    yuki_430();
    return 0;
}