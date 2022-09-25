class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        
         size = k;
    }
    
    bool enQueue(int value) {

        if (li.size() < size) {
            li.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {

        if (li.size() > 0) {
            li.erase(li.begin());
            return true;
        }
        return false;
    }
    
    int Front() {
    
        if (li.size() > 0) {
            return li.front();
        }
        return -1;
    }
    
    int Rear() {
        
        if (li.size() > 0) {
            return li.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        
        return li.size() == 0;
    }
    
    bool isFull() {
        
        return li.size() == size;
    }

private:
    list<int> li;
    int size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
