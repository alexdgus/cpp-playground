/* Given two strings s and t , write a function to determine if t is an anagram
 * of s. */
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }

    std::array<int, 26> alphabet = {};

    for (int i = 0; i < s.size(); i++) {
      alphabet[s[i] - 97]++;
    }
    for (int i = 0; i < t.size(); i++) {
      alphabet[t[i] - 97]--;
    }
    for (int i = 0; i < alphabet.size(); i++) {
      if (alphabet[i] != 0) {
        return false;
      }
    }
    return true;
  }
};