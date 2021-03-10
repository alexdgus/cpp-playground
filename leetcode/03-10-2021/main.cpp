/* Given an integer, convert it to a roman numeral. */

/*Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000 */

class Solution {
public:
    void addDigits(int& num, string& s, char digit, int digitVal) {
        int digits = num / digitVal;
        num %=digitVal;
        for(; digits > 0; digits--) {
            s.push_back(digit);
        }
    }

    void addSubtractionDigit(int& num, string& s, char digit, char digit2, int checkVal) {
        if(num >= checkVal) {
            s.push_back(digit);
            s.push_back(digit2);
            num -= checkVal;
        }
    }

    string intToRoman(int num) {
        string s;
        addDigits(num, s, 'M', 1000);
        addSubtractionDigit(num, s, 'C', 'M', 900);
        addDigits(num, s, 'D', 500);
        addSubtractionDigit(num, s, 'C', 'D', 400);
        addDigits(num, s, 'C', 100);
        addSubtractionDigit(num, s, 'X', 'C', 90);
        addDigits(num, s, 'L', 50);
        addSubtractionDigit(num, s, 'X', 'L', 40);
        addDigits(num, s, 'X', 10);
        addSubtractionDigit(num, s, 'I', 'X', 9);
        addDigits(num, s, 'V', 5);
        addSubtractionDigit(num, s, 'I', 'V', 4);
        addDigits(num, s, 'I', 1);
        return s;
    }
};