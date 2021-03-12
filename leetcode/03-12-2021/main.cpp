/* Given a binary string s and an integer k. */

/* Return True if every binary code of length k is a substring of s. Otherwise,
 * return False. */

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> subStrs(pow(2, k), false);
        for(int i = 0; i + k <= s.size(); i++) {
            subStrs[stoi(s.substr(i, k), nullptr, 2)] = true;
        }
        for(const auto& x : subStrs) {
            if(!x) { return false; }
        }
        return true;
    }
};