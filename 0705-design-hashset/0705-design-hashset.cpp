class MyHashSet {
private:
    int size;
    std::vector<std::list<int>> buckets;

public:
    MyHashSet() {
        size = 1000;
        buckets = std::vector<std::list<int>>(size);
    }

    void add(int key) {
        int index = hash(key);
        std::list<int>& bucket = buckets[index];
        if (!contains(key, bucket)) {
            bucket.push_back(key);
        }
    }

    void remove(int key) {
        int index = hash(key);
        std::list<int>& bucket = buckets[index];
        bucket.remove(key);
    }

    bool contains(int key) {
        int index = hash(key);
        std::list<int>& bucket = buckets[index];
        return contains(key, bucket);
    }

private:
    int hash(int key) {
        return key % size;
    }

    bool contains(int key, std::list<int>& bucket) {
        for (int num : bucket) {
            if (num == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */