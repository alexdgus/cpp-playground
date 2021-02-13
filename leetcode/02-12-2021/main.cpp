/* Given a non-negative integer num, return the number of steps to reduce it to
 * zero. If the current number is even, you have to divide it by 2, otherwise,
 * you have to subtract 1 from it. */

class Solution {
 public:
  int numberOfSteps(int num) {
    int steps = 0;
    while (num != 0) {
      if (num & 0x01) {
        num -= 1;
        steps++;
      }
      if (num != 0) {
        num = num >> 1;
        steps++;
      }
    }
    return steps;
  }
};