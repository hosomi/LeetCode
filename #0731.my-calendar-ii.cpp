class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {

        for (vector<int>& event : v2) {
            if (event[0] < end && event[1] > start) {
                return false;
            }
        }

        for (vector<int>& event : v1) {
            if (event[0] < end && start < event[1]) {
                v2.push_back({std::max(start, event[0]), std::min(end, event[1])});
            }
        }
        v1.push_back({start, end});
        return true;
    }

private:
    vector<vector<int>> v1;
    vector<vector<int>> v2;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
