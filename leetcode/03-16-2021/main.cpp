/* You are given an array prices where prices[i] is the price of a given stock
 * on the ith day, and an integer fee representing a transaction fee. */

/* Find the maximum profit you can achieve. You may complete as many
 * transactions as you like, but you need to pay the transaction fee for each
 * transaction. */
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int startingIndex = 0;
        int totalProfit = 0;
        while(startingIndex < prices.size() - 1) {
            int potentialBuyIndex = startingIndex;
            bool potentialBuyFound = false;
            for(int i = startingIndex; i < prices.size() - 1; i++) {
                startingIndex = i + 1;
                if(prices[i + 1] > prices[i]) {
                    potentialBuyIndex = i;
                    potentialBuyFound = true;
                    break;
                }
            }
            bool potentialSellFound = false;
            int potentialSellIndex = 0;
            int maxProfit = 0;
            if(potentialBuyFound) {
                for(int i = potentialBuyIndex + 1; i < prices.size(); i++) {
                    if(prices[i] - prices[potentialBuyIndex] > fee) {
                        potentialSellIndex = i;
                        potentialSellFound = true;
                        maxProfit = prices[i] - prices[potentialBuyIndex];
                        startingIndex = i + 1;
                        break;
                    } else if(prices[i] < prices[potentialBuyIndex]) {
                        startingIndex = i;
                        break;
                    }
                }
            }
            if(potentialSellFound) {
                for(int i = potentialSellIndex + 1; i< prices.size(); i++) {
                    if(prices[i] - prices[potentialBuyIndex] > maxProfit) {
                        maxProfit = prices[i] - prices[potentialBuyIndex];
                        startingIndex = i + 1;
                        potentialSellIndex = i;
                    } else if(prices[i] - prices[potentialBuyIndex] < maxProfit - fee) {
                        break;
                    }
                }
            }
            cout << "si" << startingIndex << "\n";
            if(maxProfit) {
                totalProfit += maxProfit - fee;
            }
        }
        return totalProfit;
    }
};