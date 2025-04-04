class LRUCache {
public:

    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key,int val)
        {
            this->key=key;
            this->val=val;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    int cap;
    unordered_map<int,Node*>mp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* temp)
    {
        temp->next=head->next;
        temp->prev=head;
        temp->next->prev=temp;
        head->next=temp;
    }

    void deleteNode(Node* temp)
    {
        Node* delNode=temp;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end())
        return mp[key]->val;
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* delNode=mp[key];
            deleteNode(mp[key]);
            mp.erase(delNode->key);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* temp=new Node(key,value);
        addNode(temp);
        mp[key]=temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */