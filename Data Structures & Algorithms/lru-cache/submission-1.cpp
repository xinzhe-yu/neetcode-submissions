class LRUCache {
private: 
    struct Node {
            Node* left = nullptr;
            Node* right = nullptr;
            int key;
            int val;
            

            Node(int k, int v) : key(k), val(v) {}
        };

    int capacity;
    std::unordered_map<int, Node*> s;
    int usage; 
    Node* LRU = nullptr;
    Node* MRU = nullptr;

    void MRU_set(Node* n) {

        // Already MRU 
        if (n == MRU) return;

        if (n == LRU) {
            n->left->right = nullptr;
            LRU = n->left;
            n->left = nullptr;
            n->right = MRU;
            MRU->left = n;
            MRU = n;
        }

        // Middle case 
        else if (n->left && n->right) {

            n->left->right = n->right;
            n->right->left = n->left;

            n->left = nullptr; 
            n->right = nullptr;

            n->right = MRU;
            MRU->left = n;
            MRU = n;
        }
    }

    void New_node(int key, int value) {
        Node* cacheblock = new Node(key, value); // Returns a Node*
        s[key] = cacheblock;
            if (MRU) {
                cacheblock->right = MRU;
                MRU->left = cacheblock; 
            }
            MRU = cacheblock;
            usage++;
        if (!LRU) LRU = cacheblock;
    }


public:
    LRUCache(int capacity) {
    this->capacity = capacity;
    usage = 0; 
    }

    int get(int key) {
        if (usage == 0) return -1;
        auto it = s.find(key);
        if (it != s.end()) {
            MRU_set(it->second);
            return MRU->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = s.find(key);
        if (it != s.end()) {
            //it->second->val = value;
            MRU_set(it->second);
            it->second->val = value;
            return; 
        } 
        
        if (usage < capacity) {
            New_node(key, value);
        } 
        else {            
            Node* prev = nullptr;
            if (LRU->left) {
                prev = LRU->left;
            }
            s.erase(LRU->key);
            delete LRU;
            usage--;
            
            if (prev) {
                LRU = prev; 
                prev->right = nullptr; 
            } 
            else {
                LRU = nullptr;
                MRU = nullptr; 
            }

            New_node(key, value);
        }
    }


};


