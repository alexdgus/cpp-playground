/* Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.

 * Return the quotient after dividing dividend by divisor.

 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool oppositeSign = false;
        int quotient = 0;
        if(dividend == 0) {
            return 0;
        }
        if(dividend < 0 && divisor > 0 ||
           divisor < 0 && dividend > 0) {
            oppositeSign = true;
        }
        if(divisor == -2147483648) {
            if(dividend == -2147483648) {
                return 1;
            } else {
                return 0;
            }
        }
        if(dividend == -2147483648) {
            if(divisor == 1) {
                return -2147483648;
            } else if(divisor == -1) {
                return 2147483647;
            } else {
                quotient++;
                dividend += abs(divisor);
            }
        }
        dividend = abs(dividend);
        divisor = abs(divisor);

        while(dividend >= divisor) {
            int i = 0;
            while(dividend >> i >= divisor) {
                i++;
            }
            dividend -= divisor << i - 1;
            quotient += 1 << i - 1;
        }
        return oppositeSign ? -quotient : quotient;
    }
};