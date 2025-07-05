class MyHashSet {
    vector<int> arr;
    int n;
public:
    MyHashSet() {
        n = 15000;
        arr.resize(n, -1);
    }
    
    int getIndex(int key) {
        return key % n;
    }

    void add(int key) {
        int index = getIndex(key);
        int start = index;
        while (arr[index] != -1 && arr[index] != -2 && arr[index] != key) {
            index = (index + 1) % n;
            if (index == start) return; // full
        }
        arr[index] = key;
    }
    
    void remove(int key) {
        int index = getIndex(key);
        int start = index;
        while (arr[index] != -1) {
            if (arr[index] == key) {
                arr[index] = -2; // tombstone marker for deleted
                return;
            }
            index = (index + 1) % n;
            if (index == start) break;
        }
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        int start = index;
        while (arr[index] != -1) {
            if (arr[index] == key)
                return true;
            index = (index + 1) % n;
            if (index == start) break;
        }
        return false;
    }
};
