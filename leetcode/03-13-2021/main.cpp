/* Given an array of unique integers, arr, where each integer arr[i] is strictly
 * greater than 1. */

/* We make a binary tree using these integers, and each number may be used for
 * any number of times. Each non-leaf node's value should be equal to the
 * product of the values of its children. */

/* Return the number of binary trees we can make. The answer may be too large so
 * return the answer modulo 109 + 7. */

class Solution {
public:
    bool factors(int num, int x, int y) {
        if(num / y == x && num % y == 0) {
            return true;
        }
        return false;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<unsigned long> trees(arr.size(), 1);
        long count = 0;
        for(int i = 0; i < arr.size(); i++) {
            double lim2 = arr[i] / 2;
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] != 0) {
                    continue;
                }
                if(arr[j] > lim2) {
                    break;
                }
                for(int k = 0; k < i; k++) {
                    if(arr[k] > lim2) {
                        break;
                    }
                    if(factors(arr[i], arr[j], arr[k])) {
                        trees[i] += trees[j] * trees[k];
                    }
                }
            }
            count += trees[i];
            if(count > 1000000007) {
                count %= 1000000007;
            }
        }
        return count;
    }
};