/* Given a string s of '(' , ')' and lowercase English characters. */

/* Your task is to remove the minimum number of parentheses ( '(' or ')', in any
 * positions ) so that the resulting parentheses string is valid and return any
 * valid string. */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openCount = 0;
        int index = 0;
        while(index < s.size()) {
            if(s[index] == ')') {
                if(openCount == 0) {
                    s.erase(index, 1);
                    continue;
                } else {
                    openCount--;
                }
            } else if(s[index] == '(') {
                openCount++;
            }
            index++;
        }
        index = s.size() - 1;
        while(openCount > 0 && index >= 0) {
            if(s[index] == '(') {
                s.erase(index, 1);
                openCount--;
            }
            index--;
        }
        return s;
    }
};