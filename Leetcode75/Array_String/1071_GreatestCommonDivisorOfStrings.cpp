class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If concatenating str1+str2 doesn't equal str2+str1,
        // then there's no common divisor string pattern
        if (str1 + str2 != str2 + str1) {
            return "";
        }
      
        // Find the GCD of the two string lengths
        // This will be the length of the greatest common divisor string
        int gcd_length = __gcd(str1.size(), str2.size());
      
        // Return the substring from start to the GCD length
        // This is the greatest common divisor string
        return str1.substr(0, gcd_length);
    }
};