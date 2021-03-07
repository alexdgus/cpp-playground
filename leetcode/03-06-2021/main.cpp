/* A valid encoding of an array of words is any reference string s and array of
 * indices indices such that:
   - words.length == indices.length
   - The reference string s ends with the '#' character.
   - For each index indices[i], the substring of s starting from indices[i]
     and up to (but not including) the next '#' character is equal to words[i].

/* Given an array of words, return the length of the shortest reference string s
 * possible of any valid encoding of words. */

/* A very slow and ugly solution */
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        string s;
        vector<string> uwords;
        for(auto& word : words) {
            bool found = false;
            int wi = word.size() - 1;
            int ui = 0;
            for(int i = 0; i < uwords.size(); i++) {
                int wi = word.size() - 1;
                int ui = uwords[i].size() - 1;
                while(ui > 0 && wi > 0) {
                    if(word[wi] == uwords[i][ui]) {
                        ui--;
                        wi--;
                    } else {
                        break;
                    }
                }
                if(ui == 0 || wi == 0) {
                    if(word[wi] == uwords[i][ui]) {
                        found = true;
                        if(ui < wi) {
                            uwords.erase(uwords.begin()+i);
                            uwords.push_back(word);
                        }
                    }
                    break;
                }
            }
            if(!found) {
                uwords.push_back(word);
            }
        }
        
        // Find the total length of the encoding
        int total = 0;
        for(auto& uword : uwords) {
            total += uword.size() + 1;
        }
        return total;
    }
};