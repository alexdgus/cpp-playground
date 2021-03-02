#include <unordered_set>
#include <vector>
#include <iostream>

class Solution {
public:
    static bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> s;
        for(auto &i : nums) {
            if(s.count(i) != 0) {
                return true;
            } else {
                s.insert(i);
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> dupArray = {0, 1, 2, 5, 3, 4};
    std::cout << "Array contains duplicate: " << Solution::containsDuplicate(dupArray) << "\n";
    return 1;
}