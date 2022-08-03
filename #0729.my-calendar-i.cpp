class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        auto it = myCalendar.upper_bound(start);
        int prev = (it != myCalendar.begin()) ? (--it)->first : -1;
        it = myCalendar.lower_bound(start);
        int next = (it != myCalendar.end()) ? it->first : -1;
        if ((prev == -1 || myCalendar[prev] <= start)
           && (next == -1 || end <= next)) {
            myCalendar[start] = end;
            return true;
        }
        return false;
    }

private:
    map<int, int> myCalendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
