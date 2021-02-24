#include <vector>
#include <iostream>

using namespace std;

/* Slow iterative solution that does some minimal column optimization
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int maxColumn = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < maxColumn; j++) {
                if(matrix[i][j] == target) {
                    return true;
                } else if(matrix[i][j] > target) {
                    maxColumn = min(maxColumn, j);
                    break;
                }
            }
        }
        return false;
    }
};
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int c = matrix[0].size() - 1;
        int r = 0;
        while(r < matrix.size() && c >= 0) {
            if(matrix[r][c] == target) {
                return true;
            } else if(matrix[r][c] < target) {
                r++;
            } else {
                c--;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
std::vector<std::vector<int>> matrix =
{{ 1,  2,  3,  4,  5,  6,  7,  8,  9},
 {10, 11, 12, 13, 14, 15, 16, 17, 18},
 {19, 20, 21, 22, 23, 24, 25, 26, 27},
 {28, 29, 30, 31, 32, 33, 34, 35, 36}};

int target = 35;

Solution s;
s.searchMatrix(matrix, target);
}