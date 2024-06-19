class NumberContainers {
public:
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if (_indexs.find(index) != _indexs.end()) {
            _containers[_indexs[index]].erase(index);
        }
        _indexs[index] = number;
        _containers[number].insert(index);
    }
    
    int find(int number) {
        if (_containers.find(number) == _containers.end()) {
            return -1;
        }
        auto iter = _containers[number].begin();
        if (iter == _containers[number].end()) {
            return -1;
        }
        return *iter;
    }
private:
    std::map<int, std::set<int> > _containers;
    std::map<int, int> _indexs;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
