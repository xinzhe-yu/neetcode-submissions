class LRUCache {
private:
    int capacity; 
    int size; 

    struct Node {
        int key; 
        int val; 
        Node* next; 
        Node* prev; 

        Node() : val(0), key(0), next(nullptr), prev(nullptr) {};
        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {};
    };
    unordered_map<int, Node*> cache; 

    // Dummy nodes
    Node HEAD{-1, -1};
    Node TAIL{-1, -1};


    // Move node to most recent used (Left side)
    void MRU(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev; 

        node->next = HEAD.next;
        HEAD.next->prev = node;

        HEAD.next = node; 
        node->prev = &HEAD; 
    }

    void left_insert(Node* node) {
        HEAD.next->prev = node;
        node->next = HEAD.next;

        HEAD.next = node;
        node->prev = &HEAD;  
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity; 
        size = 0; 

        HEAD.next = &TAIL;
        TAIL.prev = &HEAD;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            MRU(cache[key]);
            return cache[key]->val;
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            cache[key]->val = value;
            MRU(cache[key]);
            return; 
        }
        if (size == capacity) { // Case 1: Compulsory Miss
            Node* Last = TAIL.prev;  //remove Last
            int last_key = Last->key;
            cache.erase(last_key);

            Last->prev->next = &TAIL; //clean up
            TAIL.prev = Last->prev; 

            delete Last; 
            size--; 
        }

        Node* newNode = new Node(key, value);  // Add a new node
        cache[key] = newNode; // Invariance: cache.size() > capacity
        left_insert(newNode);
        size++;
    }
};
