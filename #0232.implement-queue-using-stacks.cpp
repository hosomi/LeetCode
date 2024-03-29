class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {

        stack<int> st;
        while (!s.empty()) {
            st.push(s.top());
            s.pop();
        }

        s.push(x);
        while (!st.empty()) {
            s.push(st.top());
            st.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        int i = s.top();
        s.pop();
        return i;
    }

    /** Get the front element. */
    int peek() {

        return s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {

        return s.empty();
    }

private:
    stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
