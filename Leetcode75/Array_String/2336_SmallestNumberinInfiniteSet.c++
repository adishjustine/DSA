class SmallestInfiniteSet {
public:
    // Constructor: Initialize the set with integers from 1 to 1000
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) {
            available_numbers.insert(i);
        }
    }
  
    // Remove and return the smallest integer from the infinite set
    int popSmallest() {
        // Get the smallest element (first element in ordered set)
        int smallest = *available_numbers.begin();
      
        // Remove the smallest element from the set
        available_numbers.erase(available_numbers.begin());
      
        return smallest;
    }
  
    // Add a number back to the infinite set if not already present
    void addBack(int num) {
        // Insert the number (set automatically handles duplicates)
        available_numbers.insert(num);
    }
  
private:
    // Ordered set to maintain available numbers in sorted order
    std::set<int> available_numbers;
};
