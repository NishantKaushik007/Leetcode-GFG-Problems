class SeatManager {
    int seatAvailable;
    priority_queue<int,vector<int>,greater<int>>minHeap;
public:
    SeatManager(int n) {
        seatAvailable=1;
    }
    
    int reserve() {
        if(minHeap.empty())
        return seatAvailable++;
        else{
            int seat=minHeap.top();
            minHeap.pop();
            return seat;
        }
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */