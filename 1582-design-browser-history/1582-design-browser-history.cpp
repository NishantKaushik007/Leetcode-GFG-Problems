class Deque{
    public:
    string str;
    Deque* next;
    Deque* prev;
    Deque(string str)
    {
        this->str=str;
        next=NULL;
        prev=NULL;
    }
};
class BrowserHistory {
private:
    Deque* head;
    Deque* curr;
public:
    BrowserHistory(string homepage) {
        head=new Deque(homepage);
        curr=head;
    }
    
    void visit(string url) {
        curr->next=new Deque(url);
        curr->next->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(curr!=head&&steps--)
        {
            curr=curr->prev;
        }
        return curr->str;
    }
    
    string forward(int steps) {
        while(curr->next!=NULL&&steps--)
        {
            curr=curr->next;
        }
        return curr->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */