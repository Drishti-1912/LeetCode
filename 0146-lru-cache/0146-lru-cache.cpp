struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // Hash map to store key-node pairs
    Node* head; // Dummy head of the doubly linked list
    Node* tail; // Dummy tail of the doubly linked list

    // Helper function to add a node to the head of the list
    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // Helper function to remove a node from the list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper function to move a node to the head of the list
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    // Helper function to remove the tail node (LRU node)
    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }   
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); // Dummy head
        tail = new Node(-1, -1); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToHead(node); // Move the accessed node to the head
            return node->value;
        }
        return -1; // Key not found
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value; // Update the value
            moveToHead(node); // Move the updated node to the head
        } else {
            if (cache.size() >= capacity) {
                Node* tailNode = removeTail(); // Remove the LRU node
                cache.erase(tailNode->key); // Remove the key from the hash map
                delete tailNode; // Free memory
            }
            Node* newNode = new Node(key, value); // Create a new node
            addToHead(newNode); // Add the new node to the head
            cache[key] = newNode; // Add the key-node pair to the hash map
        }
    }
        ~LRUCache() {
        // Clean up the doubly linked list
        Node* current = head->next;
        while (current != tail) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        delete tail;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */