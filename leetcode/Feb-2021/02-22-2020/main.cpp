#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* Really slow brute force solution
class Solution {
public:
    bool findWord(string s, vector<string>& d) {
        for(int i = 0; i < d.size(); i++) {
            if(s == d[i]) {
                return true;
            }
        }
        return false;
    }

    string findLongestWord(string s, vector<string>& d) {
        string str = "";
        if(findWord(s, d)) {
            return s;
        } else if(s.size() > 0) {
            for(int i = 0; i < s.size(); i++) {
                string temp = s;
                temp = findLongestWord(temp.erase(i, 1), d);
                if(temp.size() > str.size() ||
                    (temp.size() == str.size() && temp < str)) {
                    str = temp;
                }
            }
        }
        return str;
    }
}; */

class Solution {
public:
    bool findWord(string s, string d) {
        int searchIndex = 0;
        int charsFound = 0;
        for(int i = 0; i < d.size(); i++) {
            for(int j = searchIndex; j < s.size(); j++) {
                if(s[j] == d[i]) {
                    charsFound++;
                    if(charsFound == d.size()) {
                        return true;
                    }
                    searchIndex = j + 1;
                    break;
                }
            }
        }
        return false;
    }

    string findLongestWord(string s, vector<string>& d) {
        string longestWord = "";
        for(int i = 0; i < d.size(); i++) {
            if(findWord(s, d[i])) {
                if(d[i].size() > longestWord.size() ||
                   (d[i].size() == longestWord.size() && d[i] < longestWord)) {
                    longestWord = d[i];
                }
            }
        }
        return longestWord;
    }
};

int main(int argc, char *argv[]) {
    Solution x;
    string s = "abpcplea";
    vector<string> d = {"ale","apple","monkey","plea"};
    std::cout << x.findLongestWord(s, d) << "\n";
}