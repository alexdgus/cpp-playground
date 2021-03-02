/* Given a m * n matrix mat of ones (representing soldiers) and zeros
 * (representing civilians), return the indexes of the k weakest rows in the
 * matrix ordered from the weakest to the strongest. */

/* A row i is weaker than row j, if the number of soldiers in row i is less than
 * the number of soldiers in row j, or they have the same number of soldiers but
 * i is less than j. Soldiers are always stand in the frontier of a row, that
 * is, always ones may appear first and then zeros. */

class Solution {
public:
    int countSoldiers(vector<int> &row) {
        int count = 0;
        for(auto &i : row) {
            if(i == 1) {
                count++;
            }
        }
        return count;
    }

    int findMinIndex(vector<int> &counts, int maxSoldiers) {
        int minIndex = 0;
        for(int i = 0; i < counts.size(); i++) {
            if(counts[i] < counts[minIndex]) {
                minIndex = i;
            }
        }
        counts[minIndex] = maxSoldiers + 1;
        return minIndex;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> rowCounts;
        for(int i = 0; i < mat.size(); i++) {
            rowCounts.push_back(countSoldiers(mat[i]));
        }
        vector<int> kSmallest;
        for(int i = 0; i < k; i++) {
            kSmallest.push_back(findMinIndex(rowCounts, mat[0].size()));           
        }
        return kSmallest;
    }
};