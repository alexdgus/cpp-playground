/* A sequence of numbers is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same. */

/* The function should return the number of arithmetic slices in the array A. */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int startIndex = 0;
        int endIndex = 1;
        int totalSlices = 0;
        while(endIndex < A.size()) {
            int sequenceLen = 2;
            int diff = A[endIndex] - A[startIndex];
            endIndex++;
            while(endIndex < A.size()) {
                int nextDiff = A[endIndex] - A[endIndex - 1];
                if(nextDiff == diff) {
                    sequenceLen++;
                } else {
                    break;
                }
                endIndex++;
            }
            if(sequenceLen > 2) {
                for(int i = 1; i <= sequenceLen - 2; i++) {
                    totalSlices += i;
                }
            }
            startIndex = endIndex - 1;
        }
        return totalSlices;
    }
};