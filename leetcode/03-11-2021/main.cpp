/* You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1. */

/* You may assume that you have an infinite number of each kind of coin. */

class Solution {
public:
    int findLeast(vector<int>& coins, vector<int>& store, int amount) {
        if(amount == 0) {
            store[amount] = 0;
            return 0;
        }
        if(store[amount] == -2) {
            store[amount] = INT_MAX;
            bool match = false;
            for(auto& coin : coins) {
                if(coin > amount) {
                    continue;
                } else {
                    int coinCount = findLeast(coins, store, amount - coin);
                    if(coinCount != -1) {
                        store[amount] = min(store[amount], coinCount + 1);
                        match = true;
                        if(store[amount] == 1) {
                            break;
                        }
                    }
                }
            }
            if(!match) {
                store[amount] = -1;
            }
        }
        return store[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> store(amount+1, -2);
        return findLeast(coins, store, amount);
    }
};