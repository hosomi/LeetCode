class FreqStack {
public:
    FreqStack() {

        max = 0;
    }
    
    void push(int val) {

        int v = m[val] + 1;
        m[val] = v;
        max = std::max(max, v);
        stacks[v].push(val);
    }

    int pop() {

        int x = stacks[max].top(); stacks[max].pop();
        m[x]--;
        if (stacks[max].size() == 0) {
            max--;
        }
        return x;
    }

private:
    map<int, int> m;
    map<int, stack<int>> stacks;
    int max;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
