class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {

        st.push(x);
        if (stmin.empty() || x <= stmin.top()) {
            stmin.push(x);
        }
    }

    void pop() {

        int top = st.top();
        st.pop();
        if (top == stmin.top()) {
            stmin.pop();
        }
    }

    int top() {

        return st.top();
    }

    int getMin() {

        return stmin.top();
    }

private:
    stack<int> st;
    stack<int> stmin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
