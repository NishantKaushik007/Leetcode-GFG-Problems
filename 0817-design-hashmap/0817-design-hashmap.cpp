class MyHashMap {
    vector<list<pair<int,int>>>buckets;
    int size=1000;
public:
    MyHashMap() {
        buckets.resize(size);
    }

    int getIndex(int key)
    {
        return key%size;
    }
    
    void put(int key, int value) {
        int bucketNo=getIndex(key);
        auto& chain=buckets[bucketNo];
        for(auto& it:chain)
        {
            if(key==it.first)
            {
                it.second=value;
                return;
            }
        }
        chain.emplace_back(make_pair(key,value));
    }
    
    int get(int key) {
        int bucketNo=getIndex(key);
        auto& chain=buckets[bucketNo];
        if(chain.empty())
        return -1;
        for(auto& it:chain)
        {
            if(key==it.first)
            {
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int bucketNo=getIndex(key);
        auto& chain=buckets[bucketNo];
        for(auto it=chain.begin();it!=chain.end();it++)
        {
            if(key==it->first)
            {
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */