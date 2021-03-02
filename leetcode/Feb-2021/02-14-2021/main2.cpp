/* You are given a string s consisting only of the characters '0' and '1'. In
 * one operation, you can change any '0' to '1' or vice versa.

 * The string is called alternating if no two adjacent characters are equal. For
 * example, the string "010" is alternating, while the string "0100" is not.

 * Return the minimum number of operations needed to make s alternating. */

class Solution {
 public:
  int minOperations(string s) {
    int evenPositionOnes = 0;
    int evenPositionZeroes = 0;
    int oddPositionOnes = 0;
    int oddPositionZeroes = 0;

    cout << s.size();

    for (int i = 0; i < s.size(); i++) {
      bool isOne = (s[i] == '1');
      if (i & 0x1) {
        if (isOne) {
          oddPositionOnes++;
        } else {
          oddPositionZeroes++;
        }
      } else {
        if (isOne) {
          evenPositionOnes++;
        } else {
          evenPositionZeroes++;
        }
      }
    }
    long int inPlaceZeroStarting = evenPositionZeroes + oddPositionOnes;
    long int inPlaceOneStarting = evenPositionOnes + oddPositionZeroes;
    return inPlaceZeroStarting > inPlaceOneStarting ? inPlaceOneStarting
                                                    : inPlaceZeroStarting;
  }
};