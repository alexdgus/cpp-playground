/* Given a balanced parentheses string S, compute the score of the string based on the following rule:

1. () has score 1
2. AB has score A + B, where A and B are balanced parentheses strings.
3. (A) has score 2 * A, where A is a balanced parentheses string. */

/* A fairly inefficient recursive solution */
class Solution {
public:
    int scoreOfParentheses(string S) {
        if(S == "()") {
            return 1;
        } else {
            int chunk1 = 0;
            int chunk2 = 0;
            int open = 0;
            for(int i = 0; i < S.size(); i++) {
                if(S[i] == '(') {
                    open++;
                } else {
                    open--;
                }
                if(open == 0) {
                    if(i < S.size() - 1) {
                        chunk1 = scoreOfParentheses(S.substr(i+1, S.size() - 1));
                    }
                    if(i == 1) {
                        return chunk1 + 1;
                    }
                    chunk2 = 2 * scoreOfParentheses(S.substr(1, i - 1));
                    break;
                }
            }
            return chunk1 + chunk2;
        }
    }
};