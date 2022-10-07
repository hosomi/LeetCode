class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {

		int second = 0;
		int max = 0;

        ++calendar[start];
		--calendar[end];
		for (auto iter = calendar.begin(); iter != calendar.end(); ++iter) {
			second += iter->second;
			max = std::max(max, second);
		}
		return max;
    }

private:
	map<int,int> calendar;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
