class RecentCounter {
private:
    std::queue<int> timestamps;  // Queue to store timestamps of recent requests

public:
    /**
     * Constructor: Initializes an empty RecentCounter
     */
    RecentCounter() {
        // Queue is automatically initialized as empty
    }
  
    /**
     * Records a new request at timestamp t and returns the number of requests
     * that have happened in the past 3000 milliseconds (including the new request).
     * 
     * @param t - The timestamp of the current request in milliseconds
     * @return The number of requests in the time window [t-3000, t]
     */
    int ping(int t) {
        // Add the current timestamp to the queue
        timestamps.push(t);
      
        // Remove all timestamps that are outside the 3000ms window
        // Keep removing from front while timestamp is older than (t - 3000)
        while (!timestamps.empty() && timestamps.front() < t - 3000) {
            timestamps.pop();
        }
      
        // Return the count of requests within the valid time window
        return timestamps.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
