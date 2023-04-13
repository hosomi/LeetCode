class MyLinkedList {
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        
        auto node = getNode(index);
        if (node == nullptr) {
            return -1;
        }
        
        return node->val;
    }
    
    void addAtHead(int val) {
        
        auto new_node = new ListNode(val);
        
        new_node->next = _head;
        _head = new_node;
    }
    
    void addAtTail(int val) {

        if (_head == nullptr) {
            addAtHead(val);
            return;
        }
        
        auto current = _head;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        current->next = new ListNode(val);   
    }
    
    void addAtIndex(int index, int val) {
        
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        auto new_node = new ListNode(val);

        auto node = getNode(index - 1);
        if (node == nullptr) {
            return;
        }
        new_node->next = node->next;
        node->next = new_node;
    }
    
    void deleteAtIndex(int index) {
        
        auto curr = getNode(index);
        if (curr == nullptr) {
            return;
        }
        if (index == 0) {
            _head = curr->next; 
            delete curr;
            return;
        }
        
       auto prev = getNode(index - 1);
        if (prev == nullptr) {
            return;
        }
        
        prev->next = curr->next;
        delete curr;
    }

private:
    ListNode* _head = nullptr;

    ListNode* getNode(int index) {
        ListNode* current = _head;
        
        while(current != nullptr && index > 0) {
            --index;
            current = current->next;
        }
        
        if (index < 0) {
            return nullptr;
        }
        
        return current;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
