/* Given two sequences pushed and popped with distinct values, return true if
 * and only if this could have been the result of a sequence of push and pop
 * operations on an initially empty stack. */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> s;
        int poppedIdx = 0;
        for(int i = 0; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while(s.size() && popped[poppedIdx] == s.top()) {
                poppedIdx++;
                s.pop();
            }
        }
        return (poppedIdx == popped.size());
    }
};