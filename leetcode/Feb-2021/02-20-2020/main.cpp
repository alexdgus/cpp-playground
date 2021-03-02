/* Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Find the value of the given roman numeral string */

//SOLUTION 1. This one isn't very good
class Solution {
public:
    int romanToInt(string s) {map<char, int> numerals = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        
        int cachedVal = 0;
        int cachedCount = 0;
        int total = 0;
        for(int i = 0; i < s.size(); i++) {
            int curVal = numerals[s[i]];
            if(curVal == cachedVal || cachedVal == 0) {
                cachedVal = curVal;
                cachedCount++;
            } else if(curVal < cachedVal) {
                total += cachedVal * cachedCount;
                cachedVal = curVal;
                cachedCount = 1;
            } else {
                total += curVal - (cachedVal * cachedCount);
                cachedVal = 0;
                cachedCount = 0;
            }
        }
        total += cachedVal * cachedCount;
        return total;
    }
};

//SOLUTION 2. This one is much faster
class Solution {
public:
    int numeralToInt(char c) {
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }

    int romanToInt(string s) {
        int total = 0;
        int prevVal = 0;
        for(int i = 0; i < s.size(); i++) {
            int curVal = numeralToInt(s[i]);
            if(prevVal != 0 && prevVal < curVal) {
                total -= 2 * prevVal;
            }
            total += curVal;
            prevVal = curVal;
        }
        return total;
    }
};
