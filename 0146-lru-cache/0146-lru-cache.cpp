class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {} 
    };

    map<int, Node*> mp; 
    Node* head;
    Node* tail;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); 
        tail = new Node(-1, -1); 
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* curr = mp[key];
        deleteNode(curr);            
        insertAfterHead(curr);       
        return curr->value;          
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->value = value;     
            deleteNode(node);        
            insertAfterHead(node);
        } else {
            if (mp.size() == capacity) {
                Node* node = tail->prev; 
                mp.erase(node->key);     
                deleteNode(node);        
                delete node;             
            }
            Node* newnode = new Node(key, value);
            mp[key] = newnode;                    
            insertAfterHead(newnode);             
        }
    }

    void deleteNode(Node* node) {
        Node* prevnode = node->prev;
        Node* afternode = node->next;
        prevnode->next = afternode;
        afternode->prev = prevnode;
    }

    void insertAfterHead(Node* node) {
        Node* curr = head->next;
        head->next = node;
        node->next = curr;
        node->prev = head;
        curr->prev = node;
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */