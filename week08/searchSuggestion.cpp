class Solution {
public:
    class TrieNode {
        public: 
            bool isEnd;
            TrieNode* next[26];
            TrieNode() {
                for (int i = 0; i < 26; ++i) {
                    next[i] = nullptr;
                }
                isEnd = false;
            }
    };
    class Trie {
        public: 
            TrieNode* root;
            Trie() {
                root = new TrieNode();
            }
            void insert(string &word) {
                auto curr = root;
                for (auto &ch : word) {
                    int rnk = ch - 'a';
                    if (curr -> next[rnk] == nullptr) {
                        curr -> next[rnk] = new TrieNode();
                    }
                    curr = curr -> next[rnk];
                }
                curr -> isEnd = true;
            }
    };

    Trie* buildTrie(vector<string> &products) {
        Trie* trie = new Trie();
        for (auto &product : products) {
            trie -> insert(product);
        }
        return trie;
    }

    void dfs (TrieNode* root, string &prefix, vector<string> &result) {
        if (root == nullptr || result.size() == 3) return;
        if (root -> isEnd) {
            result.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (root -> next[i] == nullptr) continue;
            prefix.push_back((char)(i + 'a'));
            dfs(root -> next[i], prefix, result);
            prefix.pop_back();
        }
    }

    // TC: O(n * m) where, n = |searchWord|, m = |products|
    // SC: O(n * m)
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto trie = buildTrie(products);
        vector<vector<string>> suggestions;

        auto currNode = trie -> root;
        string prefix = "";

        for (auto &ch : searchWord) {
            prefix.push_back(ch);
            currNode = currNode ? currNode -> next[ch - 'a'] : nullptr;
            vector<string> result;
            dfs(currNode, prefix, result);
            suggestions.push_back(result);
        }

        return suggestions;
    }
};