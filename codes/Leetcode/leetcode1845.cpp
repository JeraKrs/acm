class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            seat.push(i);
        }
    }
    
    int reserve() {
        int t = seat.top();
        seat.pop();
        return t;
    }
    
    void unreserve(int seatNumber) {
        seat.push(seatNumber);
    }
    std::priority_queue<int, std::vector<int>, std::greater<int> > seat;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
