class LRUCache {
private: 
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {};
    };

    Node headc{-1, -1};
    Node tailc{-1, -1};

    unordered_map<int, Node*> cache; 

    Node* head = &headc;
    Node* tail = &tailc;
    int capacity; 

    void unlink(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev; 

        node->next = nullptr;
        node->prev = nullptr; 
    }

    void insert_front(Node* node) {
        node->next = head->next; 
        head->next->prev = node;

        node->prev = head;
        head->next = node; 
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity; 

        //dummy nodes need to be intialzed linked
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            Node* node = cache[key];
            unlink(node);
            insert_front(node);
            return node->val;
        }

        return -1; 
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            Node* node = cache[key];
            node->val = value; 
            unlink(node);
            insert_front(node);
            return;
        }
        if (cache.size() >= capacity) {
            // remove LRU 
            Node* Last = tail->prev; 
            unlink(Last);
            cache.erase(Last->key);
            delete Last; 
        }

        // add node
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert_front(newNode);

    }
};
