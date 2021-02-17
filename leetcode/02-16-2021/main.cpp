/* Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string. */

/* Return a list of all possible strings we could create. You can return the
 * output in any order. */

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> perms;
        findPerms(S, 0, perms);
        return perms;
    }
    
    void findPerms(string s, int offset, vector<string> &perms) {
        int i;
        for(i = offset; i < s.size(); i++) {
            if(!(s[i] >= '0' && s[i] <= '9')) {
                break;
            }
        }
        if(i >= s.size()) {
            perms.push_back(s);
        } else {
            s[i] = toupper(s[i]);
            findPerms(s, i+1, perms);
            s[i] = tolower(s[i]);
            findPerms(s, i+1, perms);
        }
    }
};