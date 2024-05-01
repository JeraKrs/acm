class MyHashSet {
public:
    MyHashSet() {
        memset(cnt, 0, sizeof(cnt));
    }
    
    void add(int key) {
        cnt[key]++;
    }
    
    void remove(int key) {
        cnt[key] = 0;
    }
    
    bool contains(int key) {
        return cnt[key] > 0;
    }
    static const int maxn = 1e6+1;
    int cnt[maxn];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
