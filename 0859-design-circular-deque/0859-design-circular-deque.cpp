class MyCircularDeque {
    vector<int>arr;
    int size;
    int front;
    int rear;
    int limit;
public:
    MyCircularDeque(int k) {
        size=0;
        front=0;
        rear=k-1;
        limit=k;
        arr.resize(k);
    }
    
    bool insertFront(int value) {
        if(size==limit)
        return false;
        front=(front-1+limit)%limit;
        arr[front]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==limit)
        return false;
        rear=(rear+1)%limit;
        arr[rear]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0)
        return false;
        front=(front+1)%limit;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0)
        return false;
        rear=(rear-1+limit)%limit;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0)
        return -1;
        return arr[front];
    }
    
    int getRear() {
        if(size==0)
        return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==limit;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */