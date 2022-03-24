class WordDictionary {
public:
    struct Node {
        int v;
        int next[26];
        Node() {
            v = 0;
            memset(next, -1, sizeof(next));
        }
    };
    WordDictionary() {
        nodes.emplace_back(Node());
    }
    
    void addWord(string word) {
        int mov = 0;
        for (int i = 0; i < word.size(); ++i) {
            int e = word[i] - 'a';
            if (nodes[mov].next[e] == -1) {
                nodes[mov].next[e] = nodes.size();
                nodes.emplace_back(Node());
            }
            mov = nodes[mov].next[e];
        }
        nodes[mov].v = 1;
    }
    
    bool search(string word) {
        return isFind(0, 0, word);
    }

private:
    bool isFind(int mov, int s, const string& word) {
        for (int i = s; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (nodes[mov].next[j] != -1) {
                        if (isFind(nodes[mov].next[j], i + 1, word)) {
                            return true;
                        }
                    }
                }
                return false;
            }

            int e = word[i] - 'a';
            if (nodes[mov].next[e] == -1) {
                return false;
            }
            mov = nodes[mov].next[e];
        }
        return nodes[mov].v == 1;
    }
    vector<Node> nodes;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
