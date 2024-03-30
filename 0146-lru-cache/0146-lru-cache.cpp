class LRUCache {
public:
    class node{
        public:
        int key,value;
        node* next,*prev;
        node(int k,int val)
        {
            key=k;
            value=val;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* newNode)
    {
        node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    
    void deleteNode(node* delNode)
    {
        node* delprev=delNode->prev;
        node* delnext=delNode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node* resNode=m[key];
            int res=resNode->value;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key]=head->next;
            return res;
        }
            return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* existingNode=m[key];
            m.erase(key);
            deleteNode(existingNode);
            m.erase(existingNode->key);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */