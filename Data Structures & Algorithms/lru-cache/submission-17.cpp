class LRUCache {
private:

    struct Node {
        int key; 
        int val; 
        Node* left; 
        Node* right; 

        Node(int val) : key(0), val(val), left(nullptr), right(nullptr) {}
        Node(int k, int v) : key(k), val(v), left(nullptr), right(nullptr) {}
        Node() : key(0), val(0), left(nullptr), right(nullptr) {}
    };

    unordered_map<int, Node*> mp; 
    int capacity; 
    
    Node* dummy_left;
    Node* dummy_right;

    void link_remove(Node* n) {
        n->left->right = n->right;
        n->right->left = n->left; 
    }

    void link_front(Node* n) {
        dummy_left->right->left = n; 
        n->right = dummy_left->right; 

        dummy_left->right = n;
        n->left = dummy_left; 
    }


public:
    LRUCache(int capacity) {
        this->capacity = capacity; 
        Node* dummy_left = new Node(0);
        Node* dummy_right = new Node(0);
        this->dummy_left = dummy_left; 
        this->dummy_right = dummy_right; 

        dummy_left->right = dummy_right;
        dummy_right->left = dummy_left; 


    }
    
    int get(int key) {
        if (mp.contains(key)) {
            Node* n = mp[key];
            link_remove(n);
            link_front(n);

            return mp[key]->val;
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            mp[key]->val = value; 
            Node* n = mp[key];
            link_remove(n);
            link_front(n);
            return; 
        }

        // capacity? 
        if (mp.size() >= capacity) {
            // remove + insert
            Node* last = dummy_right->left; 

            mp.erase(last->key);
            link_remove(last);
            delete last; 

            // make new
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            link_front(newNode);
            return;
        }

        // new insert 
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        link_front(newNode);
        return;


    }
};













