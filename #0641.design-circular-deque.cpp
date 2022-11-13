class MyCircularDeque {
public:
    MyCircularDeque(int k) {

        q = vector<int>(k, -1);
        head = k - 1;
        tail = 0;
        size = 0;
    }
    
    bool insertFront(int value) {

        if (isFull()) {
            return false;
        }

        q[head] = value;
        head = (head - 1 + q.size()) % q.size();
        size++;
        return true;
    }
    
    bool insertLast(int value) {

        if (isFull()) {
            return false;
        }

        q[tail] = value;
        tail = (tail + 1) % q.size();
        size++;
        return true;
    }
    
    bool deleteFront() {

        if (isEmpty()) {
            return false;
        }

        head = (head + 1) % q.size();
        q[head] = -1;
        size--;
        return true;
    }
    
    bool deleteLast() {

        if (isEmpty()) {
            return false;
        }

        int temp = q.size();
        tail = (tail - 1 + temp) % temp;
        q[tail] = -1;
        size--;
        return true;
    }
    
    int getFront() {

        return q[(head + 1) % q.size()];
    }
    
    int getRear() {

        int temp = q.size();
        return q[(tail - 1 + temp) % temp];
    }
    
    bool isEmpty() {

        return size == 0;
    }
    
    bool isFull() {

        return size == q.size();
    }

private:
    vector<int> q;
    int head;
    int tail;
    int size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
