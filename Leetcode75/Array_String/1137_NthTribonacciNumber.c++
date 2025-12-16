class Solution {
public:
    int tribonacci(int n) {
        // Initialize the first three Tribonacci numbers
        // T0 = 0, T1 = 1, T2 = 1
        long long first = 0;
        long long second = 1;
        long long third = 1;
      
        // Iterate n times to calculate the nth Tribonacci number
        while (n--) {
            // Calculate the next Tribonacci number as sum of previous three
            long long next = first + second + third;
          
            // Shift the window: move each value one position forward
            first = second;
            second = third;
            third = next;
        }
      
        // After n iterations, 'first' contains the nth Tribonacci number
        return static_cast<int>(first);
    }
};