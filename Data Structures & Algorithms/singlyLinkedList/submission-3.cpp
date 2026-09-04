class LinkedList {
private:
    struct Node {
        Node* next = nullptr; 
        int val = 0; 
        Node(int v) : val(v) {}
    };

    Node* DummyFront = new Node(-1);
    Node* DummyBack = new Node(-1);
    int size = 0;

public:
    LinkedList() {
        
    }

    int get(int index) {
        if (index > size || size < 1) return -1; 
        Node* current = DummyFront->next;
        for (int i = 0; i < index; i++) {
            current = current->next; 
        }
        return current->val;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (DummyFront->next) {
            newNode->next = DummyFront->next; 
        } 
        else {
            newNode->next = DummyBack;
        }
        DummyFront->next = newNode;
        ++size;        
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        newNode->next = DummyBack;
        if (size > 0) {
            Node* current = DummyFront->next;
            for (int i = 0; i < size - 1; i++) {
                current = current->next;
            }
            current->next = newNode; 
        } 
        else {
            DummyFront->next = newNode;
        }
        ++size; 
    }

    bool remove(int index) {
        if (size < 1 || index >= size) return false; 
        Node* prev = DummyFront;
        Node* current = DummyFront->next; 

        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        current = prev->next;

        prev->next = current->next; 
        delete current; 
        --size; 

        return true; 
    }

    vector<int> getValues() {
        
        vector<int> v; 

        if (size == 0) return v; 
        Node* current = DummyFront->next; 

        v.push_back(current->val);
        for (int i = 0; i < size - 1; i++) {
            current = current->next;
            v.push_back(current->val);
        }
        return v;
    }
};
