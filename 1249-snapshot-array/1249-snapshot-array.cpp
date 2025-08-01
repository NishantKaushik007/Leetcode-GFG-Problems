class SnapshotArray {
    int snaps;
    vector<vector<pair<int,int>>>vec;
public:
    SnapshotArray(int length) {
        snaps=0;
        vec.resize(length);
        for(int i=0;i<length;i++)
        vec[i].push_back(make_pair(0,0));
    }
    
    void set(int index, int val) {
        vec[index].push_back(make_pair(snaps,val));
    }
    
    int snap() {
        return snaps++;
    }
    
    int get(int index, int snap_id) {
        auto it=upper_bound(begin(vec[index]),end(vec[index]),make_pair(snap_id,INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */