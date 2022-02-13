class SnapshotArray {
public:
    SnapshotArray(int length) {

        snap_id = 0;
    }

    void set(int index, int val) {

        if(obj[index].empty() || obj[index].back().first != snap_id)
            obj[index].push_back({snap_id, val});
        else
            obj[index].back().second = val;
    }
    
    int snap() {

        return snap_id++;
    }
    
    int get(int index, int snap_id) {

        auto it = upper_bound(obj[index].begin(),
            obj[index].end(), pair<int, int>(snap_id, INT_MAX));
        return it == obj[index].begin() ? 0 : prev(it)->second;
    }

private:
    int snap_id;
    map<int, vector<pair<int, int>>> obj;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
