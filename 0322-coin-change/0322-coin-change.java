class Solution {
    public int coinChange(int[] coins, int amount) {
        int[][] a = new int[coins.length + 1][amount + 1];
        for (int i = 0; i <= coins.length; i++) {
            a[i][0] = 0;
        }
        for (int j = 1; j <= amount; j++) {
            a[0][j] = Integer.MAX_VALUE;
        }
        for (int i = 1; i <= coins.length; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    int withoutCoin = a[i - 1][j];
                    int withCoin = (a[i][j - coins[i - 1]] == Integer.MAX_VALUE) ? Integer.MAX_VALUE : 1 + a[i][j - coins[i - 1]];
                    a[i][j] = Math.min(withoutCoin, withCoin);
                } else {
                    a[i][j] = a[i - 1][j];
                }
            }
        }
        System.gc();
        return a[coins.length][amount] == Integer.MAX_VALUE ? -1 : a[coins.length][amount];
    }
}

