class Trie {
public:
    struct Node {
        Node() {
            v = 0;
            memset(next, -1, sizeof(next));
        }
        int v;
        int next[26];
    };

    Trie() {
        root = nodes.size();
        nodes.emplace_back(Node());
    }
    
    void insert(string word) {
        int mov = root;
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
        int mov = root;
        for (int i = 0;i < word.size(); ++i) {
            int e = word[i] - 'a';
            if (nodes[mov].next[e] == -1) {
                return false;
            }
            mov = nodes[mov].next[e];
        }
        return nodes[mov].v == 1;
    }
    
    bool startsWith(string prefix) {
        int mov = root;
        for (int i = 0;i < prefix.size(); ++i) {
            int e = prefix[i] - 'a';
            if (nodes[mov].next[e] == -1) {
                return false;
            }
            mov = nodes[mov].next[e];
        }
        return true;
    }

    int root;
    vector<Node> nodes;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
