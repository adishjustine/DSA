class Solution {
private:
    string helper(int& i, string& s) {
        string res;
        int k = 0;

        while (i < s.size()) {
            char c = s[i];

            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                i++;
                string subRes = helper(i, s);
                while (k-- > 0) res += subRes;
                k = 0;
            } else if (c == ']') {
                return res;
            } else {
                res += c;
            }

            i++;
        }

        return res;
    }

public:
    string decodeString(string s) {
        int i = 0;
        return helper(i, s);
    }
};