class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
            Node(int _key,int _val){
                key = _key;
                val = _val;
            }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    map<int,Node*> mpp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode){
        Node* afterHead = head->next;
        head->next= newNode;
        newNode->prev = head;
        newNode->next= afterHead;
        afterHead->prev = newNode;
    }

    void deleteNode(Node* delnode){
        Node* prevNode = delnode->prev;
        Node* nextNode = delnode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        Node* address = mpp[key];
        int val = address->val;
        deleteNode(address);
        Node* newNode = new Node(key,val);
        mpp.erase(key);
        mpp[key] = newNode;
        addNode(newNode);
        return val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* address = mpp[key];
            mpp.erase(key);
            deleteNode(address);
            Node* newNode = new Node(key,value);
            mpp[key] = newNode;
            addNode(newNode);
        }else{
            if(mpp.size()<cap){
                Node* newNode = new Node(key,value);
                mpp[key] = newNode;
                addNode(newNode);
            }else{
                mpp.erase(tail->prev->key);
                deleteNode(tail->prev);
                Node* newNode = new Node(key,value);
                mpp[key] = newNode;
                addNode(newNode);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */