class Solution {
public:
    string predictPartyVictory(string senate) {
        int senateSize = senate.size();
      
        // Queue to store indices of Radiant senators
        queue<int> radiantQueue;
        // Queue to store indices of Dire senators
        queue<int> direQueue;
      
        // Initialize queues with initial positions of each party's senators
        for (int i = 0; i < senateSize; ++i) {
            if (senate[i] == 'R') {
                radiantQueue.push(i);
            } else {
                direQueue.push(i);
            }
        }
      
        // Simulate the voting process until one party has no senators left
        while (!radiantQueue.empty() && !direQueue.empty()) {
            // Get the front senator from each party
            int radiantIndex = radiantQueue.front();
            int direIndex = direQueue.front();
            radiantQueue.pop();
            direQueue.pop();
          
            // The senator with smaller index acts first and bans the opponent
            // The winner gets to vote again in the next round (add senateSize to maintain order)
            if (radiantIndex < direIndex) {
                // Radiant senator bans Dire senator and gets next turn
                radiantQueue.push(radiantIndex + senateSize);
            } else {
                // Dire senator bans Radiant senator and gets next turn
                direQueue.push(direIndex + senateSize);
            }
        }
      
        // Return the party name that still has senators
        return radiantQueue.empty() ? "Dire" : "Radiant";
    }
};