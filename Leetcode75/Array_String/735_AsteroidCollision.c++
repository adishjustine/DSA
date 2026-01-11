class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
      
        for (int asteroid : asteroids) {
            // If asteroid is moving right, always add it to stack
            if (asteroid > 0) {
                stack.push_back(asteroid);
            } 
            // If asteroid is moving left, handle potential collisions
            else {
                // Keep destroying smaller right-moving asteroids
                while (!stack.empty() && stack.back() > 0 && stack.back() < -asteroid) {
                    stack.pop_back();
                }
              
                // Check if current left-moving asteroid collides with equal-sized right-moving asteroid
                if (!stack.empty() && stack.back() == -asteroid) {
                    stack.pop_back();  // Both asteroids destroy each other
                } 
                // Add left-moving asteroid if no collision or only left-moving asteroids in stack
                else if (stack.empty() || stack.back() < 0) {
                    stack.push_back(asteroid);
                }
                // If stack.back() > -asteroid, the right-moving asteroid survives (do nothing)
            }
        }
      
        return stack;
    }
};