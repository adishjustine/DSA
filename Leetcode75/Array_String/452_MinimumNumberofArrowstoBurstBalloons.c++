class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort balloons by their end position (right boundary)
        // This greedy approach ensures we can burst maximum balloons with each arrow
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
      
        // Initialize arrow count
        int arrowCount = 0;
      
        // Track the position of the last arrow shot
        // Initialize to a very small value to ensure first balloon requires an arrow
        long long lastArrowPosition = -(1LL << 60);
      
        // Iterate through each balloon
        for (auto& balloon : points) {
            int balloonStart = balloon[0];
            int balloonEnd = balloon[1];
          
            // If current balloon's start is beyond the last arrow's position,
            // we need a new arrow
            if (balloonStart > lastArrowPosition) {
                arrowCount++;
                // Shoot the arrow at the end of current balloon
                // This maximizes the chance of hitting future balloons
                lastArrowPosition = balloonEnd;
            }
        }
      
        return arrowCount;
    }
};
