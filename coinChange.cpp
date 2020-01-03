322. Coin Change
Medium

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coin_size = coins.size();
        vector<vector<int>> dp = vector(coin_size, vector(amount+1,INT_MAX));
        
        // given the coin[0] can we make change between [0..amount]
        
        for (int i = 0; i <= amount; i++) {
            dp[0][i] = (i % coins[0] == 0) ? i/coins[0] : INT_MAX;
        }
        
        for (int i = 0; i < coin_size; i++) {
            dp[i][0] = 0;
        }
         
        for (int cash = 1; cash <= amount; cash++) {
            for (int i = 1; i < coin_size; i++) {
                dp[i][cash] = dp[i-1][cash];
                if (cash - coins[i] >= 0) {
                    if (dp[i][cash-coins[i]] == INT_MAX) continue;
                    dp[i][cash] = min(dp[i][cash],(dp[i][cash-coins[i]])+1);
                }
            }
        }
        
        return (dp[coin_size-1][amount] == INT_MAX) ? -1 : dp[coin_size-1][amount];
    }
};
